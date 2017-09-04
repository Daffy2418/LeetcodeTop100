#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetCombinations(vector<int>& candidates,int& sum,int start,int target,vector<int> &ans,vector<vector<int>>& result)
{
    if(sum>target) return;
    if(sum==target)
    {
        result.push_back(ans);
        return;
    }
    for(int i=start;i<candidates.size();i++)
    {
        sum+=candidates[i];
        ans.push_back(candidates[i]);
        GetCombinations(candidates,sum,i+1,target,ans,result);
        ans.pop_back();
        sum-=candidates[i];
        
        while(i<candidates.size()-1 && candidates[i]==candidates[i+1])
            i++;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> ans;
    int sum=0;
    sort(candidates.begin(),candidates.end());
    GetCombinations(candidates,sum,0,target,ans,result);
    return result;
}


int main()
{
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    
    
    vector<vector<int>> result;
    vector<int> candidates={1,1,2,5,6,7,10};
    result =combinationSum(candidates,8);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j];
        cout<<endl;
    }
}
