#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义赫夫曼树节点结构体
struct Node {
	char ch;  // 存储字符
	int freq; // 频率
	Node *left, *right;
	
	// 用于叶节点的构造函数（包含字符和频率）
	Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
	
	// 用于非叶节点的构造函数（合并节点）
	Node(int f, Node* l, Node* r) : ch('\0'), freq(f), left(l), right(r) {}
};

// 自定义比较函数，优先队列需要最小频率的节点优先出队
struct Compare {
	bool operator()(Node* left, Node* right) {
		return left->freq > right->freq;
	}
};

// 递归生成赫夫曼编码
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCode) {
	if (!root) {
		return;
	}
	
	// 叶节点（包含字符）
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = code;
	}
	
	generateCodes(root->left, code + "0", huffmanCode);
	generateCodes(root->right, code + "1", huffmanCode);
}

// 释放赫夫曼树内存
void freeTree(Node* root) {
	if (!root) return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

// 构建赫夫曼树并生成赫夫曼编码
void buildHuffmanTree(const string& text) {
	// 统计字符频率
	unordered_map<char, int> freq;
	//char ch : text表示遍历text里面的所有元素，并且将text的字符传递给ch
	for (char ch : text) {
		//freq[ch]++将ch对应的频率加一
		freq[ch]++;
	}
	
	// 创建优先队列
	priority_queue<Node*, vector<Node*>, Compare> pq;
	
	// 将每个字符创建为单独的节点加入优先队列
	for (auto pair : freq) {
		pq.push(new Node(pair.first, pair.second));
	}
	
	// 构建赫夫曼树
	while (pq.size() != 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();
		
		// 合并两个最小频率的节点
		int sum = left->freq + right->freq;
		pq.push(new Node(sum, left, right)); // 新节点，不含字符
	}
	
	// 获取根节点
	Node* root = pq.top();
	
	// 生成赫夫曼编码 string用于存储赫夫曼编码 char是对应的字符
	unordered_map<char, string> huffmanCode;
	generateCodes(root, "", huffmanCode);
	
	// 输出每个字符的赫夫曼编码
	cout << "赫夫曼编码:\n";
	for (auto pair : huffmanCode) {
		cout << pair.first << ": " << pair.second << '\n';
	}
	
	// 释放树内存
	freeTree(root);
}

int main() {
	string text = "hello huffman";
	buildHuffmanTree(text);
	return 0;
}

