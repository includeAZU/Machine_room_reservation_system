#pragma once
#include <iostream >
using namespace std;
//身份抽象基类
class identity
{
public:
	//操作菜单   纯虚函数
	virtual void open_menu() = 0;
	//用户名

    string name;
	//密码
	string  password;

};