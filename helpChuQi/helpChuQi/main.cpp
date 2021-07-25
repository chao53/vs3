#include"LinkList.h"
#include<iostream>

using namespace std;

int main() {
	
	int n;
	int m;
	cout << "请输入第一个多项式非零项个数以及他们的系数和指数：";
	cin >> n;
	LinkList l1;
	LinkList l2;

	l1.CreateList(n);

	cout << "请输入第二个多项式非零项个数以及他们的系数和指数：";
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
