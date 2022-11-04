#include "student.h"

student:: student(int id, string name, string password)//�вι���
{
	this->student_id = id;
	this->name = name;
	this->password = password;
	ifstream ifs;
	ifs.open(computer_txt, ios::in);
	computer_room com;
	while (ifs >> com.computer_room_id && ifs >> com.computer_room_max_size)
	{
		computer_room_vector.push_back(com);

	}
	ifs.close();
}

void   student::open_menu()//�ع�ѧ���Ӳ˵�
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void student::apply_order()//����ԤԼ
{
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;

		}
		else
		{
			cout << "�������" << endl;
		}

		cout << "����������ԤԼʱ��Σ�" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;

		}
		else
		{
			cout << "�������" << endl;
		}
		cout << "��ѡ�������" << endl;
		for (int i = 0; i < computer_room_vector.size(); i++)
		{
			cout << computer_room_vector[i].computer_room_id << "�Ż�������Ϊ�� " << computer_room_vector[i].computer_room_max_size << endl;
		}
		while (true)
		{
			cin >> room;
			if (room >= 1 && room <= 3)
			{
				break;
			}
			cout << "������������������" << endl;
		}
		cout << "ԤԼ�ɹ��������" << endl;
		fstream ofs;
		ofs.open(order_txt, ios::out|ios::app);//׷��

		ofs << "date:" << date << " ";
		ofs << "interval:" << interval << " ";
		ofs << "stuId:" << this->student_id << " ";
		ofs << "stuName:" << this->name << " ";
		ofs << "roomId:" << room << " ";
		ofs << "status:" << 1 << endl;
		ofs.close();

		system("pause");
		system("cls");

	}

}

void student::show_my_order()//��ʾ����ԤԼ
{
	order_file of;
	if(of.order_size==0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		if (this->student_id == atoi(of.order_data[i]["student_id"].c_str()))
		{
			cout << "ԤԼ���ڣ� ��" << of.order_data[i]["date"];//
			//��keyȥѰ��
			cout << " ʱ��Σ� " << (of.order_data[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ� " << of.order_data[i]["roomId"];
			string status = "״̬�� ";
			
			// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			if (of.order_data[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
		}



	}


void student::show_all_order()//��ʾ����ԤԼ
{
	order_file of;
	if (of.order_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		
			cout << "ԤԼ���ڣ� ��" << of.order_data[i]["date"];
			cout << " ʱ��Σ� " << (of.order_data[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ� " << of.order_data[i]["roomId"];
			string status = "״̬�� ";
			// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			if (of.order_data[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	



}
void student::cancel_order()//ȡ��ԤԼ
{
	order_file of;
	if (of.order_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		if (this->student_id == atoi(of.order_data[i]["student_id"].c_str()))
		{
			cout << i << "��";
			cout << "ԤԼ���ڣ� ��" << of.order_data[i]["date"];
			cout << " ʱ��Σ� " << (of.order_data[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ� " << of.order_data[i]["roomId"];
			string status = "״̬�� ";
			// 1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
			if (of.order_data[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	int select = 0;
	cout << "��ѡ��Ҫȡ����ԤԼ" << endl;
	cin >> select;
   
	of.order_data[select - 1]["status"] = "0";
	cout << "ȡ���ɹ�" << endl;
	system("pause");




}
