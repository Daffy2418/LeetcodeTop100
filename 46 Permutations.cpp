#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GeneratePermute(vector<int>& nums,int start,vector<int>& visited,vector<int>& ans,vector<vector<int>>& result)
{
    if(start==nums.size())
    {
        result.push_back(ans);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            ans.push_back(nums[i]);
            GeneratePermute(nums,start+1,visited,ans,result);
            ans.pop_back();
            visited[i]=0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ans;
    if(nums.size()==0) return result;
    vector<int> visited(nums.size(),0);
    GeneratePermute(nums,0,visited,ans,result);
    return result;
}

int main()
{
    vector<vector<int>> permute(vector<int>& nums);
    
    
    vector<vector<int>> result;
    vector<int> candidates={1,2,3};
    result =permute(candidates);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j];
        cout<<endl;
    }
}
