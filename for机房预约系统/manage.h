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
	manage();//Ĭ�Ϲ���

	manage(string name, string password);//	�вι���

	virtual void open_menu();

	//����˺�
	void add_person();
	//�鿴�˺�
	void show_person();
	//�鿴������Ϣ
	void show_computer_room();
	//���ԤԼ��¼
	void clean_order();
	//��ʼ��ѧ��,��ʦ����
	void init_vector();
	//�������˺��Ƿ��ظ�(���,����)

	bool cheak_repeat(int id,int type);
	//ѧ������
	vector <student> student_vector;

	//��ʦ���� 
	vector <teacher> teacher_vector;
	//������Ϣ
	vector <computer_room> computer_room_vector;

};