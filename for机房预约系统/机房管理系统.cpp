#include <iostream>
#include <fstream>
#include "identity.h"
#include "global_file.h"
#include "student.h"
#include "teacher.h"
#include "manage.h"
using namespace std;

void student_menu(identity *  mystudent)//只有父类的属性
{
	while (1)
	{
		mystudent->open_menu();
		int select = 0;
		cin >> select;
		student* stu = (student*)mystudent;//强制类型转换
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
		else if (select == 4) //取消预约
		{
			stu->cancel_order();
		}

		else
		{
			delete mystudent;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			
		}

	}

}

void teacher_menu(identity*myteacher)//只有父类的属性
{
	while (1)
	{
		myteacher->open_menu();
		int select = 0;
		cin >> select;
		teacher* tea = (teacher*)myteacher;//强制类型转换
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");

		}

	}
	

}
void manage_menu(identity* mymanage)//只有父类的属性
{
	while (1)
	{
		mymanage->open_menu();
		int select = 0;
		cin >> select;
		manage* admin = (manage*)mymanage;//强制类型转换
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
			cout << "注销成功" << endl;
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
		cout << "请输入你的学号"<<endl;
		cin >> id;


	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入你的姓名" << endl;
	cin >> name;

	cout << "请输入你的密码" << endl;
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
				cout<< "学生验证登录成功！" << endl;
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
				cout << "教师验证登录成功！" << endl;
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
				cout << "管理员验证登录成功！" << endl;
				person = new manage ( name, passworld);
				 manage_menu(person);
				

			}


		}
	}
	cout << "登录失败,请重新输入" << endl;
	
}


	
	
	



int main()
{
	int select = 1;
	while (select)
	{
		cout << "=================  欢迎来到机房预约系统  =============="<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t ------------------------------- \n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
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
					
					cout << "欢迎下一次使用" << endl;
					break;

				default :
					cout << "输入有误,请重新输入" << endl;
					break;



				}
    }
	
   system("pause");
	return 0;

}