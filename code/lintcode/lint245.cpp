// lintcode 245.Subtree
// Easy 
#include <iostream>

using namespace std;


//Definition of TreeNode:
class TreeNode {
public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
};

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here  
        if(is_same(T1, T2))	return 1;
        if(T2 == NULL)	return 1;	// true
        if(T1 == NULL )	return 0;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
    
    bool is_same(TreeNode *T1, TreeNode *T2)
    {
    	//判断清楚各种情况 
    	if(T1 == NULL)
    	{
    		if(T2 == NULL)	return 1;
    		else	return 0;
    	}
    	if(T2 == NULL)	return 0;
    	if(T1->val == T2->val) 
    	    return is_same(T1->left, T2->left) && is_same(T1->right, T2->right);
    	 return 0;
    }
};


int main()
{
	
	return 0;
}
