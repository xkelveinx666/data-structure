#include<iostream>
using namespace std;
#define datatype char
typedef struct node * pointer;
struct node{
	datatype data;
	pointer next;
};
typedef pointer lklist;
int length(lklist L) {
	int i = 0;
	pointer p = L;
	while(p != NULL){
		p = p->next;
		i++;
	}
	return --i;
}
void print(lklist L){
	if(length(L) == 0)
		return;
	pointer p;
	if(L -> data == NULL)
		p = L -> next;
	else
		p = L;
	if(p != NULL){
		cout<<p -> data;
		p = p -> next;
	}
	while(p != NULL){
		cout<<"->";
		cout<<p -> data;
		p = p -> next;
	}
	cout<<endl;
}
lklist initiateRear(){
	pointer head,p,s;
	datatype x;
	head = new node;
	p = head;
	p -> data = NULL;
	cin>>x;
	while(x != '$'){
		getchar();
		s = new node;
		s -> data = x;
		p -> next = s;
		p = s;
		cin>>x;
	}
	p -> next = NULL;
	return head;
}
lklist initiateHead(){
	pointer head,p,s;
	datatype x;
	head = new node;
	head -> data = NULL;
	head -> next = NULL;
	cin>>x;
	while(x != '$'){
		getchar();
		s = new node;
		s -> data = x;
		s -> next = head->next;
		head -> next = s;
		p = s;
		cin>>x;
	}
	return head;
}
lklist inverse(lklist l1){
	pointer head,p,s,q;
	datatype x;
	head = new node;
	head -> data = NULL;
	head -> next = NULL;
	q = l1 -> next;
	while(q != NULL){
		x = q -> data;
		s = new node;
		s -> data = x;
		s -> next = head->next;
		head -> next = s;
		p = s;
		q = q -> next;
	}
	return head;
}
int main(void){
	lklist l1 = initiateRear();
	lklist l2 = inverse(l1);
	print(l1);
	print(l2);
	return 0;
} 
