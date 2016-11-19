#include<iostream>
using namespace std;
#define datatype char
typedef struct dnode * dpointer;
struct dnode{
	datatype data;
	dpointer prior,next;
};
typedef dpointer dlklist;
int length(dlklist L) {
	int i = 0;
	dpointer p = L;
	while(p -> next != L){
		p = p->next;
		i++;
	}
	return i;
}
dpointer get(dlklist L, int i){
	dpointer p = L;
	int j = 0;
	if(i < 0 || length(L) < i)
		return NULL;
	while(p -> next != L){
		if(i == j++)
			return p;
		p = p -> next;
	}
	return NULL;
}
dpointer locate(dlklist L, datatype x){
	dpointer p = L -> next;
	while(p -> next != L){
		if(p -> data == x)
			return p;
		p = p->next;
	}
	return NULL;
}
void print(dlklist L){
	if(length(L) == 0)
		return;
	dpointer p;
	if(L -> data == NULL)
		p = L -> next;
	else
		p = L;
	if(p -> next != L){
		cout<<p -> data;
		p = p -> next;
	}
	while(p -> next != L){
		cout<<"->";
		cout<<p -> data;
		p = p -> next;
	}
	cout<<"->";
	cout<<p -> data;
	cout<<endl;
}
void insert(dlklist L, datatype x, int i){
	int len = length(L);
	if(len < i - 1 || i < 0)
		return;
	dpointer s = new dnode();
	s -> data = x;
	dpointer p = get(L,i - 1);
	if(len != i - 1){
		dpointer q = p ->next;
		s -> next = q;
	}
	else
		s -> next = NULL;
	p -> next = s;
}
void deleteNode(dlklist L,int i){
	int len = length(L);
	if(i < 0 || len < i)
		return;
	dpointer p = get(L, i - 1);
	if(len != i){		
		dpointer q = p -> next;	
		q -> next -> prior = p;	
		p -> next = q -> next;
		delete q; 		
	}
	else{
		delete p->next;
		p ->next = L;
		L -> prior = p;
	}	
}
dlklist initiate(){
	dlklist l = new dnode();
	dpointer q = l;
	datatype x;
	cin>>x;
	while(x != '$'){
		dpointer p = new dnode();	
		p -> data = x;
		q -> next = p;
		p -> prior = q;
		q = p;
		cin>>x;
	}
	q -> next = l;
	l -> prior = q;
	return l;
}
int main(void){
	cout<<"����˫������\'$\'����"<<endl;
	dlklist l = initiate();
	print(l);
	cout<<"������λ�ò���t"<<endl;
	insert(l, 't', 3);
	print(l);
	cout<<"���㳤��"<<endl;
	cout<<length(l)<<endl;
	cout<<"�ҳ�\'2\'��λ��"<<endl;
	cout<<locate(l, '2')<<endl;
	cout<<"��ȡ������λ��"<<endl;
	cout<<get(l, 4)<<endl;
	cout<<"ɾ���������ڵ�"<<endl;
	deleteNode(l,3);
	print(l);
	return 0;
} 
