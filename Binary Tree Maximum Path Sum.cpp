/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//使用DFS，总是返回上一节点
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int mx=mxsum(root,res);
        return res;
    }
    
    //引用传递
    int mxsum(TreeNode* root,int &res){
        if(!root)
            return 0;
        else
        {
            int mx_l=mxsum(root->left,res);
            int mx_r=mxsum(root->right,res);
            
            int mx=max(max(mx_l,mx_r)+root->val,root->val);
            res=max(res,max(mx,mx_l+root->val+mx_r));
            return mx;
        }
    }
};
