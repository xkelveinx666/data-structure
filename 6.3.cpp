#include<iostream>
#include<string.h>
using namespace std;
#define datatype string
#define pointer struct node *
struct node{
	datatype name;
	datatype sex;
	pointer next;
};
typedef struct{
	pointer front;
	pointer rear;
}lkqueue;
void init_lkqueue(lkqueue *ls){
	pointer p = new node;
	p -> next = NULL;
	ls -> front = p;
	ls -> rear  = p; 
}
bool empty_lkqueue(lkqueue *ls){
	if(ls -> front == ls -> rear){
		cout<<"队空"<<endl;
		return true;
	} 
	else
		return false;	
}
void en_lkqueue(lkqueue *ls, datatype name, datatype sex) {
	pointer p = new node;
	p -> next = NULL;
	p -> name = name;
	p -> sex = sex;
	ls -> rear -> next = p;
	ls -> rear = p;
	return;
}
int de_lkqueue(lkqueue *ls, datatype *name, datatype *sex) {
	if(empty_lkqueue(ls) == 1) {
		return 0;
	}
	pointer p = ls -> front;
	ls -> front = p -> next;
	*name = p -> next -> name;
	*sex = p -> next -> sex;
	delete p;
}
datatype gethead_lkqueue(lkqueue *ls){
	if(empty_lkqueue(ls)) {
		return NULL;
	}
	else{
		return	ls -> rear -> name; 
	}
}
void print(lkqueue *ls){
	if(empty_lkqueue(ls) == 1) {
		return;
	}
	pointer p = ls -> front -> next;
	cout<<p -> name;
	cout<<" ";
	cout<<p -> sex;
	p = p -> next;
	while(p != NULL){
		cout<<" -> ";
		cout<<p -> name;
		cout<<" ";
		cout<<p -> sex;
		p = p -> next;
	}
	cout<<endl;
	return;
}
void build(lkqueue *lm,lkqueue *lf) {	
	int i = 1;
	string male = "男";
	string female = "女";
	string end = "$";
	cout<<"请用中文输入,输入$停止输入"<<endl; 
	while(true){
		datatype name, sex;
		cout<<"请输入第";
		cout<<i++;
		cout<<"个嘉宾的名字"<<endl; 
		cin>>name;
		if(name.compare(end) == 0){
			return;
		}
		cout<<"请输入该嘉宾的性别"<<endl;
		cin>>sex;
		if(sex.compare(end) == 0){
			return;
		}
		if(sex.compare(male) == 0) {
			en_lkqueue(lm, name, sex);
		}
		else if(sex.compare(female) == 0){
			en_lkqueue(lf, name, sex);
		}
	}
}
void pairPeople(lkqueue *lm,lkqueue *lf) {
	pointer p = lm -> front -> next;
	pointer q = lf -> front -> next;
	while(p != NULL && q != NULL) {
		cout<<p -> name;
		cout<<" 与 ";
		cout<<q -> name;
		cout<<"配对"<<endl;;
		q = q -> next;
		p = p -> next;
	}
	int i = 0;
	while(p != NULL) {
		if(i == 0){
			cout<<"下一轮舞曲开始时第一个可获得舞伴的人是";
			cout<<p -> name;
		}
		i++;
		p = p -> next;
	}
	while(q != NULL) {
		if(i == 0){
			cout<<"下一轮舞曲开始时第一个可获得舞伴的人是";
			cout<<q -> name<<endl;
		}
		i++;
		q = q -> next;
	}
	cout<<"还有";
	cout<<i;
	cout<<"人未配对";
}
int main(void){
	lkqueue malequeue, femalequeue;
	lkqueue *lm = &malequeue;
	lkqueue *lf = &femalequeue;
	init_lkqueue(lm);
	init_lkqueue(lf);
	build(lm, lf);
	cout<<"男嘉宾"<<endl;
	print(lm);
	cout<<"女嘉宾"<<endl;
	print(lf);
	pairPeople(lm, lf);
	return 0;
} 
