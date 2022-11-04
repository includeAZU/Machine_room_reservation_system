#include "student.h"

student:: student(int id, string name, string password)//有参构造
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

void   student::open_menu()//重构学生子菜单
{
	cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void student::apply_order()//申请预约
{
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
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
			cout << "输入错误" << endl;
		}

		cout << "请输入申请预约时间段：" << endl;
		cout << "1、上午" << endl;
		cout << "2、下午" << endl;
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;

		}
		else
		{
			cout << "输入错误" << endl;
		}
		cout << "请选择机房：" << endl;
		for (int i = 0; i < computer_room_vector.size(); i++)
		{
			cout << computer_room_vector[i].computer_room_id << "号机房容量为： " << computer_room_vector[i].computer_room_max_size << endl;
		}
		while (true)
		{
			cin >> room;
			if (room >= 1 && room <= 3)
			{
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "预约成功！审核中" << endl;
		fstream ofs;
		ofs.open(order_txt, ios::out|ios::app);//追加

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

void student::show_my_order()//显示自身预约
{
	order_file of;
	if(of.order_size==0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		if (this->student_id == atoi(of.order_data[i]["student_id"].c_str()))
		{
			cout << "预约日期： 周" << of.order_data[i]["date"];//
			//用key去寻找
			cout << " 时间段： " << (of.order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号： " << of.order_data[i]["roomId"];
			string status = "状态： ";
			
			// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			if (of.order_data[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
		}



	}


void student::show_all_order()//显示所有预约
{
	order_file of;
	if (of.order_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		
			cout << "预约日期： 周" << of.order_data[i]["date"];
			cout << " 时间段： " << (of.order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号： " << of.order_data[i]["roomId"];
			string status = "状态： ";
			// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			if (of.order_data[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	



}
void student::cancel_order()//取消预约
{
	order_file of;
	if (of.order_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.order_size; i++)
	{
		if (this->student_id == atoi(of.order_data[i]["student_id"].c_str()))
		{
			cout << i << "、";
			cout << "预约日期： 周" << of.order_data[i]["date"];
			cout << " 时间段： " << (of.order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号： " << of.order_data[i]["roomId"];
			string status = "状态： ";
			// 1 审核中  2 已预约  -1 预约失败  0 取消预约
			if (of.order_data[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.order_data[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.order_data[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	int select = 0;
	cout << "请选择要取消的预约" << endl;
	cin >> select;
   
	of.order_data[select - 1]["status"] = "0";
	cout << "取消成功" << endl;
	system("pause");




}
