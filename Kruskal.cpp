#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

// 定义边的结构
struct Edge {
	int src, dest, weight;
};

// 并查集结构，用于检测环路
class DisjointSets {
public:
	vector<int> parent, rank;
	
	// 初始化并查集
	DisjointSets(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		
		// 初始化时，每个顶点的父节点为自己
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	
	// 查找操作，带路径压缩优化
	int find(int u) {
		if (u != parent[u]) {
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}
	
	// 合并两个子集
	void Union(int u, int v) {
		int rootU = find(u);
		int rootV = find(v);
		
		// 将 rank 小的集合合并到 rank 大的集合
		if (rank[rootU] < rank[rootV]) {
			parent[rootU] = rootV;
		} else if (rank[rootU] > rank[rootV]) {
			parent[rootV] = rootU;
		} else {
			parent[rootV] = rootU;
			rank[rootU]++;
		}
	}
};

// Kruskal 算法实现
void kruskalMST(vector<Edge>& edges, int V) {
	// 按边的权重排序
	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.weight < b.weight;
	});
	
	// 创建并查集实例，管理图的连通性
	DisjointSets ds(V);
	
	vector<Edge> mst;  // 用于存储最小生成树的边
	
	// 遍历所有边，并选择合适的边加入到 MST
	for (Edge& edge : edges) {
		int u = edge.src;
		int v = edge.dest;
		
		// 找到顶点 u 和 v 所在的集合根
		int setU = ds.find(u);
		int setV = ds.find(v);
		
		// 如果两个顶点不在同一个集合中，则加入 MST
		if (setU != setV) {
			mst.push_back(edge);
			ds.Union(setU, setV);  // 合并两个集合
			
			// 如果已选的边数达到 V-1，则构造完成
			if (mst.size() == V - 1) break;
		}
	}
	
	// 输出结果
	cout << "Edges in the MST:\n";
	for (Edge& e : mst) {
		cout << e.src << " - " << e.dest << " \t" << e.weight << endl;
	}
}

int main() {
	int V = 5;  // 顶点数
	vector<Edge> edges = {
		{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, 
		{2, 4, 7}, {3, 4, 9}
	};
	
	kruskalMST(edges, V);
	
	return 0;
}

