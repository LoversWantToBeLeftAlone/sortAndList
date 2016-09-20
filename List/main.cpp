#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};
node *recursive(node*head){
	if(head==NULL || head->link==NULL)
		return head;
	node*p1=head;
	node*p2=p1->next;
	head=recursive(p2);
	p2->link=p1;
	p1->link=NULL;
}

node*reserve(node*head){
	if(head==NULL ||head->link=NULL)
		return head;
	node *p1=head;
	node *p2=p1->link;
	node *p3=p2->link;
	p1->link=NULL;
	while(p3!=NULL){
		p2->link=p1;
		p1=p2;
		p2=p3;
		p3=p3->link;
	}
	p2->link=p1;
	head=p2;
	return p2;
}

node *mergeLink(node*head1,node*head2){
	node *temp=NULL;
	if(head1==NULL &&head2=NULL)
		return temp;
	else if(head1==NULL)
		return head2;
	else if(head2==NULL)
		return head1;
	else{
		if(head1->data>head2->data){
			temp=head1;
			temp->link=mergeLink(head1->link,head2);
		}
		else{
			temp=head2;
			temp->link=mergeLink(head1,head2->link);
		}
	}
	return temp;
}
