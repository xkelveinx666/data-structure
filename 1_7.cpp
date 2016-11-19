#include<iostream>
#include<time.h>
using namespace std;
int main(void){
//1.7.1
	double start = clock();
	double n = 10000000,sum = 0;
	for(int i = 0;i < n;i++){
		sum += i;
	}
	double end = clock();
	cout<<"1.7.1"<<endl;
	cout<<end - start<<endl; 
	cout<<"T(n) = n , O(n) = n"<<endl;
//1.7.2
	start = clock();
	sum = 0;
	for(int i = 1;i < n; i+=2){
		sum += i;
	}
	end = clock();
	cout<<"1.7.2"<<endl;
	cout<<end - start<<endl;
	cout<<"T(n) = n / 2 , O(n) = n"<<endl;
//1.7.3
	start = clock();
	sum = 0;
	for(int i = 0;sum < n;i++){
		sum += i;
	}
	end = clock();
	cout<<"1.7.3"<<endl;
	cout<<end - start<<endl;
	cout<<"T(n) = (2n + 1/4) ^ 1/2 + 1/2 , O(n) = n ^ 1/2"<<endl;
}
