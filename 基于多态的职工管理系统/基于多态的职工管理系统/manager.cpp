#include"manager.h"
using namespace std;

manager::manager(int id, string name, int did) {
	this->workerId = id;
	this->workerName = name;
	this->deptId = did;
}
//显示个人信息
void manager::showInfo() {
	cout << "职工编号：" << this->workerId
		<< "\t职工姓名：" << this->workerName
		<< "\t职工部门：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务"
		<< endl;
}
//获取岗位名称
string manager::getDeptName() {
	return string("经理");
}