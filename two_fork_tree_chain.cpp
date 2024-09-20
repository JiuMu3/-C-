#include <iostream>
using namespace std;
template<typename T>
class BitNode{
public:
	BitNode(){}
	BitNode(T val):data(val),lchild(nullptr),rchild(nullptr){}
	T data;
	//左孩子和右孩子
	BitNode<T> *lchild,*rchild;
	~BitNode(){
		delete lchild;
		delete rchild;
	}
	
	//method
	void setLchild(BitNode<T> *temp){
		if(temp!=nullptr){
			lchild=temp;
			return;
		}
		return;
	}
	void setRchild(BitNode<T> *temp){
		if(temp!=nullptr){
			rchild=temp;
			return;
		}
		return;
	}
};
template<typename T>
class BitTree{
public:
	BitTree():count(0),depth(0){}
	BitTree(T val):count(1),depth(1){
		BASE=new BitNode<T>(val);
	}
public:
	BitNode<T> *BASE;
	int depth;
	int count;
public:
	~BitTree(){
		delete BASE;
		BASE=nullptr;
		count=0;
		depth=0;
	}
};

//前序遍历
template<typename T>
void PreOrderTraverse(BitNode<T> *bittree){
	if(bittree==nullptr){
		return;
	}
	//注意，自定义类型必须重载<<运算符
	cout<<bittree->data<<endl;
	PreOrderTraverse(bittree->lchild);
	PreOrderTraverse(bittree->rchild);
}

//中序遍历
template<typename T>
void InOrderTraverse(BitNode<T> *bittree){
	if(bittree==nullptr) return;
	
	InOrderTraverse(bittree->lchild);
	cout<<bittree->data<<endl;
	InOrderTraverse(bittree->rchild);
}

//后序遍历
template<typename T>
void PostOrderTraverse(BitNode<T> *bittree){
	if(bittree==nullptr) return;
	
	InOrderTraverse(bittree->lchild);
	InOrderTraverse(bittree->rchild);
	cout<<bittree->data<<endl;
}

//创建二叉树
//这里Data类似于char类型
template<typename T>
void CreateBitTree(BitNode<T> *e){
	T Data;
	cin>>Data;
	if(Data=='#'){
		*e=NULL;
	}
	
	else{
		e=new BitNode<T>(Data);
		if(!e) exit(1);
		
		CreateBitTree(e->lchild);
		CreateBitTree(e->rchild);
	}
}

int main(){
	return 0;
}
