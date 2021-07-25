//作者:陈炜潮
#include <iostream>

using namespace std;

struct node
{
	float ai;
	float ei;
	node* next = NULL;
};

int main()
{
	int num1;
	cin >> num1;
	node* headNode1 = new node;
	node* p = headNode1;
	for (int i = 0;i < num1;i++) {
		node* newNode = new node;
		cin >> newNode->ai;
		cin >> newNode->ei;
		p->next = newNode;
		p = p->next;
	}

	int num2;
	cin >> num2;
	node* headNode2 = new node;
	p = headNode2;
	for (int i = 0;i < num2;i++) {
		node* newNode = new node;
		cin >> newNode->ai;
		cin >> newNode->ei;
		p->next = newNode;
		p = p->next;
	}

	char op;
	cin >> op;

	node* headNode3 = new node;
	node* p3 = headNode3;
	node* p1 = headNode1->next;
	node* p2 = headNode2->next;

	if (op == '+' || op == '-') {

		/*加法,headNode3储存加法结果的链表头结点。
			判断两链表每项的指数的大小，若相同，
			就系数相加并插入新链表，若不同就将
			较小的插入新链表。插入时要把系数为0的项剔除。*/
		int m = 1;
		if (op == '-') {
			m = -1;
		}
		while (true) {
			node* newNode = new node;
			if (p1 == NULL && p2 == NULL) {
				break;
			}
			else if (p1 == NULL) {
				newNode->ai = p2->ai*m;
				newNode->ei = p2->ei;
				p3->next = newNode;
				p2 = p2->next;
				p3 = p3->next;
			}
			else if (p2 == NULL || p1->ei < p2->ei) {
				newNode->ai = p1->ai;
				newNode->ei = p1->ei;
				p3->next = newNode;
				p1 = p1->next;
				p3 = p3->next;
			}
			else if (p1->ei > p2->ei) {
				newNode->ai = p2->ai*m;
				newNode->ei = p2->ei;
				p3->next = newNode;
				p2 = p2->next;
				p3 = p3->next;
			}
			else if (p1->ei == p2->ei)
			{
				newNode->ai = p1->ai + p2->ai*m;
				if (newNode->ai == 0) {
					p1 = p1->next;
					p2 = p2->next;
					continue;
				}
				newNode->ei = p1->ei;
				p3->next = newNode;
				p1 = p1->next;
				p2 = p2->next;
				p3 = p3->next;
			}
			if (p1 == NULL && p2 == NULL) {
				break;
			}
		}
	}
	else if (op == '*') {
		/*乘法,headNode3储存乘法结果的链表头结点。
		嵌套两个for循环，用一个链表的每个项遍历相
		乘另一个链表的每个项，再按顺序插入新链
		表中，若已有相同指数项，就把相应系数相加。*/
		for (int i = 0;i < num1;i++) {
			p2 = headNode2->next;
			for (int j = 0;j < num2;j++) {
				node* newNode = new node;
				newNode->ai = p1->ai * p2->ai;
				newNode->ei = p1->ei + p2->ei;
				p3 = headNode3;
				while (true)
				{
					if (p3->next == NULL) {
						p3->next = newNode;
						p3 = p3->next;
						break;
					}
					else if (p3->ei == newNode->ei) {
						p3->ai += newNode->ai;
						break;
					}
					else if (p3->next->ei > newNode->ei) {
						newNode->next = p3->next;
						p3->next = newNode;
						break;
					}
					p3 = p3->next;
				}
				p2 = p2->next;
			}
			p1 = p1->next;
		}
	}
	//输出
	p = headNode3->next;
	cout << endl;
	while (p != NULL) {
		if (p->ai != 0) {
			cout << p->ai << " " << p->ei << " ";
		}
		p = p->next;
	}
}
