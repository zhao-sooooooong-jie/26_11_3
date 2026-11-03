#include"logger.h"

int main()
{
    int userld = 404; // Example user ID
    std::string action = "登录系统"; // Example action
    double amount = 123.45; // Example amount

    //像用printf/cout一样使用日志宏
    LOG_INFO("系统启动成功！");

    LOG_INFO("用户ID: " << userld << " 执行了操作: " << action);

    LOG_DEBUG("当前用户总额为: " << amount);

    bool isError = true; // Example error condition
    if(isError){
        LOG_ERROR("发生了一个错误");
    }
    else{
        LOG_INFO("操作成功完成");
    }

    return 0;
}