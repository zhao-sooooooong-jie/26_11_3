#include<iostream>
#include<ctime>
#include<fstream>

int main()
{
    time_t now = time(0);

    tm* t = localtime(&now);

    char timeStr[80];

    strftime(timeStr,sizeof(timeStr),"%Y-%m-%d %H:%M:%S",t);
    
    std::ofstream logFile;
    logFile.open("app.log", std::ios::app);

    if(logFile.is_open()){
        logFile << "["<< timeStr << "]start !" <<std::endl;

        logFile.close();
        std::cout <<"日志写入成功！" << std::endl;
    }
    else{
        std::cout <<"日志写入失败！" << std::endl;
    }
}