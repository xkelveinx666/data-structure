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
pointer get(lklist L, int i){
	pointer p = L;
	int j = 0;
	if(i < 0 || length(L) < i)
		return NULL;
	while(p != NULL){
		if(i == j++)
			return p;
		p = p -> next;
	}
	return NULL;
}
pointer locate(lklist L, datatype x){
	pointer p = L -> next;
	while(p != NULL){
		if(p -> data == x)
			return p;
		p = p->next;
	}
	return NULL;
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
void insert(lklist L, datatype x, int i){
	int len = length(L);
	if(len < i - 1 || i < 0)
		return;
	pointer s = new node();
	s -> data = x;
	pointer p = get(L,i - 1);
	if(len != i - 1){
		pointer q = p ->next;
		s -> next = q;
	}
	else
		s -> next = NULL;
	p -> next = s;
}
void deleteNode(lklist L,int i){
	int len = length(L);
	if(i < 0 || len < i)
		return;
	pointer p = get(L, i - 1);
	if(len != i){
		pointer q = p -> next;
		p -> next = q -> next;
		delete q; 		
	}
	else{
		delete p->next;
		p ->next = NULL;
	}	
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
int main(void){
	lklist l = initiateRear();
	print(l);
	int len = length(l);
	cout<<len<<endl;
	if(len > 3)
		print(get(l ,3));
	pointer p ;
	if((p = locate(l, '0')) != NULL)
		print(p);
	insert(l,'T', 4);
	print(l);
	deleteNode(l ,4);
	print(l);
	return 0;
} 
