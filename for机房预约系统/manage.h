#pragma once
#include <iostream >
using namespace std;
#include "identity.h"
#include <string >
#include <fstream >
#include "global_file.h"
#include <vector >
#include "student.h"
#include "teacher.h"
#include <algorithm >
#include "computer_room.h"

class manage :public identity
{
public:
	manage();//默认构造

	manage(string name, string password);//	有参构造

	virtual void open_menu();

	//添加账号
	void add_person();
	//查看账号
	void show_person();
	//查看机房信息
	void show_computer_room();
	//清空预约记录
	void clean_order();
	//初始化学生,老师容器
	void init_vector();
	//检测添加账号是否重复(编号,类型)

	bool cheak_repeat(int id,int type);
	//学生容器
	vector <student> student_vector;

	//老师容器 
	vector <teacher> teacher_vector;
	//机房信息
	vector <computer_room> computer_room_vector;

};