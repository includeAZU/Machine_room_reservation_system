#include "manage.h"
#include "global_file.h"
manage::manage(string name, string password)//	�вι���
{
	this->name = name;
	this->password = password;
	this->init_vector();
	ifstream ifs;
	ifs.open(computer_txt, ios::in);
	computer_room com;
	while (ifs >> com.computer_room_id && ifs >> com.computer_room_max_size)
	{
		computer_room_vector.push_back(com);

	}
	ifs.close();


}

void manage::open_menu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void manage::add_person()
{
	cout << "����������˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string file_name;
	string tip;
	string error_tip;
	fstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		file_name = student_txt;
		tip = "������ѧ�ţ�";
		error_tip = "ѧ���ظ�������������";
	}
	else
	{
		file_name = teacher_txt;
		tip = "������ְ����ţ�";
		error_tip = "ְ�����ظ�������������";
	}
	ofs.open(file_name, ios::out|ios::app);
	int id; //ѧ�� /ְ����
	string name; //����
	string pwd; //����
	cout << tip << endl;
	cin >> id;
	while (1)
	{
		bool ret = cheak_repeat(id, select);
		if (ret)
		{
			cout << error_tip << endl;
		}
		else 
		{
			break;
		}

	}
	cout << "������������ " << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << "  " << name << "  " << pwd << "  " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->init_vector();

}
//�鿴�˺�
void print_student(student &s)
{
	cout << "ѧ�ţ� " << s.student_id<< " ������ " << s.name << " ���룺" << s.password << endl;

}
void print_teacher(teacher& s)
{
	cout << "ѧ�ţ� " << s.teacher_id << " ������ " << s.name << " ���룺" << s.password << endl;

}
void manage::show_person()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0; //�����û�ѡ��
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(student_vector.begin(), student_vector.end(), print_student);
	}
	if (select == 2)
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(teacher_vector.begin(), teacher_vector.end(), print_teacher);
	}
	system("pause");
	
}

//�鿴������Ϣ
void manage:: show_computer_room()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<computer_room>::iterator it = computer_room_vector.begin(); it <= computer_room_vector.end(); it++)
	{
		cout << "������ţ� " << it->computer_room_id << " ������������� " << it->computer_room_max_size << endl;

	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void manage::clean_order()
{
	fstream(order_txt, ios::in|ios::trunc);
	cout << "����ԤԼ��¼��ɾ��" << endl;
	system("pause");



}

//��ʼ��ѧ��,��ʦ����
void manage::init_vector()
{
	teacher_vector.clear();
	student_vector.clear();
	fstream ifs;
	ifs.open(student_txt, ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			return;

		}
		student s;
		while (ifs >> s.student_id && ifs >> s.name && ifs >> s.password)
		{
			student_vector.push_back(s);
		}
		ifs.close();

		ifs.open(teacher_txt, ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			return;

		}
		teacher t;
		while (ifs >> t.teacher_id && ifs >> t.name && ifs >> t.password)
		{
			teacher_vector.push_back(t);
		}
		ifs.close();

}

//�������˺��Ƿ��ظ�(���,����)


bool manage::cheak_repeat(int id, int type) 
{
	if (type == 1)
	{
		for (vector<student>::iterator it = student_vector.begin(); it != student_vector.end(); it++)
		{
			if (it->student_id=id)

				return true;

		}

	}

	else if (type == 2)
	{
		for (vector<teacher>::iterator it = teacher_vector.begin();  it != teacher_vector.end(); it++)
		{
			if (it->teacher_id = id)

				return true;

		}

	}

	else
	{
		return false;
	}

}