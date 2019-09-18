// leetcode_cy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

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


int main()
{
	TreeNode treeNode(1);
	inertNode(&treeNode, 2);
	inertNode(&treeNode, 3);
	inertNode(&treeNode, 4);
	inertNode(&treeNode, 5);
	inertNode(&treeNode, 6);
	inertNode(&treeNode, 7);
	preOrder(&treeNode);
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
