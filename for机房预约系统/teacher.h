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
	teacher();//Ĭ�Ϲ���

	teacher(int id, string name, string password);//�вι���

	//�˵�����
	virtual void open_menu();

	//��ʾ����ԤԼ
	void show_all_order();

	//���ԤԼ
	void valid_order();

	//��ʦ���
	int teacher_id;
	



};