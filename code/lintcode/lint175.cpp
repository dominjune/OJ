// lintcode 175. 
// Easy 
// Invert Binary Tree

#include <iostream>

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) 
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    TreeNode* invertBinaryTree(TreeNode *root) {
        // write your code here
        // recursive
        if(!root)	return NULL;
        TreeNode *temp = root->left;
        root->left = invertBinaryTree(root->right);
        root->right = invertBinaryTree(temp);
        return root;
    }
    
};

int main()
{
	
	return 0;
}

