#include <iostream>
#include <fstream>
#include "identity.h"
#include "global_file.h"
#include "student.h"
#include "teacher.h"
#include "manage.h"
using namespace std;

void student_menu(identity *  mystudent)//ֻ�и��������
{
	while (1)
	{
		mystudent->open_menu();
		int select = 0;
		cin >> select;
		student* stu = (student*)mystudent;//ǿ������ת��
		if (select == 1)
		{
			stu->apply_order();

		}
		else if (select == 2)
		{
			stu->show_my_order();

		}
		else if (select == 3) 
		{
			stu->show_all_order();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancel_order();
		}

		else
		{
			delete mystudent;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			
		}

	}

}

void teacher_menu(identity*myteacher)//ֻ�и��������
{
	while (1)
	{
		myteacher->open_menu();
		int select = 0;
		cin >> select;
		teacher* tea = (teacher*)myteacher;//ǿ������ת��
		if (select == 1)
		{
			tea->show_all_order();

		}
		else if (select == 2)
		{
			tea->valid_order();


		}
		

		else
		{
			delete myteacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");

		}

	}
	

}
void manage_menu(identity* mymanage)//ֻ�и��������
{
	while (1)
	{
		mymanage->open_menu();
		int select = 0;
		cin >> select;
		manage* admin = (manage*)mymanage;//ǿ������ת��
		if (select == 1)
		{
			admin->add_person();

		}
		else if (select == 2)
		{
			admin->show_person();


		}
		else if (select == 3)
		{
			admin->show_computer_room();


		}

		else if (select == 3)
		{
			admin->clean_order();


		}
		else
		{
			delete mymanage;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");

		}

	}
}


void  myloginin( string file_name, int type)

{
	identity* person = NULL;
	fstream ifs;
	ifs.open(file_name, ios::in);

	if (!ifs.is_open())
	{
		ifs.close();
		
	}
	int id = 0;
	string name;
	string passworld;

	if (type ==1)
	{
		cout << "���������ѧ��"<<endl;
		cin >> id;


	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������������" << endl;
	cin >> name;

	cout << "�������������" << endl;
	cin >> passworld;

	if (type == 1)
	{
		int fid;
		string fname;
		string fpassworld;

		while (ifs >> fid && ifs >> fname && ifs >> fpassworld)
		{
			if (id == fid && name == fname && passworld == fpassworld)
			{
				cout<< "ѧ����֤��¼�ɹ���" << endl;
				person = new student(id, name, passworld);
				student_menu(person);
				

			}
			

		}
	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpassworld;

		while (ifs >> fid && ifs >> fname && ifs >> fpassworld)
		{
			if (fid == id && name == fname && passworld == fpassworld)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				person = new teacher(id, name, passworld);
				 teacher_menu(person);
				

			}


		}
	}
	else if (type == 3)
	{
		
		string fname;
		string fpassworld;

		while (ifs >> fname && ifs >> fpassworld)
		{
			if ( name == fname && passworld == fpassworld)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				person = new manage ( name, passworld);
				 manage_menu(person);
				

			}


		}
	}
	cout << "��¼ʧ��,����������" << endl;
	
}


	
	
	



int main()
{
	int select = 1;
	while (select)
	{
		cout << "=================  ��ӭ��������ԤԼϵͳ  =============="<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
				cin >> select;
	    
	
				switch (select)
				{
				case 1:
					  myloginin (  student_txt, 1);
					break;


				case 2:
					 myloginin (teacher_txt,2);
					break;

				case 3:
					myloginin (admin_txt, 3);
					break;

				case 0:
					
					cout << "��ӭ��һ��ʹ��" << endl;
					break;

				default :
					cout << "��������,����������" << endl;
					break;



				}
    }
	
   system("pause");
	return 0;

}