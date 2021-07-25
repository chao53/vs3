//����:��쿳�
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

struct Arc
{
	char v1 = NULL;
	char v2 = NULL;
	int weight1 = NULL;
	int weight2 = NULL;
	Arc* next = NULL;
};

struct Node
{
	char body = NULL;
	Arc* firstArc = NULL;
	Node* nextNode = NULL;
};

int main() {
	//�����ڽӱ�************************************************************************************
	Node* headNode = new Node;
	int NodeNum = 0;
	char ch1;
	while (true)
	{
		
		ch1 = getchar();
		if (ch1 != ' ') {
			char ch2;
			int weight1;
			int weight2;
			cin >> ch2;
			cin >> weight1;
			cin >> weight2;
			Arc* newArc = new Arc;
			newArc->v1 = ch1;
			newArc->v2 = ch2;
			newArc->weight1 = weight1;
			newArc->weight2 = weight2;

			int m1 = 0;
			int m2 = 0;

			Node* p = headNode;
			while (p->nextNode != NULL)//����nodeTable���Ƿ����иýڵ�
			{
				if (p->nextNode->body == ch1) {//�������������
					newArc->next = p->nextNode->firstArc;
					p->nextNode->firstArc = newArc;
					m1 = 1;
				}
				else if (p->nextNode->body == ch2) {
					m2 = 1;
				}
				if (m1 == 1 && m2 == 1) {
					break;
				}
				p = p->nextNode;
			}
			if (m1 == 0) {//���޽ڵ�1��������ӣ�����ӻ�
				Node* newNode = new Node;
				newNode->body = ch1;
				newNode->firstArc = newArc;
				p->nextNode = newNode;
				p = p->nextNode;
				NodeNum++;
			}
			if (m2 == 0) {//���޽ڵ�2���������
				Node* newNode = new Node;
				newNode->body = ch2;
				p->nextNode = newNode;
				p = p->nextNode;
				NodeNum++;
			}
		}
		else
		{
			break;
		}
		getchar();//��'\n'���
	}

	//Dijkstra�㷨************************************************************************************
	char start;
	char destination;
	cin >> start;
	cin >> destination;
	
	if (headNode->nextNode != NULL) {
		Node* Np = headNode->nextNode;
		string* path = new string[NodeNum];//��¼ÿ���ڵ�·�����ַ�������
		int _count = 0;
		int sta = -1;
		int des = -1;
		Node* Sp = NULL;
		map<char, int> M;//�õ�ͼ���ڵ���
		int* F = new int[NodeNum];
		while (Np != NULL)
		{
			M[Np->body] = _count;
			path[_count] += start;//��·����������
			F[_count] = INT_MAX;
			if (Np->body == start) {//��λ�����
				Sp = Np;
				sta = _count;
			}
			else {
				path[_count] += " ";
				path[_count] += Np->body;//��·��������յ�
			}
			if (Np->body == destination) {//��λ���յ�
				des = _count;
			}
			Np = Np->nextNode;
			_count++;
		}
		F[sta] = 0;
		
		int* rSet = new int[NodeNum];//rSet��������ӵĽڵ�
		for (int rank = 0;rank < NodeNum;rank++) {//rank:������ӽ���
			//Ѱ����һ������ڵ�
			int keep = -1;
			int record = INT_MAX;
			for (int i = 0; i < NodeNum;i++) {
				bool mark = false;
				for (int j = 0;j < rank;j++) {
					if (i == rSet[j]) {
						mark = true;
						break;
					}
				}
				if (mark) {
					continue;
				}
				if (F[i] < record) {
					keep = i;
					record = F[i];
				}
			}
			rSet[rank] = keep;

			//�������·��
			Np = headNode->nextNode;
			for (int j = 0;j < keep;j++) {
				Np = Np->nextNode;
			}
			Arc* Ap = Np->firstArc;
			while (Ap != NULL)
			{
				if (F[M[Ap->v2]] > F[keep] + Ap->weight1) {
					F[M[Ap->v2]] = F[keep] + Ap->weight1;
					path[M[Ap->v2]] = path[keep] + " ";
					path[M[Ap->v2]] += Ap->v2;
				}
				Ap = Ap->next; 
			}
		}
		cout << path[des] << endl;
		cout << F[des] << endl;
	}
}