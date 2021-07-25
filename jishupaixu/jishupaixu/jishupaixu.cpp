//作者:陈炜潮
#include <iostream>
#include <ctime>
using namespace std;

struct node
{
	int body;
	node* next = NULL;
};

int main() {
	int num;
	int figures;
	cin >> num;
	cin >> figures;

	unsigned seed;
	seed = time(0);
	srand(seed);

	int maxNum = 1;
	for (int i = 0; i < figures;i++) {
		maxNum *= 10;
	}

	node* headNode = new node;
	node* p = headNode;
	for (int i = 0;i < num;i++) {//生成数据
		node* newNode = new node;
		newNode->body = rand() % maxNum;
		p->next = newNode;
		p = p->next;
	}
	int place = 1;//place表示位数
	for (int i = 0; i < figures;i++) {
		p = headNode->next;
		node** GheadNode1 = new node * [10];//10组链表
		node** Gp1 = new node * [10];//指向十组链表尾节点的指针
		for (int i = 0;i < 10;i++) {
			GheadNode1[i] = new node;
			Gp1[i] = GheadNode1[i];
		}
		while (p != NULL) {
			node* newNode = new node;
			newNode->body = p->body;
			int group = (p->body % (10*place))/place;//分组
			Gp1[group]->next = newNode;
			Gp1[group] = Gp1[group]->next;
			p = p->next;
		}
		p = headNode;
		for (int group = 0;group < 10;group++) {//把十组链表的值按顺序重新加到主链表上
			Gp1[group] = GheadNode1[group];
			while (true)
			{
				Gp1[group] = Gp1[group]->next;
				if (Gp1[group] == NULL) {
					break;
				}
				node* newNode = new node;
				newNode->body = Gp1[group]->body;
				p->next = newNode;
				p = p->next;
			}
			delete GheadNode1[group];//释放空间
		}
		place *= 10;
	}

	int judge = 1;
	p = headNode->next;
	for (int i = 0;i < num - 1;i++) {
		if (p->body > p->next->body) {
			judge = 0;
		}
		p = p->next;
	}
	if (judge == 1) {
		cout << "是"<<endl;
	}
	else
	{
		cout << "否"<<endl;
	}

}
