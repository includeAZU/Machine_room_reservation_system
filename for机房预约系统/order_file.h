#pragma once
#include <iostream>
#include "global_file.h"
#include <fstream>
#include <map>
#include<string >
using namespace std;
class order_file
{
public :
	order_file();

	void updata_order();

	int order_size;
	//记录所有预约信息的容器  key记录条数   value 具体记录键值对信息
	map <int, map <string, string >> order_data;




};