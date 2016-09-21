#include<iostream>
using namespace std;

template<class T>
struct ListNode              //�ڵ�����ݽṹ
{
	T data;
	ListNode* next;
	ListNode(){next=NULL;}
	ListNode(T data1,ListNode<T>* next1=NULL)
	{
		data=data1;
		next=next1;
	}
};

template<class T>
class A
{
public:
	ListNode<T>* head;
	A();
	//~A();
	//void search();
	void add(T data);
	ListNode<T>* ReverseList(ListNode<T>* head);
};

template<class T>
A<T>::A()
{
	this->head=NULL;
}

template<class T>
void A<T>::add(T data)         //��ӽڵ�
{
	ListNode<T> *newNode=NULL;
	if(head==NULL)
	{	
		newNode=new ListNode<T>(data,head);
		head=newNode;
	}
	else
	{
		ListNode<T> *ptr1=head;

		while(ptr1->next!=NULL)
		{
			ptr1=ptr1->next;
		}       
		newNode=new ListNode<T>(data,ptr1->next);
		ptr1->next=newNode;
	}
}

template<class T>                              //�������ת
ListNode<T>* A<T>::ReverseList(ListNode<T>* head)
{
	ListNode<T>* p = NULL; //ָ����ת�ڵ��ǰһ���ڵ�
	ListNode<T>* r = head; //ָ��ǰ�ڵ�;
	ListNode<T>* q = NULL; //ָ����ת�ڵ����һ���ڵ㣻
	while (r != NULL)
	{
		q = r->next;  //ָ����һ���ڵ�
		r->next = p;  //�������ת����
		p = r;         //��һ�α���
		r = q; //��һ�α���
	}
	return p;
}


int main()
{
	A<int> a;
	a.add(10);
	a.add(20);
	a.add(30);
	a.add(40);
    ListNode<int> *ptr1,*ptr2;
	ptr1=a.head;
	while(ptr1!=NULL)
	{
		cout<<ptr1->data;
		ptr1=ptr1->next;
	}
	cout<<endl;
	a.head=a.ReverseList(a.head);
	ptr2=a.head;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data;
		ptr2=ptr2->next;
	}
	return 0;
}