#include<iostream>
using namespace std;
typedef int datatype;
const int maxsize = 5;
typedef struct{
	datatype data[maxsize];
	int n;
}sqlist;
void initiate(sqlist *l){
	int i = 0;
	datatype data;
	cin >> data;
	l -> data[i] = data;
	while(i < maxsize - 1){
		i++;
		cin >> data;
		if(data == 0)
			break;
		else
			l -> data[i] = data;
	}
	if(data == 0)
		i--;
	l -> n = i + 1;
}
int length(sqlist *l){
	return l->n;	
}
datatype get(sqlist *l,int i){
	if(l->n == 0)
		return -1;
	return l -> data[i - 1];
}
int locate(sqlist*l,datatype x){
	int n = l->n;
	if(n == 0)
		return -1;
	for(int i = 0;i < n;i++){
		if(x == l->data[i])
			return i + 1;
	}
	return -1;
}
int insert(sqlist *l, datatype x, int i){
	if(i > l ->n || i < 0){
		return 0;
	}
	if(l -> n == maxsize)
		return -1;
	for(int j = l->n - 1;j >= i - 1;j--){
		l->data[j + 1] = l ->data[j];
	}	
	l -> data[i - 1] = x;
	l -> n++ ; 
	return 1;
}
int deleteData(sqlist *l, int i){
	if(i > l->n || i < 0)
		return 0;
	if(l -> n == 0)
		return -1;
	for(int j = i - 1;j + 1< l->n;j++){
		l -> data[j] = l->data[j + 1]; 
	}
	l -> n--;
	return 1;
}
int print(sqlist *l){
	int j = l->n;
	while(j-- > 0){
		cout << l -> data[l -> n - j - 1];
		cout << " ";
	}
	cout<<endl;
}
int main(void){
	sqlist list;
	sqlist *l = &list;
	initiate(l);
	print(l);
	deleteData(l, 2);
	print(l);
	return 0;
} 
