#include <iostream>
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
void change(sqlist *l,int i ,int j){
	datatype temp;
	temp = l->data[i];
	l->data[i] = l->data[j];
	l->data[j] = temp;
}
void exchange(sqlist *l){
	int i = 0;
	int j = l -> n - 1;
	while(i != j){
		if(l->data[i] < 0)
			i++;
		else
			while(i != j){
				if(l->data[j] > 0)
					j--;
				else{
					change(l,i,j);
					break;
				}
			}	
	}
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
	exchange(l);
	print(l);
	return 0;
}
