#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(void){
	int n = 10;
	int a[n];
	for(int i = 0;i < n;i++){
		a[i] = rand(); 
	}
	int min = a[0];
	int max = a[0];
	for(int i = 0;i < n;i++){
		if(min > a[i])
			min = a[i];
		if(max < a[i])
			max = a[i];
	}		
	cout<<"min = ";
	cout<<min<<endl;
	cout<<"max = ";
	cout<<max<<endl;
}
