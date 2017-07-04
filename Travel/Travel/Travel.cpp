#include<iostream>
#include<string>
#include<random>
#include"Guestchain.h"
#include"SightTree.h"
#include"SightAVLTree.h"

using namespace std;

//界面
int main() {
	int UserID;									//登录信息判别
	int SightID;									//景点信息
	int guestRandomId;							//游客信息
	string GuestName;							//游客姓名
	string SightName;

	guestchain* headguest;						//当前游客链表头指针，指向当前游客链表的头
	guestchain* GCoperatepoint;					//当前游客链表的操作指针

	//sightTree* MainSightTreePoint;				//景点树头指针(主存储指针）
	//sightTree* SToperatepoint;					//景点树操作指针
	//sightTree* STSearchpoint;					//景点搜索指针

	//MainSightTreePoint = new sightTree(50);		//初始化景点树
	//SToperatepoint = MainSightTreePoint;			//将操作指针初始化
	//STSearchpoint = MainSightTreePoint;			//初始化搜索指针

	sightAVLTree* MainSightAVLTreePoint = new sightAVLTree();
	sightAVLTreeNode* OperatePoint = NULL;			//结点操作指针
	sightAVLTreeNode* SearchPoint = NULL;			//结点搜索指针

	bool UILoop = 1;
	cout << "****************************************" << endl;
	cout << "*       欢迎使用旅游信息管理系统       *" << endl;
	cout << "****************************************" << endl;		//初始化界面
	while (UILoop)
	{
		cout << "请输入登录身份：（1：管理员，2：游客，3：退出）";
		cin >> UserID;
		system("cls");
		//管理员操作
		while (UserID == 1) {
			//输入操作
			int OperateId;
			cout << "请输入操作：（1：添加景点代码，2：删除景点，3：查看景点预约人数，4，查看景点详情，5：退出）";
			cin >> OperateId;
			system("cls");

			if (OperateId == 1) {
				cout << "请输入景点代码和名称用空格分割：";
				cin >> SightID >> SightName;
				MainSightAVLTreePoint->insert(SightID, SightName);		//根据输入插入景点树
				//system("cls");
			}
			if (OperateId == 2) {
				cout << "请输入节点：";
				cin >> SightID;
				SearchPoint = MainSightAVLTreePoint->search(SightID);
				if (SearchPoint->chain != NULL) {
					string operate1;
					cout << "当前景点下有游客，确定要删除吗？（Y/N）";
					cin >> operate1;
					if (operate1 == "y" || operate1 == "Y") {
						MainSightAVLTreePoint->remove(SightID);
					}
				}
				//MainSightAVLTreePoint->remove(SightID);
				//MainSightTreePoint->deletenode(SightID, SToperatepoint);		//根据输入删除景点树结点
				//AllTreePrint(MainSightTreePoint);
				system("cls");
			}
			else if (OperateId == 3) {
				MainSightAVLTreePoint->preOrderPV();
			}
			else if (OperateId == 4) {
				MainSightAVLTreePoint->preOrderAll();
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

			cout << "请输入操作：（1：查看景点，2：预定景点，3：取消预定，4：退出）";
			cin >> OperateId;

			if (OperateId == 1) {
				MainSightAVLTreePoint->preOrderPV();
			}
			else if (OperateId == 2) {
				cout << "请输入姓名：";
				cin >> GuestName;
				cout << "你的操作ID为：" << guestRandomId << " 请牢记！！" << endl;
				headguest = new guestchain(guestRandomId, GuestName);					//初始化游客单链表结点，头指针指向当前单链表
				cout << "请输入景点代码：";
				cin >> SightID;
				//SToperatepoint = MainSightTreePoint->search(SightID, STSearchpoint);	//查找景点代码在树中位置，返回指针
				//STSearchpoint = MainSightTreePoint;										//搜索指针归位

				OperatePoint = MainSightAVLTreePoint->search(SightID);

				if (OperatePoint->chain == NULL) {									//如果当前景点下无人预约
					OperatePoint->chain = headguest;									//则将当前生成的单链表头结点连接到树中
					cout << "预约成功" << endl;
				}
				else
				{
					GCoperatepoint = OperatePoint->chain;															//如果当前景点下已有单链表，单链表操作指针指向当前树下结点
					OperatePoint->chain->insertchain(guestRandomId, GuestName, GCoperatepoint);					//插入当前景点下单链表
					cout << "预约成功" << endl;
				}
				OperatePoint->pv++;

			}
			else if (OperateId == 3) {
				cout << "请输入了景点代码：";
				cin >> SightID;
				cout << "请输入你的操作ID：";
				cin >> guestRandomId;
				//SToperatepoint = MainSightTreePoint->search(SightID, STSearchpoint);	//查找景点代码在树中位置，返回指针
				//STSearchpoint = MainSightTreePoint;										//搜索指针归位
				OperatePoint = MainSightAVLTreePoint->search(SightID);

				if (OperatePoint->chain == NULL) {									//如果当前景点下无人预约
					cout << "无预约信息" << endl;
				}
				else
				{
					GCoperatepoint = OperatePoint->chain;														//如果当前景点下已有单链表，单链表操作指针指向当前树下结点
					OperatePoint->chain = OperatePoint->chain->deletechain(guestRandomId, GCoperatepoint);							//删除当前景点下单链表
				}

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