#include <iostream>
#define CHILDREN_SIZE 4
#define MAX_TREE_SIZE 100
enum STATUS{ERROR,OK,WARN};
using namespace std;
template<typename T>
class TreeChildrenNodeStatic{
public:
	TreeChildrenNodeStatic(){
		for(int i=0;i<CHILDREN_SIZE;i++){
			Children[i]=nullptr;
		}
	}
	TreeChildrenNodeStatic(T val):data(val){
		for(int i=0;i<CHILDREN_SIZE;i++){
			Children[i]=nullptr;
		}
	}
	TreeChildrenNodeStatic(T val,TreeChildrenNodeStatic** children):data(val){
		for(int i=0;i<CHILDREN_SIZE;i++){
			Children[i]=children[i];
		}
	}
	T data;
	//四个指针，可以存储4个
	TreeChildrenNodeStatic<T>* Children[CHILDREN_SIZE];
};
template<typename T>
class TreeChildrenStatic{
public:
	TreeChildrenStatic():BASE(nullptr),Dgree(0){}
	TreeChildrenStatic(T val):Dgree(0){
		BASE=new TreeChildrenNodeStatic<T>(val);
	}
	TreeChildrenNodeStatic<T> *BASE;
	int Dgree;
};

//动态申请
template<typename T>
class TreeChildrenNodeDynamic{
public:
	TreeChildrenNodeDynamic():degree(0),Children(nullptr){}
	TreeChildrenNodeDynamic(int deg):degree(deg){
		Children=(TreeChildrenNodeDynamic<T>**)malloc(sizeof(TreeChildrenNodeDynamic<T>*)*degree);
		for(int i=0;i<degree;i++){
			Children[i]=nullptr;
		}
	}
	T data;
	int degree;
	TreeChildrenNodeDynamic<T>** Children;
	~TreeChildrenNodeDynamic(){
		for(int i=0;i<degree;i++){
			Children[i]->~TreeChildrenNodeDynamic();
			free(Children[i]);
		}
		free(Children);
		Children=nullptr;
	}
};

template<typename T>
class TreeChildrenDynamic{
public:
	TreeChildrenDynamic():BASE(nullptr),depth(0){}
	TreeChildrenDynamic(T val):depth(0){
		BASE->data=val;
	}
	TreeChildrenNodeDynamic<T> *BASE;
	int depth;	
};

//顺序结构和链表结构一起表示
template<typename T>
class CTNode{
public:
	int Children;
	CTNode<T> *next;
};

template<typename T>
class CTBox{
public:
	T data;
	CTNode<T> *firstchildren;
};

template<typename T>
class CT{
public:
	CTBox<T> Box[MAX_TREE_SIZE];
	int r,n;/*根的位置和节点数*/
};
int main(){
	return 0;
}
