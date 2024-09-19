#include <iostream>
#include <math.h>
enum STATUS{OK,ERROR,WARN};
using namespace std;
//完全二叉树的顺序表表示方法
template<typename T>
class TwoForkTreeNode{
public:
	TwoForkTreeNode():flag('^'){}
	TwoForkTreeNode(T val):data(val),flag('^'){}
	T data;
	char flag;
};
template<typename T>
class TwoForkTreeOrder{
public:
	TwoForkTreeOrder(T val,int dep):depth(dep),curentPos(1){
		tree=new TwoForkTreeNode<T>[1<<dep];
		tree[0]=TwoForkTreeNode<T>(val);
		tree[0].flag='&';
		for(int i=1;i<1<<dep;i++){
			tree[i]=TwoForkTreeNode<T>();
		}
	}
	TwoForkTreeNode<T> *tree;
	int depth;
	int curentPos;
	~TwoForkTreeOrder(){
		delete[] tree;
	}
};
template<typename T>
bool isMax(TwoForkTreeOrder<T> &tree){
	return tree.tree[1<<tree.depth-1]!='^';
}
template<typename T>
bool isEmpty(TwoForkTreeOrder<T> &tree){
	return tree.tree[1].flag=='^';
}
//向树中存入数据
template<typename T>
STATUS pushElemToTree(T val,TwoForkTreeOrder<T> &tree){
	if(isMax(tree)){
		cout<<"数组已满"<<endl;
		return ERROR;
	}
	tree.tree[tree.curentPos].data=val;
	tree.tree[tree.curentPos].flag='&';
	tree.curentPos++;
	return OK;
}
//取出树中的数据 两种方式
//注意depth是从0开始的
//pos从1开始
template<typename T>
STATUS getElemRowCol(int depth,int pos,TwoForkTreeOrder<T> &tree,T &ReturnElem){
	int temp_depth=depth+1;
	if(temp_depth<1||temp_depth>tree.depth){
		cout<<"超出树深度"<<endl;
		return ERROR;
	}
	int temp_pos=pow(2,depth);
	if(pos<1||pos>temp_pos){
		cout<<"无法访问，超出当前深度的最多元素"<<endl;
		return ERROR;
	}
	
	int GetPos=pow(2,depth)+pos;
	ReturnElem=tree.tree[GetPos].data;
	return OK;
}

template<typename T>
STATUS getElem(int pos,T &e,TwoForkTreeOrder<T> &tree){
	int temp_pos=1<<tree.depth+1;
	if(pos<1||pos>temp_pos){
		cout<<"访问出界"<<endl;
		return ERROR;
	}
	e=tree.tree[pos-1].data;
	return OK;
}

//删除某一个节点数据 pos从1开始
template<typename T>
STATUS DeleteNode(TwoForkTreeOrder<T> &TREE,int pos){
	int temp_pos=1<<TREE.depth+1;
	if(pos<1||pos>temp_pos){
		cout<<"访问出界"<<endl;
		return ERROR;
	}
	
	TREE.tree[pos-1].flag='^';
}
int main(){
	return 0;
}
