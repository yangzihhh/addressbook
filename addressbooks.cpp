#include <iostream>
using namespace std;
#include<string>
#define max 100
//打印菜单
void showmenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
};
//创建联系人结构体
struct person {
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
//创建通讯录结构体
struct addressbooks 
{
	struct person personArray[max];
	int size;
};

//添加联系人
void addPerson(addressbooks* abs)
{
	if (abs->size == max)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->size].name = name;

		cout << "请输入性别" << endl;
		int sex = 0;
		cin >> sex;
		abs->personArray[abs->size].sex = sex;

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;
		 
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}
}
//显示联系人
void showPerson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录里没有联系人" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << abs->personArray[i].sex << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phone << "\t";
			cout << "地址：" << abs->personArray[i].address << "\t";
		}
	}
};

//查找联系人有则返回联系人的数组下表，无则返回-1
int isExit(addressbooks *abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;
		else
			return -1;
	}

}
//删除联系人
void deletePerson(addressbooks* abs,string name)
{
	int ret=isExit(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;

	system("pause");
	system("cls");
}
//查找联系人信息
void findPerson(addressbooks* abs, string name)
{
	int ret=isExit(abs, name);
	if (ret != -1)
	{
		int i = ret;
		cout << "姓名：" << abs->personArray[i].name << "\t";
		cout << "性别：" << abs->personArray[i].sex << "\t";
		cout << "年龄：" << abs->personArray[i].age << "\t";
		cout << "电话：" << abs->personArray[i].phone << "\t";
		cout << "地址：" << abs->personArray[i].address << "\t";
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}
//修改联系人
void alterPerson(addressbooks* abs, string name)
{
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		int i = ret;
		cout << "请输入修改的姓名" << endl;
		cin >> name;
		abs->personArray[i].name = name;

		cout << "请输入修改的性别" << endl;
		int sex = 0;
		cin >> sex;
		abs->personArray[i].sex = sex;

		cout << "请输入修改的年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[i].age = age;

		cout << "请输入修改的电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[i].phone = phone;

		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personArray[i].address = address;
		abs->size++;
		cout << "修改成功" << endl;
	}
	else
		cout << "查无此人删除失败" << endl;
	system("pause");
	system("cls");//清屏操作
}
//清空联系人
void cleanPerson(addressbooks *abs)
{
	abs->size = 0;
	cout << "已清空联系人" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//初始化通讯录
	addressbooks abs;
	abs.size = 0;
	int select = 0;
	string name;
	//循环可以一直显示菜单
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;//1.添加联系人
			system("pause");
			system("cls");
		case 2:
			showPerson(&abs);
			system("pause");
			system("cls");
			break;//2.显示联系人
		case 3:
			cout << "请输入要删除的联系人的姓名" << endl;
			cin >> name;
			deletePerson(&abs, name);
			break;//3.删除联系人
		case 4:
			cout << "请输入要查找的联系人的姓名" << endl;
			cin >> name;
			findPerson(&abs, name);
			break;//4.查找联系人
		case 5:
			cout << "请输入要修改的联系人" << endl;
			cin >> name;
			alterPerson(&abs, name);
			break;//5.修改联系人
		case 6:
			cleanPerson(&abs);
			break;//6.清空联系人
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;// 0.退出通讯录
		default:
			break;

		}
	}
}