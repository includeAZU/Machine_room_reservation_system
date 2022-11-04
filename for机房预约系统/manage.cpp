#include "manage.h"
#include "global_file.h"
manage::manage(string name, string password)//	有参构造
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
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void manage::add_person()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	string file_name;
	string tip;
	string error_tip;
	fstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		file_name = student_txt;
		tip = "请输入学号：";
		error_tip = "学号重复，请重新输入";
	}
	else
	{
		file_name = teacher_txt;
		tip = "请输入职工编号：";
		error_tip = "职工号重复，请重新输入";
	}
	ofs.open(file_name, ios::out|ios::app);
	int id; //学号 /职工号
	string name; //姓名
	string pwd; //密码
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
	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << "  " << name << "  " << pwd << "  " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->init_vector();

}
//查看账号
void print_student(student &s)
{
	cout << "学号： " << s.student_id<< " 姓名： " << s.name << " 密码：" << s.password << endl;

}
void print_teacher(teacher& s)
{
	cout << "学号： " << s.teacher_id << " 姓名： " << s.name << " 密码：" << s.password << endl;

}
void manage::show_person()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int select = 0; //接受用户选择
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(student_vector.begin(), student_vector.end(), print_student);
	}
	if (select == 2)
	{
		cout << "所有教师信息如下：" << endl;
		for_each(teacher_vector.begin(), teacher_vector.end(), print_teacher);
	}
	system("pause");
	
}

//查看机房信息
void manage:: show_computer_room()
{
	cout << "机房信息如下：" << endl;
	for (vector<computer_room>::iterator it = computer_room_vector.begin(); it <= computer_room_vector.end(); it++)
	{
		cout << "机房编号： " << it->computer_room_id << " 机房最大容量： " << it->computer_room_max_size << endl;

	}
	system("pause");
	system("cls");
}
//清空预约记录
void manage::clean_order()
{
	fstream(order_txt, ios::in|ios::trunc);
	cout << "所有预约记录已删除" << endl;
	system("pause");



}

//初始化学生,老师容器
void manage::init_vector()
{
	teacher_vector.clear();
	student_vector.clear();
	fstream ifs;
	ifs.open(student_txt, ios::in);
		if (!ifs.is_open())
		{
			cout << "文件打开失败" << endl;
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
			cout << "文件打开失败" << endl;
			return;

		}
		teacher t;
		while (ifs >> t.teacher_id && ifs >> t.name && ifs >> t.password)
		{
			teacher_vector.push_back(t);
		}
		ifs.close();

}

//检测添加账号是否重复(编号,类型)


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