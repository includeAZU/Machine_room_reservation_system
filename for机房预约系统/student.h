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
	student();//Ĭ�Ϲ���
	 
	student(int id, string name, string password);//�вι���

	virtual void open_menu();//�ع�ѧ���Ӳ˵�


	void apply_order();//����ԤԼ

	void show_my_order();//��ʾ����ԤԼ

	void show_all_order();//��ʾ����ԤԼ

	void cancel_order();//ȡ��ԤԼ

	int student_id;//ѧ��ѧ��

	vector <computer_room> computer_room_vector;










};