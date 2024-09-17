#include <iostream>
using namespace std;
enum STATUS{OK,ERROR,WARN};
template<typename T>
class MyQueueNode{
public:
	MyQueueNode():next(nullptr){}
	MyQueueNode(T val):next(nullptr),data(val){}
	T data;
	MyQueueNode<T> *next;
};
template<typename T>
class MyQueueChain{
public:
	MyQueueChain():count(0),front(new MyQueueNode<T>),rear(front){}
	MyQueueNode<T> *front,*rear;
	int count;
	~MyQueueChain(){
		
	}
};

//入队操作
template<typename T>
STATUS QueuePush(MyQueueChain<T> &L,T e){
	MyQueueNode<T> *temp=new MyQueueNode<T>(e);
	L.rear->next=temp;
	L.rear=temp;
	L.count++;
	return OK;
}
//判断队列是否为空
template<typename T>
bool isEmpty(MyQueueChain<T> &L){
	return L.count==0;
}
//出队操作
template<typename T>
STATUS QueuePop(MyQueueChain<T> &L,T &e){
	if(isEmpty(L)){
		cout<<"出错，队列为空"<<endl;
		return ERROR;
	}
	MyQueueNode<T> *temp=L.front->next;
	e=temp->data;
	L.front->next=temp->next;
	delete temp;
	temp=nullptr;
	L.count--;
	return OK;
}
//返回队列的元素数量
template<typename T>
int getQueueCount(MyQueueChain<T> &L){
	return L.count;
}
//按值查找
template<typename T>
int getElemByVal(MyQueueChain<T> &L,T e){
	if(isEmpty((L))){
		cout<<"队列为空"<<endl;
		return ERROR;
	}
	
	int i=0;
	MyQueueNode<T> *temp=L.front->next;
	while(temp->data!=e){
		temp=temp->next;
		i++;
	}
	return i;
}
int main(){
	return 0;
}
