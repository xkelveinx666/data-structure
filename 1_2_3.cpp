#include<iostream>
using namespace std;
typedef int datatype;
const int maxsize = 10;
typedef struct{
 	datatype data[maxsize];
 	int n;
}sqlist;
int change(sqlist *l){
	if(l ->n == 0)
		return -1;
	else if(l -> n == 1)
		return 0;
	datatype temp;
	for(int i = 0, j = l->n + 1;i < j;i++,j--){
	 	temp = l -> data[i];
	 	l -> data[i] = l -> data[j];
	 	l -> data[j] = temp;
	}
	return 1;
}
int initial(sqlist *l){
	int j = l->n;
	while(j-- > 0){
		cin >> l -> data[l -> n - j];
	}
}
int print(sqlist *l){
	int j = l->n;
	while(j-- > 0){
		cout << l -> data[l -> n-j];
		cout << " ";
	}
}
int main(void){
	sqlist list;
	list.n = 5;
	initial(&list);
	print(&list);
	cout <<endl;
	change(&list);
	print(&list);
} 
