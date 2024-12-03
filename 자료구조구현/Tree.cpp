#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode* left, * right;
};
TreeNode* makeNode(int data, TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

void inorder(TreeNode* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}
void preorder(TreeNode* root) {
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main()
{
	TreeNode* n1, * n2, * n3;
	n2 = makeNode(20, NULL, NULL);
	n3 = makeNode(30, NULL, NULL);
	n1 = makeNode(10, n2, n3);
	postorder(n1);
	printf("\n");
	preorder(n1);
	printf("\n");
	inorder(n1);
}