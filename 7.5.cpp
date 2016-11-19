#include<iostream>
#include<string.h>
using namespace std;
#define datatype char
#define MAXSIZE 100
typedef struct {
	datatype data[MAXSIZE];
	int top;
}sqstack;
bool isEmpty(sqstack *sq) {
	if(sq -> top == 0) {
		return true;
	}
	else
		return false;
}
void initiate(sqstack *sq) {
	sq -> top == 0;
	return;
}
void push(sqstack *sq, datatype x) {
	sq -> data[sq -> top++] = x;
	return;
}
void pop(sqstack *sq) {
	--sq -> top;
	return;
}
void input(sqstack *sq,datatype ch[]) {
	for(int i = 0,max = strlen(ch);i < max;i++) {
		if(ch[i] == '(')
			push(sq, ch[i]);
		else if(ch[i] == ')')
			pop(sq);
	}
	return;
}
void judge(sqstack *sq) {
	datatype s[MAXSIZE];
	cin>>s;
	input(sq, s);
	if(isEmpty(sq) == 1) {
		cout<<"括号正确配对"<<endl;
	}
	else {
		cout<<"括号不配对"<<endl;
	}
}
void print(sqstack *sq) {
	int top = sq -> top;
	for(int i = 0;i < top;i++) {
		cout<<sq -> data[i];
		if(i != top -1)
			cout<<" -> ";
	}
	cout<<endl;
	return;
}
int main(void) {
	sqstack stack;
	sqstack *sq = &stack;
	initiate(sq);
	judge(sq);
	return 0;
}
