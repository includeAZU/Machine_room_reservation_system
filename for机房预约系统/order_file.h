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
	//��¼����ԤԼ��Ϣ������  key��¼����   value �����¼��ֵ����Ϣ
	map <int, map <string, string >> order_data;




};