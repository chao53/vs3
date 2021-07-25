#pragma once
using namespace std;

class ListNode {
	friend class LinkList;
public:
	double coef = 0.0;  //系数
	int expo = 0;     //指数
	ListNode* next = nullptr;   //指向下一个（指针）


	ListNode() {};
	ListNode(const int& item1, const int& item2) {
		coef = item1;
		expo = item2;
	}; //构造函数
	~ListNode() {};                //析构函数
};

class LinkList {
public:
	ListNode* first = nullptr, * last = nullptr;
	//LinkList();
	//~LinkList();
	//void MakeEmpty();
	ListNode* getFirst() {return first;};

	//ListNode* getNode(const int& item, ListNode* next);  //获得结点
	void CreateList(int n);    //创建链表
	static void AddPoly(const LinkList &l1, const LinkList &l2);  //多项式相加  //const引用类型  只读不写
	static void SubPoly(const LinkList& l1,const LinkList& l2);  //多项式相减
	static void MulPoly(const LinkList& l1, const LinkList& l2);  //多项式相乘
	static void Sort(const LinkList &l);
};
