// lintcode 177.Convert Sorted Array to Binary Search Tree With Minimal Height
// Easy
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// Definition of TreeNode:
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    //用递归啊... bst都不会写了... 
    //因为高度最小，所以每次把中间的作为根 
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        int len = A.size();
        if(len == 0)	return NULL;
        return build(A, 0, len-1);
    }
    TreeNode *build(vector<int> &A, int l, int r)
    {
    	int m = (l + r) / 2;
    	TreeNode *root = new TreeNode(A[m]);
    	if(l < m)
    		root->left = build(A, l, m-1);
    	if(r > m)
    		root->right = build(A, m+1, r);
    	return root;
    }
};
    
    

int main()
{
	
	return 0;
} 
