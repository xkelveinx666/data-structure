#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 100
#define datatype int
#define othertype int
typedef struct {
	datatype key;
	othertype other;
}rectype;
typedef rectype list[MAXSIZE + 1];
int createList(list R) {
	int i = 1;
	datatype x;
	while(cin>>x, x != -1) {
		R[i++].key = x;
	}
	return i;
}
void printList(list R, int n) {
	int i = 1;
	while(i != n) {
		cout<<R[i++].key<<" ";
	}
	cout<<endl;
}
void insertSort(list R, int n, int i, int h) {
	int j;
	for(i = i + h;i < n; i+= h) {
		if(R[i].key > R[i - h].key) {
			continue;
		}
		else {
			R[0] = R[i];
			j = i - h;
			do {
				R[j + h] = R[j];
				j -= h;
			}while(R[j].key > R[0].key && j > 0);
			R[j + h] = R[0];
		}
	}
}
void shellInsert(list R, int n, int h) {
	int i;
	int j;
	int k;
	for(i = 1;i <= h;i++) {
		insertSort(R, n, i, h);
	}
}
void shellSort(list R, int n, int d[], int t) {
	int i;
	for(i = t - 1;i >= 0;i--) {
		shellInsert(R, n, d[i]);
	}
}
void bubbleSort(list R, int n) {
	int i;
	int j;
	bool changeFlag;
	for(i = 1;i < n;i++) {
		changeFlag = false;
		for(j = 1;j <= n - i;j++) {
			if(R[j].key > R[j + 1].key) {
				changeFlag = true;
				R[0] = R[j];
				R[j] = R[j + 1];
				R[j + 1] = R[0];
			}
		}
		if(!changeFlag) {
			break;
		}
	}
}
void quickSort(list R,int s,int e) {
	if(s >= e) {
		return;
	}
	int i = s;
	int j = e;
	R[0] = R[s];
	while(i < j) {
		while(i < j && R[j].key >= R[0].key) {
			j--;
		}
		if(i < j) {
			R[i] = R[j];
		}
		while(i < j && R[i].key <= R[0].key) {
			i++;
		}
		if(i < j) {
			R[j] = R[i];
		}
	}
	R[i] = R[0];
	quickSort(R, s, i - 1);
	quickSort(R, i + 1, e);
}
void selectSort(list R, int i, int n) {
	if(i + 1 == n) {
		return;
	}
	int j;
	R[0] = R[i];
	int k;
	for(j = i + 1;j < n;j++) {
		if(R[j].key < R[0].key) {
			R[0] = R[j];
			k = j;
		}	
	}
	R[k] = R[i];
	R[i] = R[0];
	printList(R, n);
	selectSort(R, i + 1, n);
}
int main(void) {
	list R;
	int n;
	int d[] = {1,3,5};
	int t = 3;
	int judge; 
	while(true){
		cout<<"输入0建立顺序表，输入1输出顺序表，输入2直接插入排序\n"
		"输入3希尔排序，输入4冒泡排序，输入5快速排序输入6直接选择排序"<<endl;
		cin>>judge;
		switch(judge){
			case 0:cout<<"建立顺序表"<<endl;n = createList(R);cout<<endl;break;
			case 1:cout<<"输出顺序表"<<endl;printList(R, n);cout<<endl;break;
			case 2:cout<<"直接插入排序"<<endl;insertSort(R, n, 1, 1);cout<<endl;break;
			case 3:cout<<"希尔排序"<<endl;shellSort(R, n, d, 3);cout<<endl;break;
			case 4:cout<<"冒泡排序"<<endl;bubbleSort(R, n);cout<<endl;break;
			case 5:cout<<"快速排序"<<endl;quickSort(R, 1, n);cout<<endl;break;
			case 6:cout<<"直接选择排序"<<endl;selectSort(R, 1, n);cout<<endl;break;
			default:return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//49 38 65 97 76 13 27 49 -1
