#include <iostream>
using namespace std;
enum STATUS{OK,ERROR};
enum PointerTag{LINK,Thread};//LINK表示左右孩子指针 Thread表示前驱后继
template<typename T>
class ThreadNode{
public:
	T data;
	ThreadNode<T> *lchild,*rchild;
	PointerTag LTAG;
	PointerTag RTAG;
};
//将普通二叉树变为线索二叉树
template<typename T>
void CreateThread(ThreadNode<T> *root,ThreadNode<T> *pre){
	if(root=nullptr){
		return;
	}
	CreateThread(root->lchild,pre);
	
	if(root->lchild==nullptr){
		root->lchild=pre;
		root->LTAG=Thread;
	}
	
	if(pre!=nullptr&&pre->rchild==nullptr){
		pre->rchild=root;
		pre->RTAG=Thread;
	}
	
	pre=root;
	
	CreateThread(root->rchild,pre);
}

//插入 data需要是int类型的
template<typename T>
ThreadNode<T>* insert(ThreadNode<T>* root, int key) {
	if (root == nullptr) {
		return new ThreadNode<T>(key);
	}
	
	if (key < root->data) {
		root->left = insert(root->left, key);
	} else if (key > root->data) {
		root->right = insert(root->right, key);
	}
	
	return root;
}


//遍历线索二叉树
template<typename T>
void inorderTraversal(ThreadNode<T>* root) {
	// 找到中序遍历的起点（最左边的节点）
	ThreadNode<T>* current = root;
	while (current != nullptr && !current->leftThread) {
		current = current->left;
	}
	
	// 开始遍历
	while (current != nullptr) {
		std::cout << current->data << " ";
		
		// 如果有线索，直接访问后继
		if (current->rightThread) {
			current = current->right;
		} else {
			// 否则，进入右子树，找到中序遍历的下一个节点
			current = current->right;
			while (current != nullptr && !current->leftThread) {
				current = current->left;
			}
		}
	}
}

int main(){
	return 0;
}
