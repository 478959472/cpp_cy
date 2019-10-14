// leetcode_cy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<algorithm>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//构建二叉树
void inertNode(TreeNode* node, int value) {
	if (value <= node->val) {
		if (!node->left) {
			node->left = new TreeNode(value);
		}
		else {
			inertNode(node->left, value);
		}
	}
	else {
		if (!node->right) {
			node->right = new TreeNode(value);
		}
		else {
			inertNode(node->right, value);
		}
	}
}

//前序遍历递归实现
void preOrder(TreeNode* node) {
	if (node) {
		std::cout << node->val;
		preOrder(node->left);
		preOrder(node->right);
	}

}
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
	if (!root) {
		return;
	}
	if (!root->left && !root->right) {
		answer = std::max(answer, depth);
	}
	std::cout << answer << std::endl;
	maximum_depth(root->left, depth + 1);
	maximum_depth(root->right, depth + 1);
}


bool symmetric(TreeNode* p, TreeNode* q)       /*判断两棵树是否对称*/
{
	if (!p && !q) return true;       //都是空
	if (!p || !q) return false;      //只有一个空
	return (p->val == q->val) && symmetric(p->left, q->right) && symmetric(p->right, q->left);
	/*树p和树q对称的条件：p和q的值相同，并且p的左子树与q的右子树对称，p的右子树与q的左子树对称*/
}

bool isSymmetric(TreeNode* root) {
	if (!root) return true;   //空树是对称的
	return symmetric(root->left, root->right);
}




bool isSymmetric2(TreeNode* root) {
	if (!root) return true;   //空树是对称的
	std::stack<TreeNode*> s;
	TreeNode* p = root->left, * q = root->right;
	s.push(p);
	s.push(q);        //即使是空节点，也是可以push到栈里的，栈并不为空。
	while (!s.empty())
	{
		p = s.top(); s.pop();
		q = s.top(); s.pop();

		if (!p && !q) continue;            //p、q都是空节点
		if (!p || !q) return false;        //有一个为空，不对称
		if (p->val != q->val) return false;  //值不相等，不对称

		s.push(p->left); s.push(q->right);
		s.push(p->right); s.push(q->left);
	}
	return true;
}

TreeNode* buildTree1(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
	if (iLeft > iRight || pLeft > pRight) return NULL;//终止条件
	TreeNode* cur = new TreeNode(postorder[pRight]);
	int i = 0;
	for (i = iLeft; i < inorder.size(); ++i) {
		if (inorder[i] == cur->val) break;
	}
	cur->left = buildTree(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
	cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
	return cur;
}

TreeNode* buildTree1(std::vector<int>& inorder, vector<int>& postorder) {
	return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}


TreeNode* buildTree(vector<int>& preorder, int iLeft, int iRight, vector<int>& inorder1, int pLeft, int pRight) {
	if (iLeft > iRight || pLeft > pRight) return NULL;//终止条件
	TreeNode* cur = new TreeNode(preorder[iLeft]);
	int i = 0;
	for (i = iLeft; i < inorder1.size(); ++i) {
		if (inorder1[i] == cur->val) break;
	}
	cur->left = buildTree(preorder, iLeft, i - 1, inorder1, pLeft, pLeft + i - iLeft - 1);
	cur->right = buildTree(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);

	cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder1, iLeft, i - 1);
	cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder1, i + 1, iRight);
	return cur;
}

TreeNode* buildTree(std::vector<int>& inorder, vector<int>& postorder) {
	return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}


int main()
{
	vector<int> preorder { 3,9,20,15,7 };
	vector<int> inorder  { 9,3,15,20,7 };

	vector<int> postorder{ 9,15,7,20,3 };
	TreeNode* treeNode = buildTree(inorder, postorder);

	maximum_depth(treeNode, 1);
	std::cout << "完成，树深度" << answer << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
