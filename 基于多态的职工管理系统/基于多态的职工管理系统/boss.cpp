#include"boss.h"
using namespace std;

boss::boss(int id, string name, int did) {
	this->workerId = id;
	this->workerName = name;
	this->deptId = did;
}

void boss::showInfo() {
	cout << "ְ����ţ�" << this->workerId
		<< "\tְ��������" << this->workerName
		<< "\tְ�����ţ�" << this->getDeptName()
		<< "\t��λְ�𣺹滮��˾�ķ�չ"
		<< endl;
}
//��ȡ��λ����
string boss::getDeptName(){
	return string("�ϰ�");
}