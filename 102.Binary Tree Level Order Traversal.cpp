/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS
//求每一层的节点，并且存在一个二维数组里，需要求出树的深度，根据深度来建立二维数组
//用DFS求出树的高度，再用DFS对每一层遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth=getHeight(root);
        vector<vector<int>> ret(depth);
        if(depth==0)
            return ret;
        getSolution(ret,root,0);
        return ret;
    }
    
    void getSolution(vector<vector<int>>& ret,TreeNode *root,int level)
    {
        if(root==NULL)
            return;
        ret[level].push_back(root->val);
        getSolution(ret,root->left,level+1);
        getSolution(ret,root->right,level+1);
    }
    
    int getHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        int height=(left>right?left:right)+1;
        return height;
    }
};
