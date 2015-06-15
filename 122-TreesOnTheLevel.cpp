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
	bool haveValue; // �Ƿ񱻸�ֵ��
	int v; // ����ֵ
	Node* left, *right; // �����ӽ��
	Node() :haveValue(false), left(NULL), right(NULL) {} 
};

Node *root; // �����

Node* newnode() {
	return new Node(); // ����һ���½��
}

bool failed;
void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root; // �Ӹ���㿪ʼ������
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (u->left == NULL) {
				u->left = newnode(); // ���㲻���ڣ�������һ���µ�
			}
			u = u->left; // ������
		}
		else if (s[i] == 'R') {
			if (u->right == NULL) {
				u->right = newnode(); // �ҽ�㲻���ڣ�������һ���µ�
			}
			u = u->right; // ������
		} 
		// ������ֱ�Ӻ���
	}
	if (u->haveValue) {
		failed = true; // �Ѿ���ֵ�ˣ�������󣬱������
	}
	u->v = v;
	u->haveValue = true;
}

// ��ֹ�ڴ�й©���µĲ���֮ǰ�ǵ��ͷŵ�֮ǰ����
// ����ݹ���ͷ��ڴ�
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
		if (scanf("%s", s) != 1) { // �������
			return false;
		}
		if (!strcmp(s, "()")) {
			break; // ��ȡ��������־
		}
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

// ������ȱ���
bool bfs(vector<int>& ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty()) {
		Node* u = q.front();
		q.pop();
		if (!u->haveValue) { // �н��û�б���ֵ�������д�
			return false;
		}
		ans.push_back(u->v);
		if (u->left != NULL) { // ����ǿգ����
			q.push(u->left);
		}
		if (u->right != NULL) { // �ҽ��ǿգ����
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