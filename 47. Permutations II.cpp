class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        if(nums.size()==0) return result;
        vector<int> visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        GeneratePermute(nums,0,visited,ans,result);
        return result;
    }
    
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
                if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0)
                    continue;
                visited[i]=1;
                ans.push_back(nums[i]);
                GeneratePermute(nums,start+1,visited,ans,result);
                ans.pop_back();
                visited[i]=0;
            }
        }
    }
};
