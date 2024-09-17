#include <iostream>
using namespace std;
enum STATUS{OK,ERROR,WARN};
template<typename T>
class MyNode{
public:
	MyNode():next(nullptr){}
	MyNode(T val):next(nullptr),data(val){}
	T data;
	MyNode<T> *next;
};
template<typename T>
class MyListStackChain{
public:
	MyListStackChain():top(nullptr),count(0){}
	MyListStackChain(MyNode<T> *first_node):top(first_node),count(0){}
	MyNode<T> *top;
	int count;
	//析构函数删除链表
	~MyListStackChain(){
		MyNode<T> *temp=this->top;
		while(temp!=nullptr){
			top=temp->next;
			delete temp;
			temp=top;
		}
	}
};
//当前栈的元素数量
template<typename T>
STATUS getElemCount(int &count,MyListStackChain<T> &L){
	count=L.count;
	return OK;
}
//判断当前栈是否为空
template<typename T>
STATUS isEmpty(MyListStackChain<T> &L,bool &isempty){
	isempty=(L.count==0);
	return OK;
}
//删除栈
template<typename T>
STATUS listDelete(MyListStackChain<T> &L){
	delete &L;
	&L=nullptr;
	return OK;
}
//入栈操作
template<typename T>
STATUS listPushStack(MyListStackChain<T> &L,T e){
	MyNode<T> *temp_top=new MyNode<T>(e);
	temp_top->next=L.top;
	L.top=temp_top;
	L.count++;
	return OK;
}
//出栈操作,并且返回元素
template<typename T>
STATUS listPopStack(MyListStackChain<T> &L,T *e){
	if(e!=nullptr){
		*e=L.top->data;
	}
	if(L.count==0){
		cout<<"栈为空"<<endl;
		return ERROR;
	}
	MyNode<T> *temp_delete=L.top;
	L.top=temp_delete->next;
	delete temp_delete;
	L.count--;
	return OK;
}

int main(){
	return 0;
}
