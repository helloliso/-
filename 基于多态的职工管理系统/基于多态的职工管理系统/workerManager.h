#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
#include"worker.h"
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;

class workerManager {
public:
	workerManager();//���캯��

	void showMenu();//չʾ�˵�

	int workerNum;//��¼ְ������

	worker** workerArray;//ְ������

	void addWorker();//���ְ��

	void showWorker();//��ʾְ��

	void exitSystem();//�˳�ϵͳ

	void save();//�����ļ�

	int getWorkerNum();//��ȡ�Ѿ����ڵ�ְ������

	void initWorker();//��ʼ��

	bool FileIsEmpty;//�ж��ļ��Ƿ�Ϊ�յı�־

	int isExist(int id);//�ж�ְ���Ƿ����

	void delWorker();//ɾ��ְ��

	void modWorker();//�޸�ְ��

	void findWorker();//����ְ��

	void sortWorker();//ְ������

	void cleanFile();//����ļ�

	int nameIsExist(string name);//���������ж�ְ���Ƿ����

	~workerManager();//��������
};