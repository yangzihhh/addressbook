#include <iostream>
using namespace std;
#include<string>
#define max 100
//��ӡ�˵�
void showmenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
};
//������ϵ�˽ṹ��
struct person {
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
//����ͨѶ¼�ṹ��
struct addressbooks 
{
	struct person personArray[max];
	int size;
};

//�����ϵ��
void addPerson(addressbooks* abs)
{
	if (abs->size == max)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "����������" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->size].name = name;

		cout << "�������Ա�" << endl;
		int sex = 0;
		cin >> sex;
		abs->personArray[abs->size].sex = sex;

		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;
		 
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].address = address;
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}
}
//��ʾ��ϵ��
void showPerson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼��û����ϵ��" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personArray[i].name << "\t";
			cout << "�Ա�" << abs->personArray[i].sex << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t";
			cout << "��ַ��" << abs->personArray[i].address << "\t";
		}
	}
};

//������ϵ�����򷵻���ϵ�˵������±����򷵻�-1
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
//ɾ����ϵ��
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;

	system("pause");
	system("cls");
}
//������ϵ����Ϣ
void findPerson(addressbooks* abs, string name)
{
	int ret=isExit(abs, name);
	if (ret != -1)
	{
		int i = ret;
		cout << "������" << abs->personArray[i].name << "\t";
		cout << "�Ա�" << abs->personArray[i].sex << "\t";
		cout << "���䣺" << abs->personArray[i].age << "\t";
		cout << "�绰��" << abs->personArray[i].phone << "\t";
		cout << "��ַ��" << abs->personArray[i].address << "\t";
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}
//�޸���ϵ��
void alterPerson(addressbooks* abs, string name)
{
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		int i = ret;
		cout << "�������޸ĵ�����" << endl;
		cin >> name;
		abs->personArray[i].name = name;

		cout << "�������޸ĵ��Ա�" << endl;
		int sex = 0;
		cin >> sex;
		abs->personArray[i].sex = sex;

		cout << "�������޸ĵ�����" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[i].age = age;

		cout << "�������޸ĵĵ绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[i].phone = phone;

		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[i].address = address;
		abs->size++;
		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "���޴���ɾ��ʧ��" << endl;
	system("pause");
	system("cls");//��������
}
//�����ϵ��
void cleanPerson(addressbooks *abs)
{
	abs->size = 0;
	cout << "�������ϵ��" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//��ʼ��ͨѶ¼
	addressbooks abs;
	abs.size = 0;
	int select = 0;
	string name;
	//ѭ������һֱ��ʾ�˵�
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;//1.�����ϵ��
			system("pause");
			system("cls");
		case 2:
			showPerson(&abs);
			system("pause");
			system("cls");
			break;//2.��ʾ��ϵ��
		case 3:
			cout << "������Ҫɾ������ϵ�˵�����" << endl;
			cin >> name;
			deletePerson(&abs, name);
			break;//3.ɾ����ϵ��
		case 4:
			cout << "������Ҫ���ҵ���ϵ�˵�����" << endl;
			cin >> name;
			findPerson(&abs, name);
			break;//4.������ϵ��
		case 5:
			cout << "������Ҫ�޸ĵ���ϵ��" << endl;
			cin >> name;
			alterPerson(&abs, name);
			break;//5.�޸���ϵ��
		case 6:
			cleanPerson(&abs);
			break;//6.�����ϵ��
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;// 0.�˳�ͨѶ¼
		default:
			break;

		}
	}
}