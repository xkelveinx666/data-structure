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
bool isSymmetry(lkstack *ls, datatype constract[], int max){
	int i = 0; 
	pointer p = ls -> top;
	if(empty_lkstack(ls))
		return false;
	while(p != NULL && max - i != 1){
		if(constract[i++] != p -> data) {
			return false;
		}
		else {
			p = p -> next;
			max--;
		}
	} 
	return true;
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
	datatype constract[100];
	int i = 0;
	while(true){
		cout<<"输入0,进行判断栈空，输入1进栈，输入2出栈，输入3输出，输入4判断是否回文，输入其他结束。"<<endl;
		cin>>judge;
		switch(judge){
			case 0:if(empty_lkstack(ls))cout<<"栈空"<<endl;break;
			case 1:cout<<"请输入要插入的数据"<<endl;cin>>x;push_lkstack(ls, x);constract[i++] = x;break;
			case 2:pop_lkstack(ls, &x);cout<<"被删除的值是"; cout<<x<<endl;constract[i--] = NULL;break;
			case 3:cout<<"输出顺序栈"<<endl;print(ls);break;
			case 4:cout<<"判断回文";if(isSymmetry(ls, constract, i) == 1) cout<<"Yes"<<endl; else cout<<"NO"<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
