#pragma once
#include <iostream >
using namespace std;
#include "identity.h"
#include <vector>
#include "computer_room.h"
#include <fstream>
#include"global_file.h"
#include"order_file.h"
class student :public identity
{
public:
	student();//默认构造
	 
	student(int id, string name, string password);//有参构造

	virtual void open_menu();//重构学生子菜单


	void apply_order();//申请预约

	void show_my_order();//显示自身预约

	void show_all_order();//显示所有预约

	void cancel_order();//取消预约

	int student_id;//学生学号

	vector <computer_room> computer_room_vector;










};