#include"employee.h"
using namespace std;

employee::employee(int id,string name, int did) {
	this->workerId = id;
	this->workerName = name;
	this->deptId = did;
}


//��ʾ������Ϣ
void employee::showInfo() {
	cout << "ְ����ţ�" << this->workerId
		<< "\tְ��������" << this->workerName
		<< "\tְ�����ţ�" << this->getDeptName()
		<< "\t��λְ����ɾ�����������"
		<< endl;
}
//��ȡ��λ����
string employee::getDeptName() {
	return string("Ա��");
}