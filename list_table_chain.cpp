#include <iostream>
using namespace std;
enum STATUS{OK,ERROR,WARN};
template<typename T>
class MyListChainNode{
public:
	MyListChainNode():Next(nullptr){}
	T dataElem;
	MyListChainNode* Next;
};
//线性链表
template<typename T>
class MyListChain{
public:
	MyListChain():chainLen(0),nodehead(new MyListChainNode<T>),nodeback(nodehead){}
	MyListChainNode<T> *nodehead;
	MyListChainNode<T> *nodeback;
	int chainLen;
	~MyListChain(){
		MyListChainNode<T> *current=nodehead;
		while(current!=nullptr){
			MyListChainNode<T> *temp=current->Next;
			delete current;
			current=temp;
		}
	}
};
//线性表的删除
template<typename T>
STATUS listDelete(MyListChain<T> &L){
	delete &L;
	return OK;
}

//单链表的存储
template<typename T>
STATUS getListElem(MyListChain<T> &L,int i,MyListChainNode<T> &e){
	if(L.chainLen==0){
		return ERROR;
	}

	if(i<1||i>L.chainLen){
		cout<<"超出链表范围"<<endl;
		return ERROR;;
	}
	
	MyListChainNode<T> *temp=L.nodehead;
	for(int j=1;j<=i;j++){
		temp=temp->Next;
	}
	e=*temp;
	return OK;
}

//单链表的插入
template<typename T>
STATUS listInsert(MyListChain<T> &L,T &e,int pos){
	if(pos<1||pos>L.chainLen+1){
		cout<<"超出链表范围"<<endl;
		return ERROR;
	}
	MyListChainNode<T> *temp=L.nodehead;
	for(int i=0;i<pos;i++){
		temp=temp->Next;
	}
	
	MyListChainNode<T> *temp_2=new MyListChainNode<T>();
	temp_2->dataElem=e;

	temp_2->Next=temp->Next;
	temp->Next=temp_2;

	L.chainLen++;
	return OK;
}
//单链表的删除
template<typename T>
STATUS listDelete(MyListChain<T> &L,int pos,T &e){
	if(pos<1||pos>L.chainLen){
		cout<<"超出链表边界"<<endl;
		return ERROR;
	}
	
	MyListChainNode<T> *temp=L.nodehead;
	for(int i=0;i<pos-1;i++){
		temp=temp->Next;
	}
	MyListChainNode<T> *temp_1=temp->Next;
	e=temp_1->dataElem;
	temp->Next=temp_1->Next;
	
	delete temp_1;
	L.chainLen--;
	return OK;
}
int main()
{
	return 0;
}
