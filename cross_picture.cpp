#include <iostream>

using namespace std;

// 边节点结构
struct EdgeNode {
	int tailNode;  // 边的起点
	int headNode;  // 边的终点
	EdgeNode *tailLink;  // 下一条以相同起点的边
	EdgeNode *headLink;  // 下一条以相同终点的边
	
	EdgeNode(int tail, int head) : tailNode(tail), headNode(head), tailLink(nullptr), headLink(nullptr) {}
};

// 顶点节点结构
struct VertexNode {
	int vertex;  // 顶点编号
	EdgeNode *inLink;  // 指向以该顶点为终点的边
	EdgeNode *outLink; // 指向以该顶点为起点的边
	
	VertexNode(int v) : vertex(v), inLink(nullptr), outLink(nullptr) {}
};

// 十字链表图结构
class CrossLinkedGraph {
public:
	VertexNode **vertices;  // 存储所有顶点的数组
	int vertexCount;        // 顶点数量
	
	CrossLinkedGraph(int n) : vertexCount(n) {
		vertices = new VertexNode*[n];
		for (int i = 0; i < n; i++) {
			vertices[i] = new VertexNode(i);  // 初始化每个顶点
		}
	}
	
	// 添加边
	void addEdge(int tail, int head) {
		EdgeNode *newEdge = new EdgeNode(tail, head);
		
		// 插入到起点顶点的出边链表中
		if (vertices[tail]->outLink == nullptr) {
			vertices[tail]->outLink = newEdge;
		} else {
			EdgeNode *temp = vertices[tail]->outLink;
			while (temp->tailLink != nullptr) {
				temp = temp->tailLink;
			}
			temp->tailLink = newEdge;
		}
		
		// 插入到终点顶点的入边链表中
		if (vertices[head]->inLink == nullptr) {
			vertices[head]->inLink = newEdge;
		} else {
			EdgeNode *temp = vertices[head]->inLink;
			while (temp->headLink != nullptr) {
				temp = temp->headLink;
			}
			temp->headLink = newEdge;
		}
	}
	
	// 打印图的出边
	void printOutEdges() {
		for (int i = 0; i < vertexCount; i++) {
			cout << "顶点 " << i << " 的出边: ";
			EdgeNode *edge = vertices[i]->outLink;
			while (edge != nullptr) {
				cout << "(" << edge->tailNode << " -> " << edge->headNode << ") ";
				edge = edge->tailLink;
			}
			cout << endl;
		}
	}
	
	// 打印图的入边
	void printInEdges() {
		for (int i = 0; i < vertexCount; i++) {
			cout << "顶点 " << i << " 的入边: ";
			EdgeNode *edge = vertices[i]->inLink;
			while (edge != nullptr) {
				cout << "(" << edge->tailNode << " -> " << edge->headNode << ") ";
				edge = edge->headLink;
			}
			cout << endl;
		}
	}
};

int main() {
	CrossLinkedGraph graph(5);  // 创建一个有5个顶点的图
	
	// 添加边
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	
	// 打印出边和入边
	cout << "图的出边:" << endl;
	graph.printOutEdges();
	
	cout << "图的入边:" << endl;
	graph.printInEdges();
	
	return 0;
}

