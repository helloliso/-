#pragma once
#include <iostream>
#include<string>
#include"worker.h"
using namespace std;

class employee :public worker {
public:
	employee(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};