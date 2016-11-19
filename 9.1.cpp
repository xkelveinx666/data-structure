#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define datatype char
#define pointer struct node *
#define bitree pointer
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
	pointer s = sq -> data[sq -> front];
	sq -> front = (sq -> front + 1) % MAXSIZE;
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
void get(bitree t, datatype *x, int *endFlag, sqqueue sq) {
	if(t == NULL) {
		popStack(ls);
	}
	pushStack(ls, t);
	if(t -> data == x) {
		*endFlag = 1;
		return;
	}
	get(t -> lchild, x, endFlag);
	get(t -> rchild, x, endFlag);
}
int main(void) {
	cout<<"请用前序创建树"<<endl;
	bitree t = preCreate();
	int sum = 0;
	int rootFlag = 1;
	height(t);
	return 0;
}
//先序建立用:ABD@G@@@CE@@F@@	ppt:42
//层次遍历:A@B@@@C#		ppt:64 
//双序建立用:前:A B H F D E C K G #中:H B D F A E K C G #ppt:77 
//A B H F D E C K G #H B D F A E K C G #
