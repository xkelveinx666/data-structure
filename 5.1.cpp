#include<iostream>
using namespace std;
#define datatype int
#define maxsize 100
typedef struct {
	datatype data[maxsize];
	int top;
}sqstack; 
void init_sqstack(sqstack *sq) {
	sq -> top = -1;
}
bool empty_sqstack(sqstack *sq) {
	if(sq -> top == -1){
		return true;
	}
	else{
		return false;
	}
}
bool push_sqstack(sqstack *sq, datatype x) {
	if(sq -> top == maxsize -1){
		return false;
	}
	else {
		sq -> data[++ (sq -> top)] = x;
		return true;
	}
}
bool pop_sqstack(sqstack *sq, datatype *x){
	if(empty_sqstack(sq)) {
		return false;
	}
	else {
		*x = sq -> data[sq -> top --];
		return true;
	}
}
int gettop_sqstack(sqstack *sq){
	if(empty_sqstack(sq)){
		cout<<"��"<<endl;
		return NULL;
	}
	return sq -> data[sq -> top];
}
void print(sqstack *sq) {
	int p = sq -> top;
	while(p != -1) {
		cout<<sq -> data[p--];
		cout<<"  ";
	}
	cout<<endl;
}
int main(void) {
	sqstack stack;
	sqstack *sq = &stack;
	init_sqstack(sq);
	int judge;
	datatype x;
	while(true){
		cout<<"����0,�����ж�ջ�գ�����1��ջ������2��ջ������3���������4ȡջ������������������"<<endl;
		cin>>judge;
		switch(judge){
			case 0:if(empty_sqstack(sq))cout<<"ջ��"<<endl;break;
			case 1:cout<<"������Ҫ���������"<<endl;cin>>x;push_sqstack(sq, x);break;
			case 2:pop_sqstack(sq, &x);cout<<"��ɾ����ֵ��"; cout<<x<<endl;break;
			case 3:cout<<"���˳��ջ"<<endl;print(sq);break;
			case 4:cout<<"ջ��";cout<<gettop_sqstack(sq)<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
