#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

workerManager::workerManager() {
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//以读文件的方式打开
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化人数为0
		this->workerNum = 0;
		//初始化数组指针为空
		this->workerArray = NULL;
		//初始化文件是否为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在但是没有内容
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在并且记录了数据
	int num = this->getWorkerNum();
	cout << "职工人数为" << num << "人" << endl;
	this->workerNum = num;
	this->workerArray = new worker * [this->workerNum];
	initWorker();
	
}

void workerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
} 

void workerManager::showMenu() {
	cout << "****************************" << endl;
	cout << "****欢迎使用职工管理系统****" << endl;
	cout << "****   0 退出管理系统   ****" << endl;
	cout << "****   1 增加职工信息   ****" << endl;
	cout << "****   2 显示职工信息   ****" << endl;
	cout << "****   3 删除职工信息   ****" << endl;
	cout << "****   4 修改职工信息   ****" << endl;
	cout << "****   5 查找职工信息   ****" << endl;
	cout << "****   6 按照编号排序   ****" << endl;
	cout << "****   7 清空所有文档   ****" << endl;
	cout << "****************************" << endl;
	cout << endl;

}

void workerManager::addWorker() {
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//执行添加操作
		//计算添加新空间的大小
		int newsize = this->workerNum + addNum;
		//开辟新空间
		worker** newspace = new worker* [newsize];
		//将原来空间下的数据拷贝到新空间
		if (this->workerArray != NULL) {
			for (int i = 0; i < this->workerNum; i++) {
				newspace[i] = this->workerArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;//职工编号
			string name;//职工姓名
			int did;//部门选择

			int falseId = 1;
			while (falseId)
			{
				cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
				cin >> id;
				for (int i = 0; i < this->workerNum; i++)
				{
					if (this->workerArray[i]->workerId == id)
					{
						cout << "该职工编号已存在" << endl;
						falseId = 1;
						break;
					}
					else
					{
						falseId = 0;
					}
				}
			}
			
			
			cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;

			worker* wk = NULL;
			switch (did)
			{
			case 1:
				wk = new employee(id, name, 1);
				break;
			case 2:
				wk = new manager(id, name, 2);
				break;
			case 3:
				wk = new boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针保存在数组里
			newspace[this->workerNum + i] = wk;
		}
		//释放原有空间
		delete[] this->workerArray;
		//更改新空间指向
		this->workerArray = newspace;
		//更新新空间人数
		this->workerNum = newsize;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
		//保存数据到文件中
		this->save();
		this->FileIsEmpty = false;
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}

int workerManager::getWorkerNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}
void workerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件——写文件

	//将每个人的数据都写入到文件中
	for (int i = 0; i < this->workerNum;i++) {
		ofs << this->workerArray[i]->workerId << " "
			<< this->workerArray[i]->workerName << " "
			<< this->workerArray[i]->deptId << endl;
	}
	//关闭文件
	ofs.close();
}

void workerManager::initWorker() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	 
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		worker* wk = NULL;
		if (did == 1) {
			wk = new employee(id, name, did);
		}
		else if (did == 2) {
			wk = new manager(id, name, did);
		}
		else {
			wk = new boss(id, name, did);
		}
		this->workerArray[index] = wk;
		index++;
	}
}

void workerManager::showWorker() {
	if (FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < workerNum; i++)
		{
			this->workerArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int workerManager::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerArray[i]->workerId == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::delWorker() {
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)//说明职工存在并且要删除该位置的职工
		{
			for (int i = index; i < this->workerNum - 1; i++)
			{
				//数据前移
				this->workerArray[i] = this->workerArray[i + 1];
			}
			this->workerNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，没有找到该编号的职工！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::modWorker() {
	if ( !this->FileIsEmpty )
	{
		cout << "请输入要修改的职工id" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->workerArray[index];
			int newId = 0;
			string newName = " ";
			int newDid = 0;
			cout << "查到编号为" << id << "的员工" << endl;
			cout << "请输入新的职工号：" << endl;
			cin >> newId;
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			cout << "请选择该职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newDid;

			worker* wk = NULL;
			switch (newDid)
			{
			case 1:
				wk = new employee(newId, newName, newDid);
				break;
			case 2:
				wk = new manager(newId, newName, newDid);
				break;
			case 3:
				wk = new boss(newId, newName, newDid);
				break;
			default:
				break;
			}
			this->workerArray[index] = wk;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，没有找到该编号的职工！" << endl;
		}
	}
	else
	{
		cout << "文件不存在或为空！" << endl;
	}
	system("pause");
	system("cls");
}

void workerManager::findWorker() {
	if (!this->FileIsEmpty)
	{
		cout << "请输入查找方式" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = this->isExist(id);
			if (ret == -1)
			{
				cout << "不存在该编号的职工！" << endl;
			}
			else
			{
				this->workerArray[ret]->showInfo();
			}
	    }
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的职工姓名：" << endl;
			cin >> name;

			int ret = this->nameIsExist(name);
			if (ret == -1)
			{
				cout << "不存在该姓名的职工" << endl;
			}
			else
			{
				this->workerArray[ret]->showInfo();
			}
		}
		else
		{
			cout << "输入错误！" << endl;
		}
	}
			
	else
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	system("pause");
	system("cls");
}

int workerManager::nameIsExist(string name) {
	int ret = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workerArray[i]->workerName == name)
		{
			ret = i;
			break;
		}
	}
	return ret;
}

void workerManager::sortWorker() {
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select = 0;
		cout << "请选择按照编号的排序方式：" << endl;
		cout << "1、升序排列" << endl;
		cout << "2、降序排列" << endl;
		cin >> select;

		for (int i = 0; i < this->workerNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->workerNum; j++)
			{
				if (select == 1)
				{
					if (this->workerArray[minOrMax]->workerId > this->workerArray[j]->workerId)
					{
						minOrMax = j;
					}

				}
				else if (select == 2)
				{
					if (this->workerArray[minOrMax]->workerId < this->workerArray[j]->workerId)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "输入错误！" << endl;
				}
			}
			if (i != minOrMax)
			{
				worker* temp = this->workerArray[i];
				this->workerArray[i] = this->workerArray[minOrMax];
				this->workerArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序后的顺序是：" << endl;
		this->save();
		this->showWorker();
	}
}

void workerManager::cleanFile() {
	int select = 0;
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//如果存在文件删除文件并重新创建
		ofs.close();

		//释放堆区数据
		if (this->workerArray != NULL)
		{
			for (int i = 0; i < this->workerNum; i++)
			{
				if (this->workerArray[i] != NULL)
				{
					delete this->workerArray[i];
				}
			}
			this->workerNum = 0;
			delete[] this->workerArray;
			this->workerArray = NULL;
			this->FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager() {
	if (this->workerArray != NULL)
	{
		delete[] this->workerArray;
		this->workerArray = NULL;
	}
}