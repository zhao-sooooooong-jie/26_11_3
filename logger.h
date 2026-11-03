#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    
    void log(const char* level,const char*file,int line,const std::string&msg)
    {
        //1.获取时间
        time_t now = time(0);
        tm* t = localtime(&now);
        char timeStr[80];
        strftime(timeStr,sizeof(timeStr),"%Y-%m-%d %H:%M:%S",t);

        //2.拼装最终格式：时间，级别，文件名，行号，日志信息
        std::ostringstream oss;
        oss << "[" << timeStr << "] [" << level << "] [" << file << ":" << line << "] " << msg;

        //3.写入日志文件
        std::ofstream fileStream("app.log", std::ios::app);
        if(fileStream.is_open()){
            fileStream << oss.str() << std::endl;
            fileStream.close();
        } else {
            std::cerr << "日志写入失败！" << std::endl;
        }

        //4.输出到控制台
        std::cout << oss.str() << std::endl;
    }
    
    private:
    Logger() {}//私有化构造函数
};

//宏定义，方便使用
#define LOG_DEBUG(...) do{\
    std::ostringstream oss;\
    oss << __VA_ARGS__;\
    Logger::getInstance().log("DEBUG",__FILE__,__LINE__,oss.str());\
}while(0)

#define LOG_INFO(...) do{\
    std::ostringstream oss;\
    oss << __VA_ARGS__;\
    Logger::getInstance().log("INFO",__FILE__,__LINE__,oss.str());\
}while(0)

#define LOG_ERROR(...) do{\
    std::ostringstream oss;\
    oss << __VA_ARGS__;\
    Logger::getInstance().log("ERROR",__FILE__,__LINE__,oss.str());\
}while(0)