#pragma once
#include <iostream>
#include <string>
using namespace std;

class worker {
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;//���麯������ĳ�����
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int workerId;//ְ�����
	string workerName;//ְ������
	int deptId;//ְ�����ű��


};