#include<iostream>
#include<ctime>

int main()
{
    time_t now = time(0);

    tm* t = localtime(&now);

    char timeStr[80];

    strftime(timeStr,sizeof(timeStr),"%Y-%m-%d %H:%M:%S",t);
    
    std::cout<<"当前时间:"<<timeStr<<std::endl;

    std::cout<<"今年是："<<t->tm_year + 1900 << "年" << std::endl;
    std::cout<<"本月是："<<t->tm_mon + 1 << "月" << std::endl;

    return 0;
}

