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
lklist rankCombine(lklist l1,lklist l2){
	pointer p,q,head;
	head = new node;
	head->data = NULL;
	head->next = NULL;
	p = l1 -> next;
	q = l2 -> next;
	while(q != NULL && p != NULL){
		if(p->data < q->data){
			insert(head,p->data,1);
			p = p->next;
		}
		else{
			insert(head,q->data,1);
			q = q->next;	
		}
	}
	if(q == NULL && p == NULL)
		return head;
	else if(q != NULL){
		while(q != NULL){
			insert(head,q->data,1);
			q = q -> next;
		}	
	}
	else{
		while(p != NULL){
			insert(head,p->data,1);
			p = p -> next;
		}
	}
	return inverse(head);
}
int main(void){
	lklist l1 = initiateRear();
	lklist l2 = initiateRear();
	print(l1);
	print(l2);
	lklist l3 = rankCombine(l1, l2);
	print(l3);
	return 0;
} 
