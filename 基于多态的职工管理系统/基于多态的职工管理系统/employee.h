#pragma once
#include <iostream>
#include<string>
#include"worker.h"
using namespace std;

class employee :public worker {
public:
	employee(int id, string name, int did);

	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};