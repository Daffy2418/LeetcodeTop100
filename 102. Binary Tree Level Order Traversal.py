# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        result=[]
        if root==None:
            return result
        levelToProcess=[root]
        while len(levelToProcess)>0:
            numbersLevel=[]
            nextLevel=[]
            for temp in levelToProcess:
                numbersLevel.append(temp.val)
                if temp.left:
                    nextLevel.append(temp.left)
                if temp.right:
                    nextLevel.append(temp.right)
            result.append(numbersLevel)
            levelToProcess=nextLevel
        return result
