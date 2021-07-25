//作者:陈炜潮
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
	//建立邻接表************************************************************************************
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
			while (p->nextNode != NULL)//查找nodeTable里是否已有该节点
			{
				if (p->nextNode->body == ch1) {//若已有添加有向弧
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
			if (m1 == 0) {//若无节点1，进行添加，并添加弧
				Node* newNode = new Node;
				newNode->body = ch1;
				newNode->firstArc = newArc;
				p->nextNode = newNode;
				p = p->nextNode;
				NodeNum++;
			}
			if (m2 == 0) {//若无节点2，进行添加
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
		getchar();//把'\n'搞掉
	}

	//Dijkstra算法************************************************************************************
	char start;
	char destination;
	cin >> start;
	cin >> destination;
	
	if (headNode->nextNode != NULL) {
		Node* Np = headNode->nextNode;
		string* path = new string[NodeNum];//记录每个节点路径的字符串数组
		int _count = 0;
		int sta = -1;
		int des = -1;
		Node* Sp = NULL;
		map<char, int> M;//用地图给节点编号
		int* F = new int[NodeNum];
		while (Np != NULL)
		{
			M[Np->body] = _count;
			path[_count] += start;//在路径上添加起点
			F[_count] = INT_MAX;
			if (Np->body == start) {//定位到起点
				Sp = Np;
				sta = _count;
			}
			else {
				path[_count] += " ";
				path[_count] += Np->body;//在路径上添加终点
			}
			if (Np->body == destination) {//定位到终点
				des = _count;
			}
			Np = Np->nextNode;
			_count++;
		}
		F[sta] = 0;
		
		int* rSet = new int[NodeNum];//rSet储存已添加的节点
		for (int rank = 0;rank < NodeNum;rank++) {//rank:遍历添加进度
			//寻找下一个最近节点
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

			//更新最短路径
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