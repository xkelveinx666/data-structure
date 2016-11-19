#include<iostream>
using namespace std;
#define datatype char
#define pointer struct node *
#define bitree pointer
#define MAXSIZE 100
struct node {
	datatype data;
	pointer lchild;
	pointer rchild;
};
typedef struct {
	pointer data[MAXSIZE];
	int front, rear;
}sqqueue;
void initiateQueue(sqqueue *sq) {
	sq -> front = 0;
	sq -> rear = 0;
}
bool isEmpty(sqqueue *sq) {
	if(sq -> rear == sq -> front)
		return true;
	else
		return false;
}
bool isFull(sqqueue *sq) {
	if((sq -> rear - sq -> front + MAXSIZE + 1) % MAXSIZE == 0){
		return true;
	} 
	else
		return false;
}
void enSqqueue(sqqueue *sq, pointer t) {
	if(isFull(sq) == 1)
		return;
	sq -> rear = (sq -> rear + 1) % MAXSIZE;
	sq -> data[sq ->rear] = t;
	return;
}
void deSqqueue(sqqueue *sq, pointer *t) {
	if(isEmpty(sq) == 1)
		return;
	sq -> front = (sq -> front + 1) % MAXSIZE;
	*t = sq -> data[sq -> front];
}
void preorder(bitree t) {
	if(t == NULL)
		return;
	cout<<t -> data;
	cout<<" ";
	preorder(t -> lchild);
	preorder(t -> rchild);
}
void inorder(bitree t) {
	if(t == NULL)
		return;
	inorder(t -> lchild);
	cout<<t -> data;
	cout<<" ";
	inorder(t -> rchild);
}
void postorder(bitree t) {
	if(t == NULL)
		return;
	postorder(t -> lchild);
	postorder(t -> rchild);
	cout<<t -> data;
	cout<<" ";
}
void floororder(bitree t) {
	sqqueue queue;
	sqqueue *sq = &queue;
	initiateQueue(sq);
	enSqqueue(sq , t);
	pointer p;
	while(isEmpty(sq) == 0) {
		deSqqueue(sq, &p);
		cout<<p -> data;
		cout<<" ";
		if(p -> lchild != NULL)
			enSqqueue(sq, p -> lchild);
		if(p -> rchild != NULL)
			enSqqueue(sq, p -> rchild);
	}
	cout<<endl;
	return;
}
bitree preCreate() {
	bitree t;
	char ch;
	cin>>ch;
	if(ch == '@')
		return NULL;
	t = new node;
	t -> data = ch;
	t -> lchild = preCreate();
	t -> rchild = preCreate();
	return t;
}
void leaf(bitree t, int *num) {
	if(t == NULL)
		return;
	if(t -> lchild == NULL && t -> rchild == NULL) {
		++*num;
	}
	if(t -> lchild != NULL)
		leaf(t -> lchild, num);
	if(t -> rchild != NULL)
		leaf(t -> rchild, num);
}
void coutLeaf(bitree t) {
	int num = 0;
	leaf(t, &num);
	cout<<"Ҷ�ӽڵ���"<<endl;
	cout<<num<<endl;
}
void node(bitree t, int *num) {
	if(t == NULL)
		return;
		++*num;
	if(t -> lchild != NULL)
		node(t -> lchild, num);
	if(t -> rchild != NULL)
		node(t -> rchild, num);
}
void coutNode(bitree t) {
	int num = 0;
	node(t, &num);
	cout<<"�ڵ���"<<endl;
	cout<<num<<endl;
}
void changeChild(bitree t) {
	if(t == NULL)
		return;
	pointer p = t -> lchild;
	t -> lchild = t -> rchild;
	t -> rchild = p; 
	changeChild(t -> lchild);
	changeChild(t -> rchild);
}
void number(bitree t, bool *flag) {
	if(t == NULL)
		return;
	if(t -> data >= '9' || t -> data <= '0'){ 
		*flag = false;
		return;
	} 
	if(t -> lchild != NULL)
		number(t -> lchild, flag);
	if(t -> rchild != NULL)
		number(t -> rchild, flag);
}
void onlyNumber(bitree t) {
	bool flag = true;
	number(t, &flag);
	if(!flag)
		cout<<"�з������ַ�"<<endl;
	else
		cout<<"���������ַ�"<<endl;
}
void Equals(bitree t1, bitree t2, bool *flag) {
	if(t1 == NULL && t2 == NULL) {
		return;
	}
	if(t1 || t2) {
		if(t1 && t2);
		else {		
			*flag = false;
			return;	
		}
	}
	if(t1 -> data != t2 -> data) {
		*flag = false;
		return;
	}
	Equals(t1 -> lchild, t2 -> lchild, flag);
	Equals(t1 -> rchild, t2 -> rchild, flag);
}
void allEquals(bitree t) {
	cout<<"����ǰ�򴴽���2"<<endl;
	bitree t2 = preCreate();
	bool flag = true;
	if(t == NULL && t2 == NULL) {
		cout<<"�������"<<endl;
		return;
	}
	Equals(t, t2, &flag);
	if(flag)
		cout<<"�������"<<endl;
	else
		cout<<"��������"<<endl;
}
int main(void) {
	cout<<"����ǰ�򴴽���"<<endl;
	bitree t = preCreate();
	int judge;
	while(true){
		cout<<"����0����ǰ�����������1�������������2�������������3��α���\n����4��Ҷ�ӣ�����5���нڵ㣬����6��������\n����7ֻ�����֣�����8�������,��������������"<<endl;
		cin>>judge;
		switch(judge){
			case 0:cout<<"����"<<endl;preorder(t);cout<<endl;break;
			case 1:cout<<"����"<<endl;inorder(t);cout<<endl;break;
			case 2:cout<<"����"<<endl;postorder(t);cout<<endl;break;
			case 3:cout<<"���"<<endl;floororder(t);break;
			case 4:coutLeaf(t);break;
			case 5:coutNode(t);break;	
			case 6:cout<<"��������"<<endl;changeChild(t);break;
			case 7:onlyNumber(t);break;
			case 8:allEquals(t);break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//��������:ABD@G@@@CE@@F@@	ppt:42
