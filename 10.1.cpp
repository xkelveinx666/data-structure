#include<iostream>
using namespace std;
#define MAXSIZE 100
#define datatype char
#define mattype int
#define pointer struct node *
#define tpointer struct tnode *
#define bitree tpointer
typedef struct {
	datatype data[MAXSIZE + 1];
	mattype adjmat[MAXSIZE + 1][MAXSIZE + 1];
	int n, e;
}MatGraph;
struct node {
	int no;
	int weight;
	pointer next;
};
typedef struct {
	datatype data;
	pointer first;
}headtype;
typedef struct {
	headtype adlist[MAXSIZE + 1];
	int n;
	int e;
}LkGraph;
typedef struct {
	int nodeList[MAXSIZE];
	int rear;
	int front;
}Sqqueue;
struct tnode {
	int node;
	int weight;
	tpointer lchild;
	tpointer rchild;
};
typedef struct {
	int weight;
	int startNo;
	int endNo;
}Edge;
void initQueue(Sqqueue *sq) {
	sq -> front = 0;
	sq -> rear = 0;
}
bool isEmpty(Sqqueue *sq) {
	if(sq -> front == sq -> rear) {
		return true;
	}
	else {
		return false;
	}
}
void enQueue(Sqqueue *sq, int node) {
	sq -> rear = (sq -> rear + 1) % MAXSIZE;
	sq -> nodeList[sq -> rear] = node;
}
int deQueue(Sqqueue *sq) {
	sq -> front = (sq -> front + 1) % MAXSIZE;
	return sq -> nodeList[sq -> front];
}
void creatMatGraph(MatGraph *g) {
	int n, e, i, j , w;
	cin>>n;
	g -> n = n;
	for(i = 1;i <= n;i++) {
		cin>>g -> data[i];
	}
	for(i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			g -> adjmat[i][j] = 0;
		}
	}
	e = 0;
	while(cin>>i>>j>>w,i > 0) {
		e++;
		g -> adjmat[i][j] = w;
		g -> adjmat[j][i] = w;
	}
	g -> e = e;
	return;
}
void printMatGraph(MatGraph *g) {
	int n = g -> n;
	for(int i = 1;i <= n;i++) {
		cout<<g -> data[i]<< " ";
	}
	cout<<endl;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cout<<g -> adjmat[i][j]<<" ";
		}
		cout<<endl;
	}
}
void dfsMatGraph(MatGraph *g, int v, int visited[], int *n) {
	int j;
	cout<<v<<" ";
	visited[v] = 1;
	for(j = 1;j <= *n;j++){
	    if(g->adjmat[v][j]==1 && !visited[j]){
	   		dfsMatGraph(g, j, visited, n);
	   }
	}
}
void completeDFSMatGraph(MatGraph *g) {
	int n = g -> n;
	int visited[MAXSIZE + 1];
	cout<<"邻接矩阵深度优先遍历"<<endl;
	for(int i = 0;i < n;i++){
		visited[i] = 0;
	}
	dfsMatGraph(g, 1, visited, &n);
}
void bfsMatGraph(MatGraph *g) {
	Sqqueue queue;
	Sqqueue *sq = &queue;
	initQueue(sq);
	int v = 1;
	int visited[MAXSIZE + 1];
	int n = g -> n;
	int j;
	for(j = 1;j < n;j++) {
		visited[j] = 0;
	}
	cout<<v<<" ";
	visited[v] = 1;
	enQueue(sq, v);
	while(!isEmpty(sq)) {
		v = deQueue(sq);
		for(j = 1;j <= n;j++) { 
			if(g->adjmat[v][j] == 1 && !visited[j]) {
				cout<<j<<" ";
				visited[j] = 1;
				enQueue(sq, j);
			} 
		}
	}
}
void creatLkGraph(LkGraph *g) {
	int n, e, i, no, weight;
	datatype data; 
	pointer p;
	pointer s;
	cin>>n;
	g -> n = n;
	for(i = 1;i <= n;i++) {
		cin>>g -> adlist[i].data;
	}
	e = 0;
	for(i = 1;i <= n;i++) {
		g -> adlist[i].first = new node;
		p = g -> adlist[i].first;
		while(cin>>no>>weight,no > 0) {
			s = new node;
			s -> no = no;
			s -> weight = weight;
			p -> next = s;
			p = p -> next;
			e++;
		}
		p -> next = NULL;
	}
	g -> e = e;
	return;
}
void printLkGraph(LkGraph *g) {
	int n = g -> n;
	for(int i = 1;i <= n;i++) {
		cout<<g -> adlist[i].data<< " ";
		pointer p = g -> adlist[i].first;
		while(p -> next != NULL) {
			p = p -> next;
			cout<<p -> no<<"with"<<p -> weight<<" ";
		}
		cout<<endl;
	}
	return;
}
void dfsLkGraph(LkGraph *g,int v,int visited[]) {
	pointer p;
	cout<<v<<" ";
	visited[v] = 1;
	p = g -> adlist[v].first -> next;
	while(p != NULL) {
		if(!visited[p -> no]) {
			dfsLkGraph(g, p -> no, visited);
		}
		p = p -> next;
	}
}
void completeDFSLkGraph(LkGraph *g) {
	int n = g -> n;
	int visited[MAXSIZE + 1];
	cout<<"邻接表深度优先遍历"<<endl;
	for(int i = 0;i < n;i++){
		visited[i] = 0;
	}
	dfsLkGraph(g, 1, visited);
}
void bfsLkGraph(LkGraph *g) {
	Sqqueue queue;
	Sqqueue *sq = &queue;
	initQueue(sq);
	pointer p;
	int v = 1;
	int visited[MAXSIZE + 1];
	int n = g -> n;
	int j;
	for(j = 1;j <= n;j++) {
		visited[j] = 0;
	}
	cout<<v<<" ";
	visited[v] = 1;
	enQueue(sq, v);
	while(!isEmpty(sq)) {
		v = deQueue(sq);
		p = g->adlist[v].first -> next;
		while(p != NULL) { 
			if(!visited[p -> no]) {
				cout<<p -> no<<" ";
				visited[p -> no] = 1;
				enQueue(sq, p -> no);
			}
			p = p -> next;
		}
	}
}
void getTnode(bitree t, int *data, bitree *node) {
	if(t == NULL) {
		return;
	}
	if(t -> node == *data) {
		*node = t;
	}
	getTnode(t -> lchild, data, node);
	getTnode(t -> rchild, data, node);
}
bitree primMatGraph(MatGraph *g) {
	bitree t = new tnode;
	bitree pnode;
	bitree snode;
	t -> rchild = NULL;
	t -> lchild = NULL;
	int n = g -> n;
	int i;
	int lowcost[MAXSIZE + 2];
    int mst[MAXSIZE + 2];
    int minId;
	int min;
    for(i = 2;i <= n;i++) {
    	lowcost[i] = g -> adjmat[1][i];
    	if(lowcost[i] == 0) {
    		lowcost[i] = 999;
		}
    	mst[i] = 1;
	}
	t -> node = 1;
	t -> weight = lowcost[1];
	int j = 0;
	for(j = 2;j <= n;j++) {
		minId = 2;
		min = 999;
		for(i = 2;i <= n;i++) {
			if(lowcost[i] < min && lowcost[i] != 0) {
				min = lowcost[i];
				minId = i;
			}
		}
	 	pnode = NULL;
		getTnode(t, &mst[minId], &pnode);
		snode = new tnode;
		snode -> lchild = NULL;
		snode -> rchild = NULL;
		snode -> node = minId;
		snode -> weight = lowcost[minId];
		if(pnode -> lchild == NULL) {
			pnode -> lchild = snode;
		}
		else {
			pnode -> rchild = snode;
		}
		lowcost[minId] = 0;
		for(i = 2;i <= n;i++) {
			if(g -> adjmat[minId][i] == 0) {
				continue;
			}
			if(g -> adjmat[minId][i] < lowcost[i]) {
				lowcost[i] = g -> adjmat[minId][i];
				mst[i] = minId;
			}
		}
	}
	return t;
}
void findMinEdgeLkGraph(LkGraph *g,int v,int visited[], Edge *e) {
	pointer p;
	visited[v] = 1;
	p = g -> adlist[v].first -> next;
	if(p == NULL) {
		findMinEdgeLkGraph(g, v + 1, visited, e);
	}
	while(p != NULL) {
		if(!visited[p -> no]) {
			findMinEdgeLkGraph(g, p -> no, visited, e);
			if(e -> weight > p -> weight) {
				e -> weight = p -> weight;
				e -> startNo = v;
				e -> endNo = p -> no;
			}
		}
		p = p -> next;
	}
}
bool allZero(int sets[], int *n) {
	for(int i = 0;i < *n;i++) {
		if(sets[i] != 0) {
			return false;
		}
	}
	return true;
}
void deleteEdgeLkGraph(LkGraph *g, int startNo, int endNo) {
	pointer q = g -> adlist[startNo].first;
	pointer p = q -> next;
	while(p != NULL) {
		if(p -> no == endNo) {
			break;
		}
		q = p;
		p = p -> next;
	}
	if(p == NULL) {
		q -> next = NULL;
	}
	if(p != NULL) {
		if(p -> next != NULL) {
			q -> next = p -> next;		
		}
		else {
			q -> next = NULL;
		}
		delete p;
	}
}
void kruskalLkGraph(LkGraph *g) {
	int sets[MAXSIZE + 1];
	int i;
	int k;
	int n = g -> n;
	int flag;
	for(i = 1;i <= n;i++) {
		sets[i] = i;
	}
	int visited[MAXSIZE + 1];
	Edge edge;
	Edge *e = &edge;
	while(!allZero(sets, &n)) {
		for(int i = 1;i <= n;i++){
			visited[i] = 0;
		}
		e -> weight = 999;
		findMinEdgeLkGraph(g, 1, visited, e);
		if(e -> weight == 999) {
			break;
		}
		deleteEdgeLkGraph(g, e -> startNo, e -> endNo);
		deleteEdgeLkGraph(g, e -> endNo, e -> startNo);
		if(sets[e -> startNo] != sets[e -> endNo]) {
			flag = 0;
			sets[0] = sets[e -> endNo];
			for(k = 1;k <= n;k++) {
				if(sets[k] == sets[0]) {
					sets[k] = sets[e -> startNo];
				}
			}
			for(k = 2;k <= n;k++) {
				if(sets[1] != sets[k]) {
					flag = 1;
				}
			}
			cout<<e -> startNo<<"---"<<e -> weight<<"--->"<<e -> endNo<<endl;
			if(flag == 0) {
				break;
			}
		}
	}
	return;
}
void preOrder(bitree t) {
	if(t == NULL) {
		return;
	}
	cout<<t -> node;
	cout<<" ";
	preOrder(t -> lchild);
	preOrder(t -> rchild);
}
int main(void) {
	LkGraph lkgraph;
	LkGraph *g2 = &lkgraph;
	MatGraph matgraph;
	MatGraph *g1 = &matgraph;
	int judge;
	while(true){
		cout<<"输入0建立邻接矩阵，输入1建立邻接表，输入2邻接矩阵深度优先\n"
		"输入3邻接矩阵广度优先，输入4邻接表深度优先，输入5邻接矩阵广度优先\n"
		"输入6邻接矩阵Prim算法，输入7邻接表Kruskal算法，输入8输出邻接矩阵，输入9输出邻接表。"<<endl;
		cin>>judge;
		switch(judge){
			case 0:cout<<"建立邻接矩阵"<<endl;creatMatGraph(g1);cout<<endl;break;
			case 1:cout<<"建立邻接表"<<endl;creatLkGraph(g2);cout<<endl;break;
			case 2:cout<<"邻接矩阵深度优先"<<endl;completeDFSMatGraph(g1);cout<<endl;break;
			case 3:cout<<"邻接矩阵广度优先"<<endl;bfsMatGraph(g1);cout<<endl;break;
			case 4:cout<<"邻接表深度优先"<<endl;completeDFSLkGraph(g2);cout<<endl;break;
			case 5:cout<<"邻接矩阵广度优先"<<endl;bfsLkGraph(g2);cout<<endl;break;
			case 6:cout<<"邻接矩阵Prim算法"<<endl;preOrder(primMatGraph(g1));cout<<endl;break;
			case 7:cout<<"邻接表Kruskal算法"<<endl;kruskalLkGraph(g2);cout<<endl;break;
			case 8:cout<<"邻输出邻接矩阵"<<endl;printMatGraph(g1);cout<<endl;break;
			case 9:cout<<"输出邻接表"<<endl;printLkGraph(g2);cout<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
/*
邻接矩阵 P31
6
a b c d e f
1 2 6
1 3 1
1 4 5
2 1 6
2 3 5
2 5 3
3 1 1
3 2 5
3 4 7
3 5 5
3 6 4
4 1 5
4 3 7
4 6 2
5 2 3
5 3 5
6 3 4
6 4 2
6 5 6
0 0 0
邻接矩阵(深度优先用) P46
7
1 2 3 4 5 6 7
1 2 1
1 3 1
1 4 1
2 5 1
2 6 1
2 7 1
3 7 1
4 7 1
5 6 1
0 0 0
邻接矩阵(Prim用) P62
7
1 2 3 4 5 6 7
1 2 19
1 5 14
1 7 18
2 3 5
2 4 7
2 5 12
3 4 3
4 5 8
4 6 21
5 7 16
6 7 27
0 0 0
邻接表 P34
5
a b c d e
2 2
4 4
0 0
1 1
3 3
5 5
0 0
2 2
4 4
5 5
0 0
1 1
3 3
0 0
2 2
3 3
0 0 
邻接表(深度优先用) P47
8
1 2 3 4 5 6 7 8
2 2
3 3
0 0
4 4
5 5
1 1
0 0
6 6
7 7
1 1
0 0
8 8
2 2
0 0
8 8
2 2
0 0
7 7
3 3
0 0
3 3
6 6
0 0
4 4
5 5
0 0
邻接表(Kruskal用) P67
7
1 2 3 4 5 6 7
2 19
5 14
7 18
0 0
1 19
3 5
4 7
5 12
0 0
2 5
4 3
0 0
2 7
3 3
5 8
6 21
0 0
1 14
2 12
4 8
7 16
0 0
4 21
7 27
0 0
1 18
5 16
6 27
0 0
*/
