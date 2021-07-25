//����:��쿳�
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
	for (int i = 0;i < num;i++) {//��������
		node* newNode = new node;
		newNode->body = rand() % maxNum;
		p->next = newNode;
		p = p->next;
	}
	int place = 1;//place��ʾλ��
	for (int i = 0; i < figures;i++) {
		p = headNode->next;
		node** GheadNode1 = new node * [10];//10������
		node** Gp1 = new node * [10];//ָ��ʮ������β�ڵ��ָ��
		for (int i = 0;i < 10;i++) {
			GheadNode1[i] = new node;
			Gp1[i] = GheadNode1[i];
		}
		while (p != NULL) {
			node* newNode = new node;
			newNode->body = p->body;
			int group = (p->body % (10*place))/place;//����
			Gp1[group]->next = newNode;
			Gp1[group] = Gp1[group]->next;
			p = p->next;
		}
		p = headNode;
		for (int group = 0;group < 10;group++) {//��ʮ�������ֵ��˳�����¼ӵ���������
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
			delete GheadNode1[group];//�ͷſռ�
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
		cout << "��"<<endl;
	}
	else
	{
		cout << "��"<<endl;
	}

}
