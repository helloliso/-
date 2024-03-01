#pragma once
#include <iostream>
#include <string>
using namespace std;

class worker {
public:
	//显示个人信息
	virtual void showInfo() = 0;//纯虚函数定义的抽象类
	//获取岗位名称
	virtual string getDeptName() = 0;

	int workerId;//职工编号
	string workerName;//职工姓名
	int deptId;//职工部门编号


};