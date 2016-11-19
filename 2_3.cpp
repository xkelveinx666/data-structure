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
		if(data == -1)
			break;
		else
			l -> data[i] = data;
	}
	if(data == -1)
		i--;
	l -> n = i + 1;
}
void deleteZero(sqlist *l){
	int s = 0;
	for(int i = 0;i < l->n;i++){
		if(l->data[i] == 0){
			s++;						
		}
		else
			l->data[i - s] = l->data[i];
	}
	l->n -= s;
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
	deleteZero(l);
	print(l);
	return 0;
}
