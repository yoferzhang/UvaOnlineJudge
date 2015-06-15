#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset> 
#include <cassert> 

using namespace std;

const int maxn = 266;

struct Node
{
	bool haveValue; // 是否被赋值过
	int v; // 结点的值
	Node* left, *right; // 左右子结点
	Node() :haveValue(false), left(NULL), right(NULL) {} 
};

Node *root; // 根结点

Node* newnode() {
	return new Node(); // 产生一个新结点
}

bool failed;
void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root; // 从根结点开始往下走
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (u->left == NULL) {
				u->left = newnode(); // 左结点不存在，就生成一个新的
			}
			u = u->left; // 往左走
		}
		else if (s[i] == 'R') {
			if (u->right == NULL) {
				u->right = newnode(); // 右结点不存在，就生成一个新的
			}
			u = u->right; // 往右走
		} 
		// 右括号直接忽略
	}
	if (u->haveValue) {
		failed = true; // 已经有值了，输入错误，标记起来
	}
	u->v = v;
	u->haveValue = true;
}

// 防止内存泄漏，新的测试之前记得释放掉之前的树
// 这里递归的释放内存
void removeTree(Node* u)
{
	if (u == NULL) {
		return;
	}
	removeTree(u->left);
	removeTree(u->right);
	delete u;
}

char s[maxn];
bool readInput()
{
	failed = false;
	removeTree(root);
	root = newnode();
	while (1) {
		if (scanf("%s", s) != 1) { // 输入结束
			return false;
		}
		if (!strcmp(s, "()")) {
			break; // 读取到结束标志
		}
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

// 宽度优先遍历
bool bfs(vector<int>& ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty()) {
		Node* u = q.front();
		q.pop();
		if (!u->haveValue) { // 有结点没有被赋值，输入有错
			return false;
		}
		ans.push_back(u->v);
		if (u->left != NULL) { // 左结点非空，入队
			q.push(u->left);
		}
		if (u->right != NULL) { // 右结点非空，入队
			q.push(u->right);
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> ans;
	while (readInput()) {
		if (!bfs(ans)) {
			failed = 1;
		}
		if (failed) {
			cout << "not complete\n";
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (i != 0) {
					cout << " ";
				}
				cout << ans[i];
			}
			cout << endl;
		}
	}

	return 0;
}