#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 1024
#define IFINITY 65535
template<typename T>
class PicPoint{
public:
	PicPoint():isempty(true){}
	T data;
	//判断当前节点是否存储数据
	bool isempty;
};

template<typename T>
class Picture{
public:
	Picture():pointNum(0),lineNum(0){}
	PicPoint<T> PointNum[MAXNUM];
	int PointLine[MAXNUM][MAXNUM];
	int pointNum,lineNum;
};

template<typename T>
void InitGraphic(Picture<T> *P){
	cout<<"输入边数:"<<endl;
	cin>>P->lineNum;
	cout<<"输入顶点数"<<endl;
	cin>>P->pointNum;
	//读入节点信息
	for(int i=0;i<P->pointNum;i++){
		//输入数据
		cin>>P->PointNum[i].data;
		P->PointNum[i].isempty=false;
	}
	//初始化邻接矩阵
	for(int i=0;i<P->pointNum;i++){
		for(int j=0;j<P->pointNum;j++){
			P->PointLine[i][j]=IFINITY;
		}
	}
	
	//给邻接矩阵输入数据
	for(int i=0;i<P->lineNum;i++){
		int k,j;
		cout<<"请输入对应邻接矩阵的下角标"<<endl;
		cin>>k;
		cin>>j;
		cout<<"请输入对应权重"<<endl;
		int w;
		P->PointLine[i][j]=w;
		P->PointLine[j][i]=P->PointLine[i][j];
	}
}
//判断树是否是满的
template<typename T>
void isMax(Picture<T> &P){
	return P.pointNum==MAXNUM+1;
}

//判断树是否是空的
template<typename T>
void isEmpty(Picture<T> &P){
	return P.pointNum==0;
}
//给一个节点插入数据
//pos从1开始
template<typename T>
void InsertElemBack(Picture<T> &P,T e){
	if(isMax(P)){
		cout<<"树已满"<<endl;
		return;
	}
	for(int i=0;i<MAXNUM;i++){
		if(P.PointNum[i].isempty){
			P.PointNum[i].data=e;
			P.PointNum[i].isempty=false;
			P.pointNum++;
		}
	}

	return;
}

//将两个节点连接起来
//i和j是要连接的两个节点的下角标
template<typename T>
void ConnectNode(Picture<T> &P,int i,int j,int k){
	if(i==j){
		cout<<"请勿输入相同角标"<<endl;
		return;
	}
	
	if(i<1||i>P.pointNum-1||j<1||j>P.pointNum){
		cout<<"输入的节点错误"<<endl;
		return;
	}
	
	P.PointLine[i][j]=j;
	P.PointLine[j][i]=P.PointLine[i][j];
	return;
}
//返回两个节点之间边的权重
template<typename T>
int GetLineWidget(Picture<T> &P,int i,int j){
	if(i<1||i>P.pointNum-1||j<1||j>P.pointNum){
		cout<<"输入的节点错误"<<endl;
		return -65535;
	}
	
	return P.PointLine[i][j];
}

//寻找图中是否有对应元素
template<typename T>
int getElemPos(Picture<T> &P,T e){
	if(isEmpty(P)) return -1;
	
	for(int i=0;i<P.pointNum;i++){
		if(e==P.PointNum[i]){
			return i;
		}
	}
	return -1;
}

//遍历图里面的所有元素并且输出
template<typename T>
void PrintAllElem(Picture<T> &P){
	for(int i=0;i<P.pointNum;i++){
		cout<<P.PointNum[i].data;
	}
	return;
}

//删除某节点
template<typename T>
void PopBack(Picture<T> &P,int pos){
	if(pos<1||pos>P.pointNum){
		cout<<"超出数组范围"<<endl;
		return;
	}
	//清空节点对应的边
	for(int i=0;i<P.pointNum;i++){
		P.lineNum[i][pos]=IFINITY;
		P.lineNum[pos][i]=IFINITY;
	}
	P.PointNum[pos].isempty=true;
	P.pointNum--;
	return;
}
enum Boolen{FALSE,TRUE};
Boolen visited[MAXNUM];
//将某一边清除
template<typename T>
void deleteLine(Picture<T> &P,int i,int j){
	if(i<1||i>P.pointNum-1||j<1||j>P.pointNum){
		cout<<"输入的节点错误"<<endl;
		return;
	}
	P.lineNum[i][j]=IFINITY;
	return;
}
template<typename T>
void DFS(Picture<T> &P,int i)
{
	visited[i]=TRUE;
	cout<<P.PointNum[i].data;
	for(int j=0;j<P.pointNum;j++){
		if(P.PointLine[i][j]==1&&visited[j]==FALSE){
			DFS(P,j);
		}
	}
}//深度优先遍历树
template<typename T>
void DFSTraver(Picture<T> &P){
	int i;
	for(i=0;i<P.pointNum;i++){
		visited[i]=FALSE;
	}
	
	for(i=0;i<P.pointNum;i++){
		if(visited[i]!=TRUE){
			DFS(P,i);
		}
	}
	
}

//广度优先遍历
//相当于只要是访问过的节点，访问完成后就立即入队
//当给出队的时候就要对与出队节点相连的节点进行访问
//在访问这些节点的时候再次进行入队
//直到队为空
template<typename T>
void BFS(Picture<T> &P){
	int i,j;
	queue<int> BFS_QUEUE;
	//初始化所有visited节点
	for(i=0;i<P.pointNum;i++){
		visited[i]=FALSE;
	}
	
	for(i=0;i<P.pointNum;i++){
		if(visited[i]==FALSE){
			visited[i]=TRUE;
			//访问操作
			cout<<P.PointNum[i].data<<endl;
			BFS_QUEUE.push(i);
			while(!BFS_QUEUE.empty()){
				int temp=BFS_QUEUE.front();
				BFS_QUEUE.pop();
				for(j=0;j<P.pointNum;j++){
					if(P.PointLine[temp][j]==1&&visited[j]==FALSE){
						visited[j]=TRUE;
						cout<<P.PointNum[j].data<<endl;
						BFS_QUEUE.push(j);
					}
				}
			}
		}
	}
}
int main(){
	return 0;
}
