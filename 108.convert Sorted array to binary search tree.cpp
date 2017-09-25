class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return arrayToBST(num, 0, num.size()-1);
    }
    
    TreeNode *arrayToBST(vector<int> &num, int start, int end) {
        if(start>end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = arrayToBST(num, start, mid-1);
        root->right = arrayToBST(num, mid+1, end);
        return root;
    }
};
