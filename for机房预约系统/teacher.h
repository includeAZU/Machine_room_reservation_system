#pragma once
#include <iostream >
using namespace std;
#include "identity.h"
#include <vector>
#include "computer_room.h"
#include <fstream>
#include"global_file.h"
#include"order_file.h"
class teacher :public identity
{
public:
	teacher();//默认构造

	teacher(int id, string name, string password);//有参构造

	//菜单界面
	virtual void open_menu();

	//显示所有预约
	void show_all_order();

	//审核预约
	void valid_order();

	//老师编号
	int teacher_id;
	



};