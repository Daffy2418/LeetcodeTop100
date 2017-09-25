class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return findDepth(root)==-1 ? false : true;
    }
    
    int findDepth(TreeNode *root) {
        if(!root) return 0;
        
        int leftDepth = findDepth(root->left);      // left subtree depth
        if(leftDepth==-1) return -1;
        
        int rightDepth = findDepth(root->right);    // right subtree depth
        if(rightDepth==-1) return -1;
        
        if(abs(leftDepth-rightDepth)>1) return -1;
        
        return max(leftDepth,rightDepth)+1;
    }
};
