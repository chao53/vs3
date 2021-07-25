#pragma once
#include "LinkList.h"
#include<iostream>

using namespace std;

//next�洢��ַ

//LinkList::~LinkList() {
//	MakeEmpty();
//	delete first;
//}
void LinkList::CreateList(int n) {
	first = new ListNode();
	last = first;

	double coef = 0.0;
	int expo = 0;

	for (size_t i = 0; i < n; i++) {
		cout << "�����" << i + 1 << "��ϵ����ָ��" << endl;
		cin >> coef >> expo;
		ListNode* t = new ListNode;
		last->next = t;
		t->coef = coef;
		t->expo = expo;
		last = t;
	}
	last->next = NULL;
	//shift+alt
	ListNode* a = first, * b = first->next->next;

	for (size_t i = 0; i < n - 1; i++) {
		a = first, b = first->next->next;
		for (size_t j = 0; j < n - i - 1; j++) {
			if (a->next->expo > b->expo) {
				a->next->next = b->next;
				b->next = a->next;
				a->next = b;
				a = a->next;
				b = b->next->next;
			}
		}
	}

	ListNode* g = first->next;
	for (size_t i = 0; i < n; i++) {
		cout << g->coef << g->expo << endl;
		g = g->next;
	}
}

void LinkList::AddPoly(const LinkList& l1, const LinkList& l2) {

	ListNode* a = l1.first->next;  //��λ
	ListNode* b = l2.first->next;  //��λ


	ListNode* first, * last;
	first = new ListNode;

	last = first;
	while (a != nullptr || b != nullptr)
	{
		ListNode* l = new ListNode;

		if (a != nullptr && b != nullptr) {
			if (a->expo == b->expo) {
				last->next = l;
				l->coef = a->coef + b->coef;
				l->expo = a->expo;
				last->next = l;
				last = l;
				a = a->next;
				b = b->next;
				continue;
			}
		}

		if (a != nullptr && b != nullptr) {
			if (a->expo < b->expo) {
				last->next = l;
				last = l;
				l->coef = a->coef;
				l->expo = a->expo;

				a = a->next;
				continue;
			}

		}


		if (a != nullptr && b != nullptr) {
			if (a->expo > b->expo) {
				last->next = l;
				last = l;
				l->coef = b->coef;
				l->expo = b->expo;

				b = b->next;
				continue;
			}

		}
		if (a == nullptr && b != nullptr) {
			last->next = l;
			last = l;
			l->coef = b->coef;
			l->expo = b->expo;

			b = b->next;
			continue;
		}
		if (a != nullptr && b == nullptr) {
			last->next = l;
			last = l;
			l->coef = a->coef;
			l->expo = a->expo;

			a = a->next;
			continue;
		}
		



	}
	ListNode* g = first->next;
	while (g != nullptr) {
		cout << g->coef << g->expo << endl;
		g = g->next;
	}



}

void LinkList::SubPoly(const LinkList& l1, const LinkList& l2) {

	ListNode* a = l1.first->next;  //��λ
	ListNode* b = l2.first->next;  //��λ


	ListNode* first, * last;
	first = new ListNode;

	last = first;
	while (a != nullptr || b != nullptr)
	{
		ListNode* l = new ListNode;

		if (a != nullptr && b != nullptr) {
			if (a->expo == b->expo) {
				last->next = l;
				l->coef = a->coef - b->coef;
				l->expo = a->expo;
				last->next = l;
				last = l;
				a = a->next;
				b = b->next;
				continue;
			}
		}

		if (a != nullptr && b != nullptr) {
			if (a->expo < b->expo) {
				last->next = l;
				last = l;
				l->coef = a->coef;
				l->expo = a->expo;

				a = a->next;
				continue;
			}

		}


		if (a != nullptr && b != nullptr) {
			if (a->expo > b->expo) {
				last->next = l;
				last = l;
				l->coef = -b->coef;
				l->expo = b->expo;

				b = b->next;
				continue;
			}

		}
		if (a == nullptr && b != nullptr) {
			last->next = l;
			last = l;
			l->coef = -b->coef;
			l->expo = b->expo;

			b = b->next;
			continue;
		}
		if (a != nullptr && b == nullptr) {
			last->next = l;
			last = l;
			l->coef = a->coef;
			l->expo = a->expo;

			a = a->next;
			continue;
		}




	}
	ListNode* g = first->next;
	while (g != nullptr) {
		if (g->coef == 0) {
			g = g->next;
			continue;
		}
		cout << g->coef << g->expo << endl;
		g = g->next;
	}



}

void sort(ListNode* l) {
	ListNode* a = l; //��λ
	ListNode* b = l->next;  //��λ
	ListNode* c = l;


	ListNode* first, * last;
	first = new ListNode;

	last = first;

	while (a != nullptr && b != nullptr)
	{
		ListNode* l = new ListNode;
		if (b == nullptr && a != nullptr) {
			a = a->next;
			b = a->next;
			c = a;
		}
		else if (a == nullptr) {
			break;
		}
		else if (a->expo == b->expo) {
			a->coef = a->coef + b->coef;
			c->next = b->next;
			delete b;
			b = c->next;
		}
		else {
			b = b->next;
		}

	}




}

void LinkList::MulPoly(const LinkList& l1, const LinkList& l2) {

	ListNode* a = l1.first->next;  //��λ
	ListNode* b = l2.first->next;  //��λ


	ListNode* first, * last;
	first = new ListNode;

	last = first;
	
	while (a != nullptr)
	{
		ListNode* l = new ListNode;
		if (b == nullptr && a != nullptr) {
			a = a->next;
			b = l2.first->next;
		}
		else if (a!=nullptr && b != nullptr) {
			last->next = l;
			last = l;
			l->coef = a->coef * b->coef;
			l->expo = a->expo + b->expo;
			b = b->next;
		}
	 
	}

	sort(first);
	ListNode* g = first->next;
	
	while (g != nullptr) {
		cout << g->coef << g->expo << endl;
		g = g->next;
	}



}

