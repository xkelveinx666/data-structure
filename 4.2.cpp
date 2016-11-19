#include<iostream>
using namespace std;
#define datatype char
#define maxsize 100
#define cursor int
#define NIL -1
typedef struct{
	datatype data;
	cursor next;
}snode;
snode nodepool[maxsize];
cursor sp;
cursor newnode(){
	cursor p;
	if(sp == NIL)
		return NIL;
	p = sp;
	sp = nodepool[sp].next;
	return p;
}
deletenode(cursor p){
	nodepool[p].next = sp;
	sp = p;
}
cursor get(cursor L, int i){
	int j;
	if(i < 0)
		return NIL;
	j = -1;
	cursor p = L;
	while(p != NIL){
		if(i == ++j)
			break;
		p = nodepool[p].next;
	}
	return p;
}
int length(cursor L) {
	int i = 0;
	cursor p = L;
	while(p != NIL){
		p = nodepool[p].next;
		i++;
	}
	return i;
}
cursor locate(cursor L,datatype x) {
   cursor p = nodepool[L].next;	  
   while(p != NIL) {
      if(nodepool[p].data==x) 
	  	return p;
      p=nodepool[p].next; 
   }
   return NIL;
}
void print(cursor L){
	cursor p = L;
	if(p != NIL){
		cout<<nodepool[p].data;
		p = nodepool[p].next;
	}
	while(p != NIL){
		cout<<"->";
		cout<<nodepool[p].data;
		p = nodepool[p].next;
	}
	cout<<endl;
}
int insert(cursor L,datatype x,int i) {
  	cursor p,s;
 	p=get(L,i-1);   	
 	if(p==NIL)
    	return -1;
  	s = newnode();
  	if(s == NIL)
    	return 0;
  	nodepool[s].data=x;	
 	nodepool[s].next=nodepool[p].next;
  	nodepool[p].next=s;
  	return 1;		     
}
int deleteNode(cursor L,int i) {
  	cursor p,q;
  	q=get(L,i-1);
  	if(q==NIL || nodepool[q].next==NIL)           
    	return 0;
  	p=nodepool[q].next;
  	nodepool[q].next=nodepool[p].next;	                
	deletenode(p);	
  	return 1;		
}
void initialize(){
	for(int i = 0;i < maxsize - 1; i++)
		nodepool[i].next = i + 1;
	nodepool[maxsize-1].next = NIL;
	sp = 0;
}
cursor build(){
	cursor s;
	datatype x;
	cin>>x;
	while(x != '$'){
		s = newnode();
		nodepool[s].data = x;
		nodepool[s].next = sp;
		cin>>x;
	}
	nodepool[s].next = NIL;
	return 0;
}
int main(void){
	initialize();
	cursor p = build();
	print(p);
	cout<<"求长度"<<endl;
	cout<<length(p)<<endl;
	cout<<get(p, 3)<<endl;
	cout<<locate(p, '3')<<endl;
	print(p);
	cout<<"插入t"<<endl;
	insert(p, 't', 3);
	print(p);	
	cout<<"插入k"<<endl;
	insert(p, 'k', 5);
	print(p);
	cout<<"移除第五个位置元素"<<endl;	
	deleteNode(p, 5);
	print(p);
	cout<<"移除第三个位置元素"<<endl;
	deleteNode(p, 3);
	print(p);
	return 0;
}
