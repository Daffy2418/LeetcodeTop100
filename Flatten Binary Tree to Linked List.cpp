/*
递归构建 DFS
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode* rightTail = flattenBT(root);
    }
    
    TreeNode* flattenBT(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *leftTail = flattenBT(root->left);
        TreeNode *rightTail = flattenBT(root->right);
        if(root->left) {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            leftTail->right = temp;
        }
        
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
    }
};




/*
前序遍历
*/
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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        vector<TreeNode*> allNodes;
        preorder(root,allNodes);
        
        int n=allNodes.size();
        for(int i=0;i<n-1;i++){
            allNodes[i]->left=NULL;
            allNodes[i]->right=allNodes[i+1];
        }
        allNodes[n-1]->left=allNodes[n-1]->right=NULL;      
    }
    
    void preorder(TreeNode *root,vector<TreeNode*> &allNodes){
        if(!root) return;
        allNodes.push_back(root);
        preorder(root->left,allNodes);
        preorder(root->right,allNodes);
    }
};
