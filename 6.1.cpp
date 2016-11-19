#include<iostream>
using namespace std;
#define maxsize 3
#define datatype int
typedef struct{
	datatype data[maxsize];
	int front;
	int rear;
}sqqueue;
void init_sqqueue(sqqueue *sq){
	sq -> front = NULL;
	sq -> rear  = NULL; 
}
bool empty_sqqueue(sqqueue *sq){
	if(sq -> front == sq -> rear){
		cout<<"队空"<<endl;
		return true;
	} 
	else
		return false;	
}
bool isFull(sqqueue *sq){
	if((sq -> rear - sq -> front + maxsize + 1) % maxsize == 0){
		cout<<"上溢"<<endl;
		return true;
	} 
	else
		return false;
}
void en_sqqueue(sqqueue *sq, datatype x) {
	if(isFull(sq) == 1) {
		return;
	}
	sq -> rear = (sq -> rear + 1) % maxsize;
	sq -> data[sq -> rear] = x;
	return;
}
int de_sqqueue(sqqueue *sq, datatype *x) {
	if(empty_sqqueue(sq) == 1) {
		return 0;
	}
	sq -> front = (sq -> front + 1) % maxsize;
	*x = sq -> data[sq -> front];
	return 1;	
}
datatype gethead_sqqueue(sqqueue *sq){
	if(empty_sqqueue(sq)) {
		return NULL;
	}
	else
		return	sq -> data[sq -> rear]; 
}
void print(sqqueue *sq){
	int p = sq -> front;
	p = (p + 1) % maxsize;
	cout<<sq -> data[p];
	while(p != sq -> rear){
		cout<<" -> ";
		p = (p + 1) % maxsize;
		cout<<sq -> data[p];
	}
	cout<<endl;
	return;
}
int main(void){
	sqqueue queue;
	sqqueue *sq = &queue;
	init_sqqueue(sq);
	int judge;
	datatype x;
	while(true){
		cout<<"输入0,进行判断队空，输入1进队，输入2出队，输入3输出，输入4取队列顶，输入其他结束。"<<endl;
		cin>>judge;
		switch(judge){
			case 0:if(empty_sqqueue(sq))cout<<"队空"<<endl;break;
			case 1:cout<<"请输入要插入的数据"<<endl;cin>>x;en_sqqueue(sq, x);break;
			case 2:if(de_sqqueue(sq, &x) == 0)break;cout<<"被删除的值是"; cout<<x<<endl;break;
			case 3:if(empty_sqqueue(sq) == 1)break;cout<<"输出顺序队列"<<endl;print(sq);break;
			case 4:cout<<"队顶";cout<<gethead_sqqueue(sq)<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
} 
