#include"LinkList.h"
#include<iostream>

using namespace std;

int main() {
	
	int n;
	int m;
	cout << "�������һ������ʽ����������Լ����ǵ�ϵ����ָ����";
	cin >> n;
	LinkList l1;
	LinkList l2;

	l1.CreateList(n);

	cout << "������ڶ�������ʽ����������Լ����ǵ�ϵ����ָ����";
	cin >> m;

	l2.CreateList(m);

    string flag;
	cin >> flag;

	if (flag == "+") {
		LinkList::AddPoly(l1, l2);
	}

	if (flag == "-") {
		LinkList::SubPoly(l1, l2);
	}
	if (flag == "*") {
		LinkList::MulPoly(l1, l2);
		
	}
	
}
