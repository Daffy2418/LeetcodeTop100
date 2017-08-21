/*
对任意位置i，在i上的积水，由左右两边最高的bar：
A[left] = max{A[j], j<i}, A[right] = max{A[j], j>i}决定。
定义Hmin = min(A[left], A[right])，则积水量Si为：
Hmin <= A[i]时，Si = 0
Hmin > A[i]时，Si = Hmin - A[i]
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        vector<int> leftHeight(n,0);
        vector<int> rightHeight(n,0);
        int water=0;
        
        for(int i=1;i<n;i++)
            leftHeight[i]=max(leftHeight[i-1],height[i-1]);
        
        for(int i=n-2;i>=0;i--){
            rightHeight[i]=max(rightHeight[i+1],height[i+1]);
            int minHeight=min(leftHeight[i],rightHeight[i]);
            if(minHeight>height[i]) water+=(minHeight-height[i]);
        }
        
        return water;
    }
};
