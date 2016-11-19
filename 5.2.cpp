#include<iostream>
using namespace std;
#define datatype int
#define pointer struct node *
struct node {
	datatype data;
	pointer next;
};
typedef struct{ 
	pointer top;
}lkstack; 
void init_lkstack(lkstack *ls) {
	ls -> top = NULL;
}
bool empty_lkstack(lkstack *ls) {
	if(ls -> top == NULL){
		return true;
	}
	else{
		return false;
	}
}
bool push_lkstack(lkstack *ls, datatype x) {
	pointer p = new node;
	p -> data = x;
	p -> next = ls -> top;
	ls -> top = p;
}
bool pop_lkstack(lkstack *ls, datatype *x){
	if(empty_lkstack(ls)) {
		return false;
	}
	else {
		pointer p = ls -> top;
		*x = p -> data;
		ls -> top = p -> next;
		delete p;
		return true;
	}
}
int gettop_lkstack(lkstack *ls){
	if(empty_lkstack(ls)){
		cout<<"��"<<endl;
		return NULL;
	}
	return ls -> top -> data;
}
void print(lkstack *ls) {
	pointer p = ls -> top;
	while(p != NULL) {
		cout<<p -> data;
		cout<<"  ";
		p = p -> next;
	}
	cout<<endl;
}
int main(void) {
	lkstack stack;
	lkstack *ls = &stack;
	init_lkstack(ls);
	int judge;
	datatype x;
	while(true){
		cout<<"����0,�����ж�ջ�գ�����1��ջ������2��ջ������3���������4ȡջ������������������"<<endl;
		cin>>judge;
		switch(judge){
			case 0:if(empty_lkstack(ls))cout<<"ջ��"<<endl;break;
			case 1:cout<<"������Ҫ���������"<<endl;cin>>x;push_lkstack(ls, x);break;
			case 2:pop_lkstack(ls, &x);cout<<"��ɾ����ֵ��"; cout<<x<<endl;break;
			case 3:cout<<"���˳��ջ"<<endl;print(ls);break;
			case 4:cout<<"ջ��";cout<<gettop_lkstack(ls)<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
