#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class BitNode{
public:
	BitNode():lchild(nullptr),rchild(nullptr){}
	BitNode(T val):data(val),lchild(nullptr),rchild(nullptr){}
	T data;
	BitNode<T> *lchild,*rchild;
};

//树节点定义
template<typename T>
class TreeNode{
public:
	TreeNode(){}
	TreeNode(T val):data(val){}
	T data;
	vector<TreeNode<T>*> children;
};

//树转换为二叉树
template<typename T>
BitNode<T>* TreeToBit(TreeNode<T> *root){
	if(root==nullptr){
		return nullptr;
	}
	//初始化根节点
	BitNode<T> *BitRoot=new BitNode<T>(root->data);
	
	//如果该节点有孩子，将第一个孩子转换为左子节点
	if(!root->children.empty()){
		BitRoot->lchild=TreeToBit(root->children[0]);
	}
	
	//遍历该节点的所有兄弟节点，将其转换为右子节点
	BitNode<T> *current=BitRoot->lchild;
	for(int i=1;i<root->children.size();++i){
		current->right = TreeToBit(root->children[i]);
		current = current->right;
	}
	
	return BitRoot;
}

//二叉树转换回树
template<typename T>
TreeNode<T>* BitToTree(BitNode<T> *root){
	if(root=nullptr) return nullptr;
	//只要二叉树节点不为空，就将左孩子存放进树节点里面的孩子里面
	TreeNode<T> *treeNode=new TreeNode<T>(root->data);
	
	if(root->lchild!=nullptr){
		treeNode->children.push_back(BitToTree(root->lchild));
	}
	
	//处理二叉树的右子节点（兄弟节点），将其添加为当前节点的兄弟
	BitNode<T>* sibling = root->right;
	while (sibling != nullptr) {
		treeNode->children.push_back(BitToTree(sibling));
		sibling = sibling->right;
	}
	
	return treeNode;
}
int main(){
	return 0;
}
