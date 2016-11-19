#include<iostream>
using namespace std;
#define MAXSIZE 100
#define datatype int
typedef struct {
	int i, j;
	datatype val;
}nodetype;
typedef struct {
	int m, n;
	int t;
	nodetype data[MAXSIZE];
}spmatrix;
void initiate(spmatrix *sp) {
	int m, n, t = 0;
	cout<<"��������"<<endl;
	cin>>m;
	cout<<"��������"<<endl;
	cin>>n;
	sp -> m = m;
	sp -> n = n;
	while(t != m * n) {
		cout<<"���������кţ��кţ�Ԫ��ֵ,�к�Ϊ0ʱ�˳�"<<endl;
		cin>>sp -> data[t].i;
		if(sp -> data[t].i == 0)
			break;
		cin>>sp -> data[t].j;
		cin>>sp -> data[t].val;
		t++;
	}
	sp -> t = t;
	return;
}
void reverse(spmatrix *sp) {
	cout<<"����ת��"<<endl;
	int t = sp -> t;
	int temp;
	temp = sp -> m;
	sp -> m = sp -> n;
	sp -> n = temp;
	while(t-- > 0) {
		temp = sp -> data[t].i;
		sp -> data[t].i = sp -> data[t].j;
		sp -> data[t].j = temp;
	}
	return;
}
void print(spmatrix *sp) {
	int m, n, t;
	cout<<"��ʾϡ�����"<<endl;
	m = sp -> m;
	n = sp -> n;
	t = sp -> t;
	int matrix[n][m];
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			matrix[i][j] = 0;
		}
	}
	while(t-- > 0) {
		matrix[sp -> data[t].i - 1][sp -> data[t].j - 1] = sp -> data[t].val;
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cout<<matrix[i][j];
			cout<<"   ";
		}
		cout<<endl;
	}
	return;
}
int main(void) {
	spmatrix spmat;
	spmatrix *sp = &spmat;
	initiate(sp);
	print(sp);
	reverse(sp);
	print(sp);
	return 0;
}
