#pragma once
using namespace std;

class ListNode {
	friend class LinkList;
public:
	double coef = 0.0;  //ϵ��
	int expo = 0;     //ָ��
	ListNode* next = nullptr;   //ָ����һ����ָ�룩


	ListNode() {};
	ListNode(const int& item1, const int& item2) {
		coef = item1;
		expo = item2;
	}; //���캯��
	~ListNode() {};                //��������
};

class LinkList {
public:
	ListNode* first = nullptr, * last = nullptr;
	//LinkList();
	//~LinkList();
	//void MakeEmpty();
	ListNode* getFirst() {return first;};

	//ListNode* getNode(const int& item, ListNode* next);  //��ý��
	void CreateList(int n);    //��������
	static void AddPoly(const LinkList &l1, const LinkList &l2);  //����ʽ���  //const��������  ֻ����д
	static void SubPoly(const LinkList& l1,const LinkList& l2);  //����ʽ���
	static void MulPoly(const LinkList& l1, const LinkList& l2);  //����ʽ���
	static void Sort(const LinkList &l);
};
