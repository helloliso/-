#include"manager.h"
using namespace std;

manager::manager(int id, string name, int did) {
	this->workerId = id;
	this->workerName = name;
	this->deptId = did;
}
//��ʾ������Ϣ
void manager::showInfo() {
	cout << "ְ����ţ�" << this->workerId
		<< "\tְ��������" << this->workerName
		<< "\tְ�����ţ�" << this->getDeptName()
		<< "\t��λְ������ϰ彻��������"
		<< endl;
}
//��ȡ��λ����
string manager::getDeptName() {
	return string("����");
}