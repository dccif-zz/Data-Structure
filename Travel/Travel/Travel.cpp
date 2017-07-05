#include<iostream>
#include<string>
#include<random>
#include"Guestchain.h"
#include"SightTree.h"
#include"SightAVLTree.h"

using namespace std;

//界面
int main() {
	int UserID;								//登录信息判别
	int SightID;								//景点信息
	int guestRandomId;						//游客信息
	string GuestName;						//游客姓名
	string SightName;

	guestchain* headguest;						//当前游客链表头指针，指向当前游客链表的头
	guestchain* GCoperatepoint;					//当前游客链表的操作指针
	guestchain* GCSearchPoint;
	GCoperatepoint = NULL;
	GCSearchPoint = NULL;

	sightAVLTree* MainSightAVLTreePoint = new sightAVLTree();
	sightAVLTreeNode* OperatePoint = NULL;			//结点操作指针
	sightAVLTreeNode* SearchPoint = NULL;			//结点搜索指针

	bool UILoop = 1;		//外循环标志
	cout << "****************************************" << endl;
	cout << "*       欢迎使用旅游信息管理系统       *" << endl;
	cout << "****************************************" << endl;		//初始化界面
	while (UILoop)
	{
		cout << "请输入登录：" << endl << "1：管理员" << endl << "2：游客" << endl << "3：退出" << endl;
		cin >> UserID;
		system("cls");
		//管理员操作
		while (UserID == 1) {
			//输入操作
			int OperateId;
			system("cls");
			cout << "请输入操作：" << endl << "1：添加景点代码" << endl << "2：删除景点" << endl << "3：查看景点预约人数" << endl << "4，查看景点详情" << endl << "5：退出" << endl;
			cin >> OperateId;		//记录选项
			system("cls");
			if (OperateId == 1) {
				cout << "请输入景点代码和名称用空格分割：";
				cin >> SightID >> SightName;
				SearchPoint = MainSightAVLTreePoint->search(SightID);		//查找是否存在结点
				if (SearchPoint == NULL) {
					MainSightAVLTreePoint->insert(SightID, SightName);		//如果不存在则根据输入插入景点树
					cout << "景点添加成功！" << endl;
					cout << "先序遍历为：" << endl;
					MainSightAVLTreePoint->preOrder();
					cout << endl << "中序遍历为：" << endl;
					MainSightAVLTreePoint->inOrder();
					cout << endl << "后序遍历为：" << endl;
					MainSightAVLTreePoint->postOrder();
					cout << endl;
				}
				else
				{
					cout << "添加失败：不允许添加相同编号的节点！" << endl;
				}
				system("pause");
				SearchPoint = NULL;
			}
			if (OperateId == 2) {
				MainSightAVLTreePoint->preOrderPV();
				string operate1 = "Y";		//删除标志符号
				cout << "请输入节点：";
				cin >> SightID;
				SearchPoint = MainSightAVLTreePoint->search(SightID);
				//OperatePoint = MainSightAVLTreePoint->search(SightID);
				while (SearchPoint == NULL)			//判断是否存在结点
				{
					cout << "无此景点！请重新输入：" << endl;
					cin >> SightID;
					SearchPoint = MainSightAVLTreePoint->search(SightID);
				}
				if (SearchPoint->chain != NULL) {
					cout << "当前景点下有游客，确定要删除吗？（Y/N）";
					cin >> operate1;
				}
				else if (operate1 == "y" || operate1 == "Y") {
					MainSightAVLTreePoint->remove(SightID);
					cout << "删除成功！" << endl;
					cout << "先序遍历为：" << endl;
					MainSightAVLTreePoint->preOrder();
					cout << endl << "中序遍历为：" << endl;
					MainSightAVLTreePoint->inOrder();
					cout << endl << "后序遍历为：" << endl;
					MainSightAVLTreePoint->postOrder();
					cout << endl;
					operate1 = "Y";
					system("pause");
				}
				else
				{
					cout << "已取消删除，点击返回上一层" << endl;
					system("pause");
				}
			}
			else if (OperateId == 3) {
				MainSightAVLTreePoint->preOrderPV();
				cout << endl;
				system("pause");
			}

			else if (OperateId == 4) {
				MainSightAVLTreePoint->inOrderAll();
				cout << endl;
				system("pause");
			}
			else if (OperateId == 5) {
				break;
			}
		}
		//游客操作
		while (UserID == 2)
		{
			int OperateId;
			//生存随机游客ID
			random_device rd;
			mt19937 gen = mt19937(rd());
			uniform_real_distribution<> dis(1, 100);
			guestRandomId = (int)dis(gen);

			system("cls");
			cout << "请输入操作：" << endl << "1：查看景点" << endl << "2：预定景点" << endl << "3：取消预定" << endl << "4：退出" << endl;
			cin >> OperateId;
			system("cls");

			if (OperateId == 1) {
				cout << "前序遍历的景点信息为：" << endl;
				MainSightAVLTreePoint->preOrderPV();
				system("pause");
			}
			else if (OperateId == 2) {
				cout << "当前由前序遍历的景点信息为：" << endl;
				MainSightAVLTreePoint->preOrderPV();
				cout << "请输入姓名：";
				cin >> GuestName;
				cout << "你的操作ID为：" << guestRandomId << " 请牢记！！" << endl;
				headguest = new guestchain(guestRandomId, GuestName);					//初始化游客单链表结点，头指针指向当前单链表
				cout << "请输入景点代码：";
				cin >> SightID;
				//SToperatepoint = MainSightTreePoint->search(SightID, STSearchpoint);	//查找景点代码在树中位置，返回指针
				//STSearchpoint = MainSightTreePoint;									//搜索指针归位

				OperatePoint = MainSightAVLTreePoint->search(SightID);
				while (OperatePoint == NULL)
				{
					cout << "无此景点！请重新输入：" << endl;
					cin >> SightID;
					OperatePoint = MainSightAVLTreePoint->search(SightID);
				}

				if (OperatePoint->chain == NULL)
				{												//如果当前景点下无人预约
					OperatePoint->chain = headguest;			//则将当前生成的单链表头结点连接到树中
					cout << "预约成功" << endl;
				}
				else
				{
					GCoperatepoint = OperatePoint->chain;															//如果当前景点下已有单链表，单链表操作指针指向当前树下结点
					OperatePoint->chain->insertchain(guestRandomId, GuestName, GCoperatepoint);					//插入当前景点下单链表
					cout << "预约成功" << endl;
				}
				system("pause");
				OperatePoint->pv++;
			}
			else if (OperateId == 3) {
				cout << "当前由前序遍历的景点信息为：" << endl;
				MainSightAVLTreePoint->preOrderPV();
				cout << "请输入了景点代码：";
				cin >> SightID;
				guestchain* inlinechain;

				OperatePoint = MainSightAVLTreePoint->search(SightID);
				while (OperatePoint == NULL)
				{
					cout << "无此景点！请重新输入：" << endl;
					cin >> SightID;
					OperatePoint = MainSightAVLTreePoint->search(SightID);
				}
				OperatePoint->chain->printall();
				cout << "请输入要删除的用户ID：";
				cin >> guestRandomId;
				inlinechain = OperatePoint->chain;
				GCSearchPoint = OperatePoint->chain;
				GCoperatepoint = OperatePoint->chain->chainsearch(guestRandomId, GCSearchPoint);
				while (GCoperatepoint == NULL) {
					cout << "无此ID，请重新输入：";
					cin >> guestRandomId;
					GCoperatepoint = OperatePoint->chain->chainsearch(guestRandomId, GCSearchPoint);
				}

				GCoperatepoint = OperatePoint->chain;												//如果当前景点下已有单链表，单链表操作指针指向当前树下结点
				OperatePoint->chain = OperatePoint->chain->deletechain(guestRandomId, inlinechain);							//删除当前景点下单链表
				cout << "删除成功！" << endl;
				OperatePoint->chain->printall();
				OperatePoint->pv--;
				system("pause");
			}
			else if (OperateId == 4)
			{
				break;
			}
		}
		//退出
		while (UserID == 3)
		{
			UILoop = 0;
			break;
		}

	}

	system("pause");
	return 0;
}