#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define datatype char
#define pointer struct node *
#define bitree pointer
#define spointer struct snode *
#define MAXSIZE 30
struct node {
	datatype data;
	pointer lchild;
	pointer	rchild;
}; 
typedef struct {
	pointer data[MAXSIZE + 1];
	int front,rear;
}sqqueue;
struct snode {
	datatype data;
	spointer next;
};
typedef struct{ 
	spointer top;
}lkstack;
bool empty_lkstack(lkstack *ls) {
	if(ls -> top == NULL){
		return true;
	}
	else{
		return false;
	}
}
bool push_lkstack(lkstack *ls, datatype x) {
	spointer p = new snode;
	p -> data = x;
	p -> next = ls -> top;
	ls -> top = p;
}
datatype pop_lkstack(lkstack *ls){
	if(empty_lkstack(ls)) {
		return NULL;
	}
	else {
		spointer p = ls -> top;
		datatype x = p  -> data;
		ls -> top = p -> next;
		delete p;
		return x;
	}
}
int gettop_lkstack(lkstack *ls){
	if(empty_lkstack(ls)){
		cout<<"空"<<endl;
		return NULL;
	}
	return ls -> top -> data;
}
void initiateSqqueue(sqqueue *sq) {
	sq -> front = 0;
	sq -> rear = 0;
	return;
}
bool isEmpty(sqqueue *sq) {
	if(sq -> front == sq -> rear) {
		return true;
	}
	else {
		return false;
	}
}
void enQueue(sqqueue *sq, pointer x) {
	sq -> rear = (sq -> rear + 1) % MAXSIZE;
	sq -> data[sq ->rear] = x;
	return;
}
pointer deQueue(sqqueue *sq) {
	sq -> front = (sq -> front + 1) % MAXSIZE;
	pointer s = sq -> data[sq -> front];
	return s;
}
void preOrder(bitree t) {
	if(t == NULL) {
		return;
	}
	cout<<t -> data;
	cout<<" ";
	preOrder(t -> lchild);
	preOrder(t -> rchild);
}
void inOrder(bitree t) {
	if(t == NULL) {
		return;
	}
	inOrder(t -> lchild);
	cout<<t -> data;
	cout<<" ";
	inOrder(t -> rchild);
}
bitree preCreate() {
	bitree t;
	datatype ch;
	cin>>ch;
	if(ch == '@') {
		return NULL;
	}
	t = new node;
	t -> data = ch;
	t -> lchild = preCreate();
	t -> rchild = preCreate();
	return t;
}
bitree levelCreate() {
	sqqueue queue;
	sqqueue *sq = &queue;
	initiateSqqueue(sq);
	bitree t;
	pointer s;
	pointer parent;
	datatype ch;
	while(cin>>ch, ch != '#') {
		if(ch != '@') {
			s = new node;
			s -> data = ch;
			s -> lchild = NULL;
			s -> rchild = NULL;
		}
		else {
			s = NULL;
		}
		enQueue(sq, s);
		if(sq -> rear == 1) {
			t = s;
			deQueue(sq);
		}
		else {
			parent = sq -> data[sq -> front];
			if(s && parent) {
				if(sq -> rear % 2 == 0) {
					parent -> lchild = s;
				}
				else {
					parent -> rchild = s;
				}
			}
			if(sq -> rear % 2 == 1) {
				deQueue(sq);
			}
		}
	}
	return t;
}
bitree create(datatype Pre[], int ps, int pe, datatype In[], int is, int ie) {
	if(ps > pe) {
		return NULL;
	}
	bitree t = new node;
	t -> data = Pre[ps];
	int i = is;
	while(In[i] != Pre[ps]) { 
		i++;
	}
	t -> lchild = create(Pre, ps + 1, ps + i - is, In, is, i - 1); 
	t -> rchild = create(Pre, ps + i - is + 1, pe, In,i + 1, ie);
	return t;
}
bitree preInCreate() {
	datatype Pre[MAXSIZE + 1];
	datatype In[MAXSIZE + 1];
	datatype ch;
	int i = 0;
	while(cin>>ch) {
		if(ch == '#') {
			break;
		}
		if(ch == ' ') {
			continue;
		}
		Pre[i++] = ch;
	}
	Pre[i] = '\0';
	int pe = i - 1;
	i = 0;
	while(cin>>ch, ch != '#') {
		if(ch == ' ') {
			continue;
		}
		In[i++] = ch;
	}
	In[i] = '\0';
	bitree t = create(Pre, 0, pe, In, 0, i - 1);
	return t;
}
void coutLeaf(bitree t, int *x) {
	if(t == NULL) {
		return;
	}
	if(!t -> lchild && !t -> rchild) {
		*x += 1;
	}
	coutLeaf(t -> lchild, x);
	coutLeaf(t -> rchild, x);
}
void coutTwoNode(bitree t, int *x, int *rootFlag) {
	if(t == NULL) {
		return;
	}
	if(rootFlag) {
		if(t -> lchild && t -> rchild) {
			*x += 1;
		}
		rootFlag = 0;
	}
	else if(!(t -> lchild && t -> rchild || !t -> lchild && !t -> rchild)){
		*x += 1;
	}
	coutTwoNode(t -> lchild, x, rootFlag);
	coutTwoNode(t -> rchild, x, rootFlag);
}
void coutThreeNode(bitree t,int *x, int *rootFlag) {
	if(t == NULL) {
		return;
	}
	if(rootFlag) {
		rootFlag = 0;
	}
	else {
		if(t -> lchild && t -> rchild) {
			*x += 1;
		}
	}
	coutThreeNode(t -> lchild, x, rootFlag);
	coutThreeNode(t -> rchild, x, rootFlag);
}
void height(bitree t) {
	int totalNode = 0;
	int sum = 0;
	int rootFlag = 1;
	int height = 0;
	coutThreeNode(t, &sum, &rootFlag);
	totalNode += sum;
	sum = 0;
	rootFlag = 1;
	coutTwoNode(t, &sum, &rootFlag);
	totalNode += sum * 2;
	sum = 0;
	coutLeaf(t, &sum);
	totalNode += sum;
	height = floor(log2(totalNode) + 1);
	cout<<height<<endl;
}
void inGetOrder(bitree t, lkstack *ls, datatype *x, int *endFlag) {
	if(t == NULL) {
		return;
	}
	if(t -> data == *x) {
		*endFlag = 1;
	}
	if(*endFlag) {
		return;
	}
	inGetOrder(t -> lchild, ls, x, endFlag);
	push_lkstack(ls, t -> data);
	if(t -> lchild == NULL && t -> rchild == NULL) {
		pop_lkstack(ls);
	}
	inGetOrder(t -> rchild, ls, x, endFlag);
}
void print(lkstack *ls) {
	spointer p = ls -> top;
	while(p -> next != NULL) {
		cout<<p -> data;
		cout<<" ";
		p = p -> next;
	}
}
void reversePrint(lkstack *ls, datatype *root) {
	if(gettop_lkstack(ls) == *root) {
		return;
	}
	datatype x = pop_lkstack(ls);
	reversePrint(ls, root);
	cout<<x;
	cout<<" ";
}
bool getNode(bitree t, datatype x) {
	lkstack stack;
	lkstack *ls = &stack;
	int endFlag = 0;
	datatype root = t -> data;
	datatype frchild = t -> rchild -> data;
	inGetOrder(t, ls, &x, &endFlag);
	if(!endFlag) {
		cout<<"该点不存在"<<endl;
		return false;
	}
	if(gettop_lkstack(ls) == root && x != frchild) {
		print(ls);
	}
	else {
		cout<<root;
		cout<<" ";
		reversePrint(ls, &root);
	}
	cout<<x<<endl;
	return true;
}
void postDeleteOrder(bitree t) {
	if(t == NULL) {
		return;
	}
	postDeleteOrder(t -> lchild);
	postDeleteOrder(t -> rchild);
	if(t -> lchild) {
		delete t -> lchild;
		t -> lchild = NULL;
	}
	if(t -> rchild) {
		delete t -> rchild;
		t -> rchild = NULL;
	}
}
int main(void) {
	bitree t;
	int judge;
	int x = 0;
	int rootFlag = 1;
	while(true){
		cout<<"输入0进行前序建树，输入1进行层次建树，输入2进行前中建树\n"
		"输入3统计度数为1的节点，输入4统计度数为2的节点，输入5计算树高\n"
		"输入6查找值为x的结点的函数，输入7递归删除二叉树。"<<endl;
		cin>>judge;
		switch(judge){
			case 0:cout<<"前序建树"<<endl;t = preCreate();cout<<endl;break;
			case 1:cout<<"层次建树"<<endl;t = levelCreate();cout<<endl;break;
			case 2:cout<<"前中建树"<<endl;t = preInCreate();cout<<endl;break;
			case 3:cout<<"统计度数为1的节点"<<endl;x = 0;coutLeaf(t, &x);cout<<x<<endl;break;
			case 4:cout<<"统计度数为2的节点"<<endl;x = 0;rootFlag = 1;coutTwoNode(t, &x, &rootFlag);cout<<x<<endl;break;
			case 5:cout<<"计算树高"<<endl;height(t);break;
			case 6:cout<<"查找值为x的结点的函数"<<endl;datatype x;cin>>x;getNode(t, x);break;
			case 7:cout<<"归删除二叉树"<<endl;postDeleteOrder(t);break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//先序建立用:ABD@G@@@CE@@F@@	ppt:42
//层次遍历:A@B@@@C#		ppt:64 
//双序建立用:前:A B H F D E C K G #中:H B D F A E K C G #ppt:77 
//A B H F D E C K G #H B D F A E K C G #
