#include <iostream>
enum STATUS{OK,ERROR,WARN};
#define MAX_SIZE 1024
using namespace std;
template<typename T>
//静态链表中头(下标为0)的cur指向第一个空的元素，最后一个则的cur指向第一个有数值的元素，最后一个有效元素的cur指向第一个元素即0，类似指针链表的next==nullptr

//插入元素的时候相当于将新元素放在第一个空闲的位置
//而数组头的cur就指向第一个空闲的位置

//而删除操作，则相当于是将被删除的元素放到数组头元素的cur里
//这样相当于被删除的元素成为了第一个空闲的位置

//使用数组实现类似链表的操作，适用于没有指针的编程语言
//静态链表节点
class staticListChainNode{
public:
    T data;
    int cur;
};
//静态链表
template<typename T>
class staticListChain{
public:
	staticListChain():listLen(0){}
	staticListChainNode<T> LIST[MAX_SIZE];
	int listLen;
	
	~staticListChain(){
		
	}	
};
//数组的插入操作
//数组的初始化操作
template<typename T>
STATUS listInit(staticListChain<T> &L){
    int i;
    for(i=0;i<MAX_SIZE-1;i++){
        L.LIST[i].cur = i + 1;
    }
    L.LIST[MAX_SIZE - 1].cur = 0;
    return OK;
}
//静态链表插入操作
//申请新空间函数
template<typename T>
STATUS SLL_Malloc(staticListChain<T> &L,int &pos){
	//数组的头存储着第一个空闲空间的位置，将其赋值给i
	//当数组满的时候i将会是0
	int i=L.LIST[0].cur;
	//判断当前数组头的cur(下一个数组地址)是否是末尾，是的话由于最后一个元素存储的是第一个元素的下角标0
	//将不会进行赋值，当不是最后一个元素，就申请后面的元素地址
	if(L.LIST[0].cur){
		L.LIST[0].cur=L.LIST[i].cur;
	}
	pos=i;
	return OK;
}

template<typename T>
STATUS FREE_SLL(staticListChain<T> &L,int k){
	//这里其实相当于是要被删除的元素成为了数组头元素的cur
	//当再次插进新元素的时候，直接就插进被删除的元素的位置了
	L.LIST[k].cur=L.LIST[0].cur;
	L.LIST[0].cur=k;
}
//插入操作
template<typename T>
STATUS listInsert(staticListChain<T> &L,int pos,T &e){
	int l,j,k;
	k=MAX_SIZE-1;
	if(pos<1||pos>MAX_SIZE+1){
		cout<<"超出数组边界"<<endl;
		return ERROR;
	}
	
	SLL_Malloc(L,j);
	//只要j不为0就可以执行
	if(j){
		L.LIST[j].data=e;
		//找到要插入的数组位置
		//如果插入的位置是1
		if(pos==1){
			L.LIST[j].cur = L.LIST[MAX_SIZE - 1].cur; // 新节点的 cur 指向原来的第一个有效节点
			L.LIST[MAX_SIZE - 1].cur = j; // 头节点指向新插入的节点
		}
		else{
			for(l=1;l<=pos-1;l++){
				k=L.LIST[k].cur;
			}
			
			L.LIST[j].cur=L.LIST[k].cur;
			e=L.LIST[j].data;
			
			L.LIST[k].cur=j;
		}

		
		L.listLen++;
		return OK;
	}
	return ERROR;
}

//静态链表的删除操作
template<typename T>
STATUS listDelete(staticListChain<T> &L,int pos,T &e){
	int j,k;
	if(pos<1||pos>L.listLen){
		return ERROR;
	}
	k=MAX_SIZE-1;
	for(j=1;j<=pos-1;j++){
		k=L.LIST[k].cur;
	}
	//j对应的数组元素就是要被删除的元素
	j=L.LIST[k].cur;
	//让被删除元素的前一个元素直接指向要被删除元素的下一个元素位置
	L.LIST[k].cur=L.LIST[j].cur;
	FREE_SLL(L,j);
	L.listLen--;
	return OK;
}

//静态链表的查找
template<typename T>
STATUS getListElem(staticListChain<T> &L,int pos,T &e){
	if(pos<1||pos>L.listLen){
		cout<<"超出数组边界"<<endl;
		return ERROR;
	}
	int k=MAX_SIZE-1;
	for(int i=1;i<=pos;i++){
		k=L.LIST[k].cur;
	}
	e=L.LIST[k].data;
	return OK;
}

int main()       
{                
    return 0;    
} 
