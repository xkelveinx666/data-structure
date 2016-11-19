#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 100
typedef struct {
	char ch[MAXSIZE + 1];
	int n;
}sqstring;
int length(sqstring *sq) {
	strlen(sq -> ch);	
}
void initiate(sqstring *sq) {
	sq -> n = 0;
}
void build(sqstring *sq) {
	cout<<"enter string to build sqstring"<<endl;
	cin>>sq -> ch;
	sq -> n = strlen(sq -> ch);
	return;
}
void assign(sqstring *sq1, sqstring *sq2) {
	cout<<"assign string"<<endl;
	strcpy(sq1 -> ch, sq2 -> ch);
	sq1 -> n = sq2 -> n;
	return;
}
bool concat(sqstring *sq1, sqstring *sq2) {
	cout<<"concat string"<<endl;
	if(sq1 -> n + sq2 -> n >= MAXSIZE)
		return false;
	strcat(sq1 -> ch, sq2 -> ch);
	sq1 -> n += sq2 -> n;	
	return true;
}
bool insert(sqstring *sq, char x) {
	if(sq -> n == MAXSIZE)
		return false;
	sq -> ch[sq -> n++] = x;
	return true;
}
void print(sqstring *sq) {
	cout<<sq -> ch<<endl;
}
bool substr(sqstring *sq1, int i , int j, sqstring *sq2) {
	if(i < 0 || j + 1 > sq1 -> n)
		return false;
	int p = 0;
	for(int k = i;k < j + 1;p++,k++) {
		sq2 -> ch[p] = sq1 -> ch[k]; 
	}
	sq2 -> ch[p] = '\0';
	return true;
}
int compare(sqstring *sq1,sqstring *sq2) {
	return strcmp(sq1 -> ch, sq2 -> ch);
}
int main(void) {
	sqstring string1;
	sqstring string2;
	sqstring *sq1 = &string1;
	sqstring *sq2 = &string2;
	int i, j;
	initiate(sq1);
	initiate(sq2);
	build(sq2);
	assign(sq1, sq2);
	print(sq1);
	build(sq2);
	concat(sq1, sq2);
	print(sq1);	
	cout<<"enter star and end to substr"<<endl;
	cin >> i;
	cin >> j;
	substr(sq1, i ,j, sq2);
	cout<<sq2 -> ch<<endl;
	cout<<"enter two str to compare"<<endl;
	build(sq1);
	build(sq2);
	i = compare(sq1, sq2);
	if(i < 0) {
		cout<<"sq2 > sq1"<<endl;
	}
	else if(i == 0) {
		cout<<"sq2 = sq1"<<endl;
	}
	else {
		cout<<"sq1 > sq2"<<endl;
	}
	return 0;
} 
