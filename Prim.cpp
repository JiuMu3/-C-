#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

#define V 5  // 图的顶点数

// 找到未包含在MST中且拥有最小权值的顶点
int minKey(vector<int>& key, vector<bool>& mstSet) {
	int min = INT_MAX, min_index;
	
	for (int v = 0; v < V; v++)
		if (!mstSet[v] && key[v] < min)
			min = key[v], min_index = v;
	
	return min_index;
}

// 打印最小生成树
void printMST(vector<int>& parent, vector<vector<int>>& graph) {
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << " \n";
}

// 使用Prim算法找到最小生成树
void primMST(vector<vector<int>>& graph) {
	vector<int> parent(V);  // 存储MST
	vector<int> key(V, INT_MAX);  // 用于选择最小权值边
	vector<bool> mstSet(V, false);  // 表示是否包含在MST中
	
	key[0] = 0;  // 初始顶点的权值为0
	parent[0] = -1;  // 第一个顶点是根节点
	
	// 构造MST
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);  // 找到权值最小的未处理顶点
		mstSet[u] = true;  // 将该顶点包括进MST
		
		// 更新邻接顶点的权值
		for (int v = 0; v < V; v++)
			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	
	// 打印MST
	printMST(parent, graph);
}

int main() {
	// 定义图的邻接矩阵
	vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 } };
	
	primMST(graph);
	
	return 0;
}

