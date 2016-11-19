#include<iostream>
using namespace std;
#define datatype int
#define M 10
#define N 3
typedef datatype R[N];
void initiate(R x[]) {
	cout<<"初始化二维数组，输入-10提前结束行"<<endl;
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < M;j++) {
			cin>>x[i][j];
			if(x[i][j] == -10) {
				break;
			}
		}
	}
	return;
}
datatype read(R x[], int i, int j) {
	return x[i][j];
}
void write(R x[], int i, int j,datatype k) {
	x[i][j] = k;
}
void print(R x[]) {
	cout<<"输出数组"<<endl;
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < M;j++) {
			if(x[i][j] == -10)
				break;
			cout<<x[i][j];
			cout<<"  ";
		}
		cout<<endl;
	}
	return;
}
int main(void) {
	R x[M];
	initiate(x);
	print(x);
	cout<<"read & write"<<endl;
	cout<<read(x, 0, 1)<<endl;
	write(x, 0, 1, 198);
	cout<<read(x, 0, 1)<<endl;
	return 0;
} 
