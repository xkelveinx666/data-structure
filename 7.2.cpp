#include<iostream>
#include<string.h>
using namespace std;
#define NODESIZE 3
#define pointer struct node *
#define lkstring pointer
struct node{
	char S[NODESIZE];
	pointer next;
};
void inputCh(char ch[]) {
	cin>>ch;
	ch[strlen(ch)] = '\0';
}
int length(lkstring ls) {
	cout<<"the length of lkstring is ";
	pointer p = ls;
	int length = 0;
	while(p -> next != NULL) {
		p = p -> next;
		length += NODESIZE;
	}
	length -= NODESIZE;
	length += strlen(p -> S);
	return length; 
}
pointer initiate() {
	pointer head;
	head = new node;
	head -> next = NULL;
	return head;
}
void insert(pointer p, char ch[], int start,int max) {
	pointer s = p;
	for(int i = 0;i < max;start++, i++) {
		if(start % NODESIZE == 0) {
			start = 0;
			s = new node;
			s -> next = NULL;
			p -> next = s;
			p = p -> next;
		}
		s -> S[start] = ch[i]; 
	}
	if(start == NODESIZE - 1) {
		s -> S[start] = '\0';
	}
	return;
}
void assign(lkstring ls, char ch[]) {
	insert(ls, ch, 0, strlen(ch));
 	return;
}
void concat(lkstring ls, char ch[]) {
	pointer p = ls;
	int start = 0;
	while(p -> next != NULL) {
		p = p -> next;
	}
	insert(p, ch, strlen(p -> S), strlen(ch));
	return;
}
int compare(lkstring ls1,lkstring ls2) {
	pointer p = ls1 -> next;
	pointer q = ls2 -> next;
	while(p != NULL && q != NULL) {
		if(strcmp(p -> S, q -> S) != 0) {
			return strcmp(p -> S, q -> S);
		}			
		p = p -> next;
		q = q -> next;
	}
	return 0;
}
void build(lkstring ls) {
	cout<<"enter string to build sqstring"<<endl;
	char ch[100];
	inputCh(ch);
	assign(ls, ch);
 	return;
}
void print(lkstring ls) {
	pointer p = ls -> next;
	while(p != NULL) {
		if(p != ls -> next)	
			cout<<" -> ";
		cout<<p -> S;
		p = p -> next;
	}
	cout<<endl;
	cout<<length(ls)<<endl;
	return;
}
int main(void) {
	char ch[100];
	lkstring ls = initiate();
	build(ls);
	print(ls);
	cout<<"enter string to concat sqstring"<<endl;
	inputCh(ch);
	concat(ls, ch);
	print(ls);
	cout<<"enter new string to compare"<<endl;
	lkstring ls2 = initiate();
	build(ls2);
	print(ls2);
	int i = compare(ls, ls2);
	if(i < 0) {
		cout<<"ls2 > ls1"<<endl;
	}
	else if(i == 0) {
		cout<<"ls2 = ls1"<<endl;
	}
	else {
		cout<<"ls1 > ls2"<<endl;
	}
	return 0;
}

