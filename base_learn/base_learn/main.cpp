// base_learn.cpp: 定义应用程序的入口点。
//


#include <iostream>
#include "log.h"


using namespace std;

sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

int main()
{
	cout << "Hello CMake." << endl;
	SYLAR_LOG_INFO(g_logger) << "mylog";
	cout << "Hello CMake." << endl;
	return 0;
}
