#include "order_file.h"
order_file::order_file()
{
	fstream ifs;
	ifs.open(order_txt, ios::in);
	string date; // ����
	string interval;//ʱ���
	string student_id;   //ѧ�����
	string student_name; //ѧ������
	string roomId;  //�������
	string status;
	this->order_size = 0;
	while (ifs >> student_name && ifs >> interval && ifs
		>> student_id && ifs >> student_name && ifs >> roomId && ifs >> status)
	{  
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");
		key = date.substr(0, pos);//�����￪ʼ,�ض���
		value = date.substr(pos + 1, date.size() - pos - 1);
		m.insert(make_pair(key, value));
		 
		pos = interval.find(":");
		key = interval.substr(0, pos);//�����￪ʼ,�ض���
		value = interval.substr(pos + 1, interval.size() - pos - 1);
		m.insert(make_pair(key, value));

		pos = student_id.find(":");
		key = student_id.substr(0, pos);//�����￪ʼ,�ض���
		value = student_id.substr(pos + 1, student_id.size() - pos - 1);
		m.insert(make_pair(key, value));
			
		pos = student_name.find(":");
		key = student_name.substr(0, pos);//�����￪ʼ,�ض���
		value = student_name.substr(pos + 1, student_name.size() - pos - 1);
		m.insert(make_pair(key, value));
		
		pos = roomId.find(":");
		key = roomId.substr(0, pos);//�����￪ʼ,�ض���
		value = roomId.substr(pos + 1, roomId.size() - pos - 1);
		m.insert(make_pair(key, value));


		pos = status.find(":");
		key = status.substr(0, pos);//�����￪ʼ,�ض���
		value = status.substr(pos + 1, status.size() - pos - 1);
		m.insert(make_pair(key, value));

		this->order_data.insert(make_pair(order_size, m));
		order_size++;
	}
	ifs.close();

}


void  order_file:: updata_order()
{
	if (order_size==0)
	{
		return; //ԤԼ��¼0����ֱ��return
	}
	ofstream ofs;
	ofs.open(order_txt, ios::out | ios::trunc);
		for (int i = 0; i < this->order_size; i++)
		{
			ofs << "date:" << this->order_data[i]["date"] << " ";
			ofs << "interval:" << this->order_data[i]["interval"] << " ";
			ofs << "stuId:" << this->order_data[i]["stuId"] << " ";
			ofs << "stuName:" << this->order_data[i]["stuName"] << " ";
			ofs << "roomId:" << this->order_data[i]["roomId"] << " ";
			ofs << "status:" << this->order_data[i]["status"] << endl;
		}
		ofs.close();
}