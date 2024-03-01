// 文件名：main
// 创建时间：2024/2/1 13:35:01
// 创建者：@fangyu
#include <iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int choice;

int main()
{
	/*worker* wk = null;
	wk = new employee(1, "张三", 1);
	wk->showinfo();
	delete wk;

	wk = new manager(2, "里斯", 2);
	wk->showinfo();
	delete wk;
	wk = new boss(3, "查里苏", 3);
	wk->showinfo();
	delete wk;*/
	while (true)
	{
		workerManager wm;
		wm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工信息
			wm.addWorker();
			break;
		case 2://显示职工信息
			wm.showWorker();
			break;
		case 3://删除职工
			wm.delWorker();
			break;
		case 4://修改职工
			wm.modWorker();
			break;
		case 5://查找职工
			wm.findWorker();
			break;
		case 6://排序职工
			wm.sortWorker();
			break;
		case 7://清空文档
			wm.cleanFile();
			break;
		default:
			system("cls");//清空屏幕
			break;
		}
	}
	return 0;
}


	