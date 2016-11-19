#include<iostream>
#include<time.h>
using namespace std;
int main(void){
	int start = clock();
	int n = 4;
	int a[n][n];
	for(int i = 0; i < n;i++){
		for(int j = 0;j < n;j++){
			a[i][j] = 1;
			cout<<a[i][j];
			cout<<" ";
		}
		cout<<""<<endl;
	}
	cout<<"delete"<<endl;
	int b = 0;
	for(int i = 0; i < n;i = i * 2 + 1){
		for(int j = 0;j < i;j++){
			a[i][j] = 0;
			b++;
		}
	}
	cout<<b<<endl;
	for(int i = 0; i < n;i++){
		for(int j = 0;j < n;j++){
			cout<<a[i][j];
			cout<<" ";
		}
		cout<<""<<endl;
	}
	int end = clock();
	cout<<end - start<<endl;
	cout<<"T(n) = 2*n - 2 - log2n, O(n) = n"<<endl;
}
