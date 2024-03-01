#include"boss.h"
using namespace std;

boss::boss(int id, string name, int did) {
	this->workerId = id;
	this->workerName = name;
	this->deptId = did;
}

void boss::showInfo() {
	cout << "职工编号：" << this->workerId
		<< "\t职工姓名：" << this->workerName
		<< "\t职工部门：" << this->getDeptName()
		<< "\t岗位职责：规划公司的发展"
		<< endl;
}
//获取岗位名称
string boss::getDeptName(){
	return string("老板");
}