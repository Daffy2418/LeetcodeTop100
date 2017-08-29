class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        for(int i=0;i<len-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target2=-nums[i];
            twoSum(nums,i+1,target2,res);
        }
        return res;        
    }
    
    void twoSum(vector<int> &sortedNum,int start,int target,vector<vector<int>> &res)
    {
        int head=start;int tail=sortedNum.size()-1;
        while(head<tail)
        {
            int tmp=sortedNum[head]+sortedNum[tail];
            if(tmp<target)
                head++;
            else if(tmp>target)
                tail--;
            else
            {
                res.push_back(vector<int>{sortedNum[start-1],sortedNum[head],sortedNum[tail]});
                
                //因为只在二元组里寻找，使其结果等于target
                int k=head+1;
                while(k<tail && sortedNum[k]==sortedNum[head])
                    k++;
                head=k;
                
                k=tail-1;
                while(k>head && sortedNum[k]==sortedNum[tail])
                    k--;
                tail=k;
            }
        }
        
    }
};
