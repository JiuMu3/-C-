#include <iostream>
using namespace std;
enum STATUS{OK,ERROR,WARN};
template<typename T>
class listWhileChainNode{
public:
	listWhileChainNode(T val):data(val),next(nullptr){}
	T data;
	listWhileChainNode<T> *next;
};
template<typename T>
class listWhileChain{
public:
	//尾指针
	listWhileChainNode<T> *tail;
	int len;
	listWhileChain():len(0),tail(nullptr){}
	~listWhileChain(){
		//temp指向第一个链表
		listWhileChainNode<T> *temp;
		listWhileChainNode<T> *temp_2;
		temp=this->tail->next;
		
		while(temp!=nullptr){
			temp_2=temp->next;
			delete temp;
			temp=temp_2;
		}
		this->len=0;
	}
};
//链表是否为空
template<typename T>
STATUS isEmpty(listWhileChain<T> &L,bool &isEmpty){
	isEmpty=(L.len==0);
	return OK;
}
//获取链表长度
template<typename T>
STATUS getListLen(listWhileChain<T> &L,int &len){
	len=L.len;
	return OK;
}
//插入元素到对应位置前方
template<typename T>
STATUS listInsertElem(listWhileChain<T> &L,int pos,T e){
	if(pos<1||pos>L.len+1){
		cout<<"超出数组界限"<<endl;
		return ERROR;
	}
	listWhileChainNode<T> *newNode=listWhileChainNode<T>(e);
	bool isempty;
	isEmpty(L,isempty);
	if(isempty){
		//说明没有元素
		L.tail=newNode;
		newNode->next=newNode;
	}else{
		//指向链表的头部
		listWhileChainNode<T> *temp=L.tail->next;
		for(int i=0;i<pos-1;i++){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	L.len++;
	return OK;
}

//删除对应位置链表,并且返回对应数据
template<typename T>
STATUS listDeleteElem(listWhileChain<T> &L,int pos,T &e){
	bool isempty;
	isEmpty(L,isempty);
	if(isempty){
		cout<<"链表为空"<<endl;
		return ERROR;
	}
	
	if(pos<1||pos>=L.len){
		cout<<"超出链表边界"<<endl;
		return ERROR;
	}
	
	listWhileChainNode<T> *temp=L.tail->next;
	for(int i=0;i<pos-1;i++){
		temp=temp->next;
	}
	temp->next=temp->next->next;
	delete temp->next;
	L.len--;
	
	return OK;
}
int main(){
	return 0;	
}
