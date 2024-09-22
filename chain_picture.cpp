#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 1024
template<typename T>
class EdgeNode{
public:
	EdgeNode():Wedgit(1),nextNode(-1),next(nullptr){}
	EdgeNode(int val):Wedgit(1),nextNode(val),next(nullptr){}
	int Wedgit;
	EdgeNode<T> *next;
	//邻接序号
	int nextNode;
};
template<typename T>
class PointNode{
public:
	PointNode():first(nullptr){}
	PointNode(T val):data(val),first(nullptr){}
	T data;
	EdgeNode<T> *first;
	~PointNode(){
		EdgeNode<T> *temp;
		while(first!=nullptr){
			temp=first;
			first=first->next;
			delete temp;
		}
		first=nullptr;
	}
};

//链表和数组一起表示图
template<typename T>
class ChainArray{
public:
	PointNode<T> pointArray[MAXNUM];
	//顶点数和边数
	int pointNum,edgeNum;
};

//建立图的邻接表结构
template<typename T>
void CreateGraph(ChainArray<T> &G){
	//输入定点数和边数
	cout<<"请输入边数和顶点数"<<endl;
	cin>>G.pointNum;
	cin>>G.edgeNum;
	
	for(int i=0;i<G.pointNum;i++){
		cin>>G.pointArray[i].data;
		G.pointArray[i].first=nullptr;
	}
	int k,j;
	EdgeNode<T> *e;
	for(int i=0;i<G.edgeNum;i++){
		//j和k是边的两个顶点
		cout<<"请输入边的顶点下角标i和j"<<endl;
		cin>>k;
		cin>>j;
		e=new EdgeNode<T>(j);
		e->next=G.pointArray[k].first;
		G.pointArray[k].first=e;
		
		//由于无向图是对称的
		e=new EdgeNode<T>(k);
		e->next=G.pointArray[j].first;
		G.pointArray[j].first=e;
	}
}
//是否为空
template<typename T>
bool isEmpty(ChainArray<T> &P){
	return P.pointNum==0;
}
//删除某一个节点
template<typename T>
void deleteElem(int pos, ChainArray<T>& P) {
	if (isEmpty(P)) {
		cout << "邻接表为空" << endl;
		return;
	}
	if (pos < 0 || pos >= P.pointNum) {
		cout << "访问位置出界" << endl;
		return;
	}
	
	// 删除边
	EdgeNode<T>* temp = P.pointArray[pos].first;
	while (temp != nullptr) {
		EdgeNode<T>* nextEdge = temp->next;
		delete temp; // 删除边
		temp = nextEdge;
		P.edgeNum--; // 更新边数
	}
	
	// 逻辑上删除点（简单设为空或不使用）
	P.pointArray[pos].first = nullptr; // 设为空，表示已删除
	P.pointNum--;
}
//判断边是否存在
template<typename T>
bool EdgeIsExist(int i,int j,ChainArray<T> &P){
	if(P.pointNum==0){
		cout<<"数组空"<<endl;
		return false;
	}
	
	EdgeNode<T> *temp=P.pointArray[i].first;
	while(temp!=nullptr){
		if(temp->nextNode==j){
			return true;
		}
		temp=temp->next;
	}
	
	return false;
}
//删除某个边
template<typename T>
void deleteEdge(ChainArray<T> &P,int i,int j){
	if(isEmpty(P)){
		cout<<"数组为空"<<endl;
		return;
	}
	if(i<1||i>P.pointNum||j<1||j>P.pointNum){
		cout<<"访问数组出界"<<endl;
		return;
	}
	if(!EdgeIsExist(i,j,P)){
		cout<<"边不存在"<<endl;
		return;
	}
	
	EdgeNode<T> *temp=P.pointArray[i].first;
	EdgeNode<T> *pre;
	while(temp!=nullptr){
		if(temp->nextNode==j){
			pre->next=temp->next;
			delete temp;
		}
		pre=temp;
		temp=temp->next;
	}
	
	temp=P.pointArray[j].first;
	while(temp!=nullptr){
		if(temp->nextNode==i){
			pre->next=temp->next;
			delete temp;
		}
		pre=temp;
		temp=temp->next;
	}
	return;
}
//判断是否是满节点
template<typename T>
bool isMax(ChainArray<T> &P){
	return P.pointNum==MAXNUM;
}
//添加新元素(节点)
template<typename T>
void InsertNewElem(ChainArray<T> &P,T e){
	if(isMax(P)){
		cout<<"数组满"<<endl;
		return;
	}
	
	P.pointArray[P.pointNum].data=e;
	return;
}

//添加新边
template<typename T>
void InsertNewLine(ChainArray<T> &P,int i,int j,int w){
	if(i<1||i>P.pointNum||j<1||j>P.pointNum){
		cout<<"访问数组出界"<<endl;
		return;
	}
	
	if(EdgeIsExist(i,j,P)){
		return;
	}
	
	EdgeNode<T> *e;
	
	e=new EdgeNode<T>(j);
	e->Wedgit=w;
	e->next=P.pointArray[i].first;
	P.pointArray[i].first=e;
	
	e=new EdgeNode<T>(i);
	e->Wedgit=w;
	e->next=P.pointArray[j].first;
	P.pointArray[j].first=e;
	return;
}
enum Boolen{FALSE,TRUE};
Boolen visited[MAXNUM];
//深度优先遍历
template<typename T>
void DFS(ChainArray<T> &P,int i){
	visited[i]=TRUE;
	cout<<P.pointArray[i].data<<endl;
	
	EdgeNode<T> *temp;
	temp=P.pointArray[i].first;
	
	while(temp!=nullptr){
		if(visited[P.pointArray[temp->nextNode]]==FALSE){
			DFS(P,temp->nextNode);
		}
		temp=temp->next;
	}
}

template<typename T>
void DFSTraver(ChainArray<T> &P){
	//初始化visited数组
	for(int i=0;i<P.pointNum;i++){
		visited[i]=FALSE;
	}
	
	for(int i=0;i<P.pointNum;i++){
		if(visited[i]!=TRUE){
			DFS(P,i);
		}
	}
}

//广度优先遍历
template<typename T>
void BFS(ChainArray<T> &P){
	if(isEmpty(P)){
		cout<<"数组为空"<<endl;
		return;
	}
	EdgeNode<T> *p;
	//初始化visited数组
	for(int i=0;i<P.pointNum;i++){
		visited[i]=FALSE;
	}
	queue<int> BFS_QUEUE;
	
	for(int i=0;i<P.pointNum;i++){
		if(visited[i]==FALSE){
			visited[i]=TRUE;
			cout<<P.pointArray[i].data<<endl;
			BFS_QUEUE.push(i);
			
			while(!BFS_QUEUE.empty()){
				int temp=BFS_QUEUE.front();
				BFS_QUEUE.pop();
				p=P.pointArray[temp].first;
				
				while(p!=nullptr){
					if(visited[p->nextNode]==FALSE){
						visited[p->nextNode]=TRUE;
						cout<<P.pointArray[p->nextNode].data<<endl;
						
						BFS_QUEUE.push(p->nextNode);
					}
					p=p->next;
				}
			}
		}
	}
}
int main(){
	return 0;
}
