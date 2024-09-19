#include <iostream>
using namespace std;
#define MAX_SIZE 1024
enum STATUS{ERROR,OK,WARN};
template<typename T>
//双亲表示法
class TreeNode{
public:
	T data;
	int parent;
};
template<typename T>
class TreeParent{
public:	
	//r保存根节点保存的位置
	TreeParent():r(0){}
	TreeNode<T> LIST[MAX_SIZE];
	int r,n;//n为当前节点存储的元素数量
};
//双亲-长子法,存储第一个长子的位置
template<typename T>
class TreePFirstNode{
public:
	TreePFirstNode(){}
	TreePFirstNode(T val):data(val){}
	TreePFirstNode(T val,int par):data(val),parent(par){}
	TreePFirstNode(T val,int par,int fir):data(val),parent(par),firChildren(fir){}
	T data;
	int parent,firChildren;
};
template<typename T>
class TreePFirst{
public:
	TreePFirst():r(0){}
	TreePFirstNode<T> LIST[MAX_SIZE];
	int r,n;
};
//双亲-兄弟
template<typename T>
class TreeBroNode{
public:
	TreeBroNode(){}
	TreeBroNode(T val):data(val){}
	TreeBroNode(T val,int par):data(val),parent(par){}
	TreeBroNode(T val,int par,int brot):data(val),parent(par),bro(brot){}
	T data;
	int parent,bro;
};

template<typename T>
class TreeBro{
public:
	TreeBro():r(0){}
	TreeBroNode<T> LIST[MAX_SIZE];
	int r,n;
};
int main(){
	return 0;
}
