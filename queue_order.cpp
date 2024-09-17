#include <iostream>
using namespace std;
enum STATUS{OK,ERROR,WARN};
#define MAX_SIZE 1024
template<typename T>
class MyQueue{
public:
	//初始化队列
	MyQueue():front(0),rear(0){}
	T Queue[MAX_SIZE];
	int front;
	int rear;
};
//获取队列长度
template<typename T>
int getQueueLen(MyQueue<T> &L){
	return (L.rear-L.front+MAX_SIZE)%MAX_SIZE;
}
//入队操作
template<typename T>
STATUS QueuePush(T e,MyQueue<T> &L){
	if((L.rear+1)%MAX_SIZE==L.front){
		cout<<"数组已满"<<endl;
		return ERROR;
	}
	L.Queue[L.rear+1]=e;
	L.rear= (L.rear+1)%MAX_SIZE;
	
	return OK;
}
//出队操作
template<typename T>
STATUS QueuePop(MyQueue<T> &L,T &e){
	if(getQueueLen(L)==0){
		cout<<"数组为空"<<endl;
		return ERROR;
	}
	e=L.Queue[L.front];
	L.front=(L.front+1)%MAX_SIZE;
	return OK;
}
//清空队列
template<typename T>
STATUS QueueClear(MyQueue<T> &L){
	L.front=L.rear=0;
	return OK;
}
int main(){
	return 0;
}
