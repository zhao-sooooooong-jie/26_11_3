#include<iostream>
#include<ctime>
#include<fstream>
#include<sstream>

int main()
{
    time_t now = time(0);

    tm* t = localtime(&now);

    char timeStr[80];

    strftime(timeStr,sizeof(timeStr),"%Y-%m-%d %H:%M:%S",t);
    
    std::ostringstream oss;
    int userId = 404; // Example user ID
    std::string action = "登录系统"; // Example action

    oss << "[" << timeStr << "] 用户ID: " << userId << " 执行了操作: " << action;
    std::string finalLog = oss.str();

    std::ofstream file("system.log", std::ios::app);
    if(file.is_open()){
        file << finalLog << std::endl;

        file.close();
        std::cout <<"日志" << std::endl;
    }
    return 0;
}