#include <iostream>
enum STATUS{OK,ERROR,WARN};
#define MAX_SIZE 1024
using namespace std;
template<typename T>
class MyInnListOrder{
public:
	MyInnListOrder():top(0){}
	T LIST[MAX_SIZE];
	int top;
};
//入栈操作
template<typename T>
STATUS push_top(MyInnListOrder<T> &L,T e){
	if(L.top==MAX_SIZE-1){
		cout<<"栈已满"<<endl;
		return ERROR;
	}
	L.LIST[L.top]=e;
	L.top++;
	return OK;
}

//出栈操作
template<typename T>
STATUS pop_top(MyInnListOrder<T> &L,T &e){
	if(L.top==0){
		cout<<"栈是空的"<<endl;
		return ERROR;
	}
	
	e= L.LIST[L.top];
	L.top--;
	return OK;
}
//栈是否为空
template<typename T>
STATUS isEmpty(bool &isempty,MyInnListOrder<T> &L){
	isempty=(L.top==0);
	return OK;
}

//返回栈中元素个数
template<typename T>
STATUS getInnNum(MyInnListOrder<T> &L,int &num){
	num=L.top+1;
	return OK;
}

//清空栈
template<typename T>
STATUS clearInn(MyInnListOrder<T> &L){
	if(L.top==0){
		return OK;
	}
	L.top=0;
	return OK;
}

int main(){
	return 0;
}
