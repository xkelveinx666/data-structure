#include<iostream>
using namespace std;
typedef int datatype;
const int maxsize = 100;
typedef struct{
	datatype data[maxsize];
	int n;
}sqlist;
void print(sqlist *l){
	int j = l->n;
	while(j-- > 0){
		cout<<l->data[l -> n-j - 1];
		cout<<" ";
	}
}
void initial(sqlist *l){
	int j = l -> n;
	while(j-- > 0)
		cin>>l->data[l -> n-j - 1];
}
int locate(sqlist *l,datatype x){
	if(l->n == 0)
		return -1;
	for(int i = 0;i < l->n / 2 + 1; i++){
		if(l -> data[i] == x){
			return i;
		}
		if(l -> data[l -> n -i - 1] == x){
			return l -> n-i;
		}
	}
	return -1;
}
void intersect(sqlist *l1,sqlist *l2){
	int l1_n = l1->n,l2_n = l2->n;
	int s = 0;
	for(int i = 0;i < l1_n;i++){
		if(locate(l2,l1->data[i]) == -1){
			l1 -> data[i] = l1 ->data[i - s];
			s++;
		}			
	}
	l1 -> n -= s;
}
int main(){
	sqlist list1, list2, *l1, *l2;
	list1.n = 4;
	list2.n = 4;
	l1 = &list1;
	l2 = &list2;
	initial(l1);
	initial(l2);
	cout<<"list1:";
	print(l1);
	cout<<endl;
	cout<<"list2:";
	print(l2);
	cout<<endl;
	intersect(l1,l2);
	cout<<"intersect:";
	print(l1);
}
