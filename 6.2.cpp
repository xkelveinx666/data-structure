#include<iostream>
using namespace std;
#define datatype int
#define pointer struct node *
struct node{
	datatype data;
	pointer next;
};
typedef struct{
	pointer front;
	pointer rear;
}lkqueue;
void init_lkqueue(lkqueue *ls){
	pointer p = new node;
	p -> next = NULL;
	ls -> front = p;
	ls -> rear  = p; 
}
bool empty_lkqueue(lkqueue *ls){
	if(ls -> front == ls -> rear){
		cout<<"队空"<<endl;
		return true;
	} 
	else
		return false;	
}
void en_lkqueue(lkqueue *ls, datatype x) {
	pointer p = new node;
	p -> next = NULL;
	p -> data = x;
	ls -> rear -> next = p;
	ls -> rear = p;
	return;
}
int de_lkqueue(lkqueue *ls, datatype *x) {
	if(empty_lkqueue(ls) == 1) {
		return 0;
	}
	pointer p = ls -> front;
	ls -> front = p -> next;
	*x = p -> next -> data;
	delete p;
}
datatype gethead_lkqueue(lkqueue *ls){
	if(empty_lkqueue(ls)) {
		return NULL;
	}
	else
		return	ls -> rear -> data; 
}
void print(lkqueue *ls){
	pointer p = ls -> front -> next;
	cout<<p -> data;
	p = p -> next;
	while(p != NULL){
		cout<<" -> ";
		cout<<p -> data;
		p = p -> next;
	}
	cout<<endl;
	return;
}
int main(void){
	lkqueue queue;
	lkqueue *ls = &queue;
	init_lkqueue(ls);
	int judge;
	datatype x;
	while(true){
		cout<<"输入0进行判断队空，输入1进队，输入2出队，输入3输出，输入4取队列顶，输入其他结束。"<<endl;
		cin>>judge;
		switch(judge){
			case 0:if(empty_lkqueue(ls))cout<<"队空"<<endl;break;
			case 1:cout<<"请输入要插入的数据"<<endl;cin>>x;en_lkqueue(ls, x);break;
			case 2:if(de_lkqueue(ls, &x) == 0)break;cout<<"被删除的值是"; cout<<x<<endl;break;
			case 3:if(empty_lkqueue(ls) == 1)break;cout<<"输出顺序队列"<<endl;print(ls);break;
			case 4:cout<<"队顶";cout<<gethead_lkqueue(ls)<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
} 
