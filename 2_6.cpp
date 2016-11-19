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
void transfer(sqlist *l1, sqlist *l2, sqlist *l3){
	int j = 0, k = 0;
	for(int i = 0;i < l1 ->n;i++){
		if(l1 ->data[i] >= 0)
			l2 -> data[j++] = l1 -> data[i];
		else
			l3 -> data[k++] = l1 -> data[i]; 
	}
	l2 -> n = j;
	l3 -> n = k;
}
void initiate(sqlist *l){
	int i = 0;
	datatype data;
	cin >> data;
	l -> data[i] = data;
	while(i < maxsize - 1){
		i++;
		cin >> data;
		if(data == 100)
			break;
		else
			l -> data[i] = data;
	}
	if(data == 100)
		i--;
	l -> n = i + 1;
}
int main(void){
	sqlist listA, listB, listC;
	sqlist *lA = &listA, *lB = &listB, *lC = &listC;
	initiate(lA);
	print(lA);
	transfer(lA,lB,lC);
	cout<<"b = ";
	print(lB);
	cout<<"c = ";
	print(lC);
	return 0;
}
