#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;

class manager :public worker
{
public:
	manager(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();



};