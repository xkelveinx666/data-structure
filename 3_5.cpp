#include<iostream>
using namespace std;
#define datatype int
typedef struct node * pointer;
struct node{
	datatype co;
	datatype exp;
	pointer next;
};
typedef pointer lklist;
lklist create(){
	pointer head,p,s;
	datatype x;
	head = new node;
	p = head;
	p -> co = NULL;
	p -> exp = NULL;
	cout<<"请输入系数"<<endl;
	cin>>x;
	while(x != -10){
		s = new node;
		s -> co = x;
		cout<<"请输入指数"<<endl;
			cin >> x;
		if(x == -10){
			break;
		}
		s -> exp = x;
		p -> next = s;
		p = s;
		cout<<"请输入系数"<<endl;
		cin>>x;
	}
	p -> next = head;
	return head;
}
int length(lklist L) {
	int i = 0;
	pointer p = L;
	while(p ->next != L){
		p = p -> next;
		i++;
	}
	return i;
}
pointer locate(lklist L, datatype exp){
	pointer p = L -> next;
	while(p->next != L){
		if(p -> exp == exp)
			return p;
		p = p->next;
	}
	return NULL;
}
void unitPrint(datatype co,datatype exp,bool isfirst){
	if(co == 0)
		return;
	else if(exp == 0){
		cout<<co;
		return;
	}
	else{
		if(co > 0 && !isfirst){
			cout<<"+";
		}
		cout<<co;
		cout<<"x^";
		cout<<exp;	
	}
	return;
}
void print(lklist L){
	if(length(L) == 0)
		return;
	pointer p;
	if(L -> co == NULL)
		p = L -> next;
	else
		p = L;
	unitPrint(p -> co, p -> exp,true);
	p = p -> next;
	while(p != L){
		unitPrint(p -> co, p -> exp,false);
		p = p -> next;
	}
	cout<<endl;
}
pointer getLast(pointer p){
	pointer q = p;
	while(q -> next != p){
		q = q->next;
	}
	return q;
}
void deleteNode(pointer p){
	pointer q = getLast(p);
	q -> next = p -> next;
	delete p; 			
}
void insert(datatype co, datatype exp,pointer q){
	pointer s = new node();
	s -> co = co;
	s -> exp = exp;
	pointer p = getLast(q);
	s -> next = q;
	p -> next = s;
}
void sort(lklist L){
	if(length(L) == 0)
		return;
	pointer p, q, s, k;
	p = L -> next;
	while(p != L){
		s = locate(p, p -> exp);
		if(s == NULL){
			p = p -> next;
		}
		else{
			p -> co += s -> co;
			deleteNode(s);
		}
	}
}
void calculate(lklist L1,lklist L2){
	if(length(L1) == 0 && length(L2) == 0)
		return;
	pointer p, q, s, k;
	p = L1 -> next;
	while(p != L1){
		s = locate(L2, p -> exp);
		if(s == NULL){
			s = L2 -> next;
			insert(s ->co, s ->exp, p);
		}
		else{
			p -> co += s -> co;
		}
		deleteNode(s);
		p = p -> next;
	}
}
int main(void){
	cout<<"请输入第一个多项式"<<endl; 
	lklist L1 = create();
	cout<<"第一个多项式"<<endl; 
	print(L1);
	sort(L1);
	cout<<"整理第一个多项式"<<endl; 
	print(L1);
	cout<<"请输入第二个多项式"<<endl;
	lklist L2 = create();
	cout<<"第二个多项式"<<endl;
	print(L2);
	sort(L2);
	cout<<"整理第二个多项式"<<endl; 
	print(L2);
	calculate(L1,L2);
	cout<<"多项式相加"<<endl;
	print(L1);
} 
