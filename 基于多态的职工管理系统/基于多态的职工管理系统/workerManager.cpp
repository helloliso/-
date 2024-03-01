#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

workerManager::workerManager() {
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//�Զ��ļ��ķ�ʽ��
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ������Ϊ0
		this->workerNum = 0;
		//��ʼ������ָ��Ϊ��
		this->workerArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڵ���û������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->workerNum = 0;
		this->workerArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ����ڲ��Ҽ�¼������
	int num = this->getWorkerNum();
	cout << "ְ������Ϊ" << num << "��" << endl;
	this->workerNum = num;
	this->workerArray = new worker * [this->workerNum];
	initWorker();
	
}

void workerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
} 

void workerManager::showMenu() {
	cout << "****************************" << endl;
	cout << "****��ӭʹ��ְ������ϵͳ****" << endl;
	cout << "****   0 �˳�����ϵͳ   ****" << endl;
	cout << "****   1 ����ְ����Ϣ   ****" << endl;
	cout << "****   2 ��ʾְ����Ϣ   ****" << endl;
	cout << "****   3 ɾ��ְ����Ϣ   ****" << endl;
	cout << "****   4 �޸�ְ����Ϣ   ****" << endl;
	cout << "****   5 ����ְ����Ϣ   ****" << endl;
	cout << "****   6 ���ձ������   ****" << endl;
	cout << "****   7 ��������ĵ�   ****" << endl;
	cout << "****************************" << endl;
	cout << endl;

}

void workerManager::addWorker() {
	cout << "���������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//ִ����Ӳ���
		//��������¿ռ�Ĵ�С
		int newsize = this->workerNum + addNum;
		//�����¿ռ�
		worker** newspace = new worker* [newsize];
		//��ԭ���ռ��µ����ݿ������¿ռ�
		if (this->workerArray != NULL) {
			for (int i = 0; i < this->workerNum; i++) {
				newspace[i] = this->workerArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int did;//����ѡ��

			int falseId = 1;
			while (falseId)
			{
				cout << "�������" << i + 1 << "����Ա���ı�ţ�" << endl;
				cin >> id;
				for (int i = 0; i < this->workerNum; i++)
				{
					if (this->workerArray[i]->workerId == id)
					{
						cout << "��ְ������Ѵ���" << endl;
						falseId = 1;
						break;
					}
					else
					{
						falseId = 0;
					}
				}
			}
			
			
			cout << "�������" << i + 1 << "����Ա����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��������ְ��ָ�뱣����������
			newspace[this->workerNum + i] = wk;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->workerArray;
		//�����¿ռ�ָ��
		this->workerArray = newspace;
		//�����¿ռ�����
		this->workerNum = newsize;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		//�������ݵ��ļ���
		this->save();
		this->FileIsEmpty = false;
	}
	else {
		cout << "��������" << endl;
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
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�����д�ļ�

	//��ÿ���˵����ݶ�д�뵽�ļ���
	for (int i = 0; i < this->workerNum;i++) {
		ofs << this->workerArray[i]->workerId << " "
			<< this->workerArray[i]->workerName << " "
			<< this->workerArray[i]->deptId << endl;
	}
	//�ر��ļ�
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)//˵��ְ�����ڲ���Ҫɾ����λ�õ�ְ��
		{
			for (int i = index; i < this->workerNum - 1; i++)
			{
				//����ǰ��
				this->workerArray[i] = this->workerArray[i + 1];
			}
			this->workerNum--;
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�û���ҵ��ñ�ŵ�ְ����" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerManager::modWorker() {
	if ( !this->FileIsEmpty )
	{
		cout << "������Ҫ�޸ĵ�ְ��id" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->workerArray[index];
			int newId = 0;
			string newName = " ";
			int newDid = 0;
			cout << "�鵽���Ϊ" << id << "��Ա��" << endl;
			cout << "�������µ�ְ���ţ�" << endl;
			cin >> newId;
			cout << "�������µ�������" << endl;
			cin >> newName;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�û���ҵ��ñ�ŵ�ְ����" << endl;
		}
	}
	else
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	system("pause");
	system("cls");
}

void workerManager::findWorker() {
	if (!this->FileIsEmpty)
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = this->isExist(id);
			if (ret == -1)
			{
				cout << "�����ڸñ�ŵ�ְ����" << endl;
			}
			else
			{
				this->workerArray[ret]->showInfo();
			}
	    }
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;

			int ret = this->nameIsExist(name);
			if (ret == -1)
			{
				cout << "�����ڸ�������ְ��" << endl;
			}
			else
			{
				this->workerArray[ret]->showInfo();
			}
		}
		else
		{
			cout << "�������" << endl;
		}
	}
			
	else
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select = 0;
		cout << "��ѡ���ձ�ŵ�����ʽ��" << endl;
		cout << "1����������" << endl;
		cout << "2����������" << endl;
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
					cout << "�������" << endl;
				}
			}
			if (i != minOrMax)
			{
				worker* temp = this->workerArray[i];
				this->workerArray[i] = this->workerArray[minOrMax];
				this->workerArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ���������˳���ǣ�" << endl;
		this->save();
		this->showWorker();
	}
}

void workerManager::cleanFile() {
	int select = 0;
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//��������ļ�ɾ���ļ������´���
		ofs.close();

		//�ͷŶ�������
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
		cout << "��ճɹ���" << endl;
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