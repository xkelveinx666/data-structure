#include<iostream>
using namespace std;
#define datatype int
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
void insertOrder(lklist L, datatype x){
	pointer s = new node();
	pointer p = L -> next;
	while(p -> next != NULL){
		if(p -> data >= x){
			break;
		}
		p = p -> next;
	}	
	if(p -> next != NULL){
		s -> next = p -> next;
		s -> data = p -> data;
		p -> data = x;
	}
	else
		s -> data = x;
	p -> next = s;
}
void insertHead(lklist L, datatype x){
	pointer s = new node;
	s -> data = x; 
	if(L -> next != NULL){
		pointer q = L -> next;
		s -> next = q;
	}
	L -> next = s;
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
lklist sort(lklist l){
	pointer head = new node;
	head -> data = NULL;
	head -> next = NULL;
	pointer p;
	datatype x;
	int i ,j;
	while(length(l) > 0){
		i = 0;
		p = l -> next;
		x = p -> data;
		j = 1;
		while(p -> next != NULL){
			i++;
			if(p -> next -> data >= x){
				x = p -> next -> data;
				j = i + 1;
			}
			p = p -> next;
		}	
		insertHead(head, x);
		deleteNode(l, j);
	}
	return head;
}
lklist initiateRear(){
	pointer head,p,s;
	datatype x;
	head = new node;
	p = head;
	p -> data = NULL;
	cin>>x;
	while(x != -10){
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
	while(x != -10){
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
	cout<<"请输入一组数据，可无序"<<endl;
	lklist l = initiateRear();
	print(l);
	cout<<"排序中"<<endl;
	l = sort(l);
	print(l);
	cout<<"插入一个元素值为x的结点，本程序能使插入后链表仍然有序"<<endl;
	datatype x;
	cin>>x;
	insertOrder(l, x);
	print(l);
	return 0;
} 
