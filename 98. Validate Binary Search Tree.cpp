/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root,false,false,0,0);
    }
    
    bool validateBST(TreeNode *root,bool left,bool right,int lmax,int rmin) {
        if(!root) return true;
        if(left && root->val>=lmax) return false;
        if(right && root->val<=rmin) return false;
        return validateBST(root->left, true,right,root->val,rmin) && validateBST(root->right, left,true,lmax,root->val);
    }
};



/**
中序遍历  栈
**/
