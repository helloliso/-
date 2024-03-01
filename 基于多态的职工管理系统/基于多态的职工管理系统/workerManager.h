#pragma once//防止头文件重复包含
#include <iostream>
#include"worker.h"
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;

class workerManager {
public:
	workerManager();//构造函数

	void showMenu();//展示菜单

	int workerNum;//记录职工人数

	worker** workerArray;//职工数组

	void addWorker();//添加职工

	void showWorker();//显示职工

	void exitSystem();//退出系统

	void save();//保存文件

	int getWorkerNum();//获取已经存在的职工数量

	void initWorker();//初始化

	bool FileIsEmpty;//判断文件是否为空的标志

	int isExist(int id);//判断职工是否存在

	void delWorker();//删除职工

	void modWorker();//修改职工

	void findWorker();//查找职工

	void sortWorker();//职工排序

	void cleanFile();//清空文件

	int nameIsExist(string name);//根据姓名判断职工是否存在

	~workerManager();//析构函数
};