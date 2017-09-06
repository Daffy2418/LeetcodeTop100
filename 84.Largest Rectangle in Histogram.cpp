#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &height) {
    if(height.empty()) return 0;
    height.push_back(-1);
    height.insert(height.begin(),-1);
    stack<int> s;
    int maxArea = 0;
    
    for(int i=0; i<height.size(); i++) {
        while(!s.empty() && height[i]<=height[s.top()]) {
            int h = height[s.top()];
            s.pop();
            if(height[i]<h) maxArea = max(maxArea, (i-s.top()-1)*h);
        }
        s.push(i);
    }
    
    // reset height
    height.erase(height.begin());
    height.pop_back();
    return maxArea;
}

int main()
{
    int largestRectangleArea(vector<int> &height);
    
    vector<int> nums={2,1,5,6,2,3};
    int ans=largestRectangleArea(nums);
    cout<<ans<<endl;
}
