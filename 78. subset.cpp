#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void generateSub(vector<int>& nums,int step,vector<vector<int>>& result,vector<int>& output)
{
    for(int i=step;i<nums.size();i++)
    {
        output.push_back(nums[i]);
        result.push_back(output);
        if(i<nums.size()-1)
            generateSub(nums,i+1,result,output);
        output.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> output;
    if(nums.size()==0) return result;
    result.push_back(output);
    sort(nums.begin(),nums.end());
    generateSub(nums,0,result,output);
    return result;
}


int main()
{
    vector<vector<int>> subsets(vector<int>& nums);
    
    vector<vector<int>> ans;
    vector<int> nums={1,2};
    ans=subsets(nums);
}
