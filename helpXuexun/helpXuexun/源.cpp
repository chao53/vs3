#include<iostream>
using namespace std;



template<class T1, class T2>
class My_array
{
public:

	My_array(int Capacity, T2 array[])
	{
		this->M_Capacity = Capacity;
		this->M_amount = sizeof(array) / sizeof(array[0]);
		this->M_array = *new T1;
		for (int i = 0; i < M_amount; i++)
		{
			M_array[i] = new T2(array[i]);
		}
	}
	
	My_array& operator=(My_array<T1, T2>& a)
	{
		for (int i = 0; i < a.M_amount; i++)
		{
			this->M_array[i] = new T2(*a.M_array[i]);
		}

	}

	void Delete(T2 d)
	{

	}

	void Add(T2 a, int n)
	{
		if (M_amount >= M_Capacity)
		{
			cout << "空间已满，无法添加" << endl;
		}
		else
		{
			for (int i = M_amount; i >= n - 1; i--)
			{
				this->M_array[i] = new T2(this->*M_array[i - 1]);
				delete M_array[i - 1];
			}

			delete M_amount[n - 1];
			this->M_array[n - 1] = new T2(a);

		}

	}


	int M_Capacity;
	int M_amount;
	T1 M_array;


};

void test01()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int capacity = 100;
	My_array<int**, int> m(100, a);
	cout << m.M_array[1][1] << endl;

}


int main()
{

	test01();



	return 0;
}