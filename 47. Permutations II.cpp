/*
*跟 Permutations的解法一样，就是要考虑“去重”。先对数组进行排序，
*这样在DFS的时候，可以先判断前面的一个数是否和自己相等，
*相等的时候则前面的数必须使用了，自己才能使用，这样就不会产生重复的排列了。
*/
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
