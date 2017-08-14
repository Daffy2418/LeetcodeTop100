'''
 4 
   / \ 
 11 13 
 / \ 
7  2

对于一条路径来说，可以分为两种情况，一是当顶节点是当前点，另一种是顶节点是父节点。例如，对于节点11来说，

1. 当顶节点是当前节点，对于节点11，路径为 7->11->2

2. 当顶节点是父节点4时，对于节点11，路径为 7->11->4->13

对于DFS来说，其递归过程中必定会对某节点的子节点调用，那么其返回值应该适用于上面第二种情况，但是最终结果肯定是第一种情况，那么如果保存并更新最终结果呢，我们可以将其放在参数中传递。那么对于任意一个节点n来说，

DFS(n) = max(DFS(n->left) + n->val, DFS(n->right) + n->val, n->val);

top(n) = max(DFS(n), DFS(n->left) + DFS(n->right) + n->val, n->val);

res = max(res, top(n));
'''
# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    res = None

    def findmax(self, root):
        if root == None:
            return 0
        else:
            max_l = self.findmax(root.left)
            max_r = self.findmax(root.right)
            # 以上一父节点为顶节点
            max_s = max(max(max_l, max_r) + root.val, root.val)
            # 以上一节点为顶节点
            max_top = max(max(max_s, max_l + max_r + root.val), root.val)
            if self.res == None:
                self.res = max_top
            else:
                self.res = max(max_top, self.res)
            return max_s

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.findmax(root)
        return self.res


if __name__ == '__main__':
    root=TreeNode(4)
    left1=TreeNode(11)
    right1=TreeNode(13)
    left2=TreeNode(7)
    right2=TreeNode(2)
    root.left=left1
    root.right=right1
    left1.left=left2
    left1.right=right2
    s=Solution()
    print(s.maxPathSum(root))
