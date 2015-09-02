// lintcode 201.Segment Tree Build
// Medium 
#include <bits/stdc++.h>

//Definition of SegmentTreeNode:
class SegmentTreeNode {
public:
     int start, end;
     SegmentTreeNode *left, *right;
     SegmentTreeNode(int start, int end) {
         this->start = start, this->end = end;
         this->left = this->right = NULL;
     }
}

class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if(start > end)	return NULL;
        if(start == end)    return root;
        root->left = build(start, (start + end) / 2);
        root->right = build((start + end) / 2 + 1, end);
        return root;
    }
};

int main()
{
	
	return 0;
}
