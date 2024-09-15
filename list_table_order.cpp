#include <iostream>
#define MAX_SIZE 256
typedef int STATUS;
#define OK 1
#define ERROR -1
using namespace std;
template<typename T>
class MyListOrder{
public:
	MyListOrder():CurrentSize(0){}
	~MyListOrder(){}
	T DataElem[MAX_SIZE];
	int CurrentSize; 
};
//新建一个线性表
template<typename T>
STATUS initList(MyListOrder<T> **L){
	*L=new MyListOrder<T>();
	if(*L!=NULL){
		return OK;
	}
	return ERROR;
}
//删除线性表
template<typename T>
STATUS deleteList(MyListOrder<T> **L){
	if(*L==nullptr){
		return ERROR;
	}
	delete *L;
	*L=nullptr;
	return OK;
}
//判断线性表是否为空
template<typename T>
STATUS isListEmpty(const MyListOrder<T> &L){
	if(L.CurrentSize==0){
		return OK;	
	}else{
		return ERROR;
	}
}
//清空线性表
template<typename T>
STATUS ClearList(MyListOrder<T> *L){
	if(L==nullptr){
		return ERROR;
	}
	else if(L->CurrentSize==0){
		return OK;
	}
	else{
		L->CurrentSize=0;
		return OK;
	}
}
//获取L中的第i个元素
template<typename T>
STATUS getElem(MyListOrder<T> &L,int i,T *e){
	if(i>L.CurrentSize||i<=0){
		return ERROR;
	}
	else{
		*e=L.DataElem[i-1];
		return OK;
	}
}
//查找相同元素
template<typename T>
STATUS LocateElem(int &Local,MyListOrder<T> &L,T &e){
	if(L.CurrentSize==0){
		return ERROR;
	}
	for(int i=0;i<L.CurrentSize;i++){
		if(e==L.DataElem[i]){
			Local=i+1;
			return OK;
		}
	}
	return ERROR;
}
//返回线性表的长度
template<typename T>
STATUS returnListLen(MyListOrder<T> &L,int &len){
	len=L.CurrentSize;
	return OK;
}
//在线性表L中的i位置插入元素
template<typename T>
STATUS listInsert(MyListOrder<T> &L,int i,T &e){
	if(L.CurrentSize==MAX_SIZE){
		cout<<"数组已满"<<endl;
		return ERROR;
	}
	if(i<1||i>L.CurrentSize+1){
		cout<<"超出数组边界"<<endl;
		return ERROR;
	}
	else{
		for(int j=L.CurrentSize-1;j>=i-1;j--){
			L.DataElem[j+1]=L.DataElem[j];
		}
		L.DataElem[i-1]=e;
		L.CurrentSize++;
		return OK;
	}
}
//删除L中的第i个元素，并且返回删除的元素
template<typename T>
STATUS listDelete(MyListOrder<T> &L,int j,T &e){
	if(L.CurrentSize==0){
		cout<<"数组为空"<<endl;
		return ERROR;
	}

	if(j<1||j>L.CurrentSize){
		cout<<"超出数组边界"<<endl;
		return ERROR;
	}
	else{
		e= L.DataElem[j-1];
		for(int i=j-1;i<L.CurrentSize-1;i++){
			L.DataElem[i]=L.DataElem[i+1];
		}
		L.CurrentSize--;
		return OK;
	}
}
int main()
{
	return 0;
}
