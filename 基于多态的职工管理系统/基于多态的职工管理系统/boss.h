#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class boss : public worker {
public:
	boss(int id, string name, int did);
	
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
