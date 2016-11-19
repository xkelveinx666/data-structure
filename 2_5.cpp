#include<iostream>
using namespace std;
typedef int datatype;
const int maxsize = 5;
typedef struct{
	datatype data[maxsize];
	int n;
}sqlist;
void change(sqlist *l,int i ,int j){
	datatype temp;
	temp = l->data[i];
	l->data[i] = l->data[j];
	l->data[j] = temp;
}
int print(sqlist *l){
	int j = l->n;
	while(j-- > 0){
		cout << l -> data[l -> n - j - 1];
		cout << " ";
	}
	cout<<endl;
}
void rank(sqlist *l,int low,int high){
	if(low >= high)
		return;
	int i = low;
	int j = high;
	int key = l->data[i];
	while(i < j){
		while(i < j && l->data[j] >= key)
			j--;
		change(l,i,j);
		while(i < j && l->data[i] <= key)
			i++;
		change(l,i,j);
	}
	rank(l,low,i - 1);
	rank(l,i + 1,high);
}
void initiate(sqlist *l){
	int i = 0;
	datatype data;
	cin >> data;
	l -> data[i] = data;
	while(i < maxsize - 1){
		i++;
		cin >> data;
		if(data == -1)
			break;
		else
			l -> data[i] = data;
	}
	if(data == -1)
		i--;
	l -> n = i + 1;
	print(l);
	rank(l,0,l->n - 1);
}
int main(void){
	sqlist list;
	sqlist *l = &list;
	initiate(l);
	print(l);
	return 0;
}
