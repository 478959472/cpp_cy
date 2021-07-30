#include<iostream>
using namespace std;

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}


#include <string>
//联系人结构体
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

//通讯录结构体

#define MAX 1000

struct Addressbooks
{
	struct  Person personArray[MAX];
	int m_size;
};

//1、添加联系人信息

void addPerson(Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		abs->m_size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "住址：" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");

}

//判断是否存在查询的人员，存在返回在数组中的索引位置，不存在返回-1
int isExist(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//4、查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_name << "\t";
		cout << "性别：" << abs->personArray[ret].m_sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_age << "\t";
		cout << "电话：" << abs->personArray[ret].m_phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//5、修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//6、清空所有联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}



int main() {

	//创建通讯录
	Addressbooks abs;
	abs.m_size = 0;

	int select = 0;
	while (true) 
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs);
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3:  //删除联系人
			deletePerson(&abs);
			break;
		case 4:  //查找联系人
			findPerson(&abs);
			break;
		case 5:  //修改联系人
			modifyPerson(&abs);
			break;
		case 6:  //清空联系人
			cleanPerson(&abs);
			break;
		case 0:  //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;

}