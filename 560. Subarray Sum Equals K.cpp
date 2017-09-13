/*brute force*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            if (sums[i] == k) ++res;
            for (int j = i - 1; j >= 0; --j) {
                if (sums[i] - sums[j] == k) ++res;
            }
        }
        return res;
    }
};

/*hash map*/
用哈希表来建立子数组之和与其出现次数之间的映射，初始化中加入{0.1}
这对映射。解题思路为  遍历数组中的数字，用sum来记录到当前位置的累加，
建立哈希表的目的是快速的查找sum-k是否存在，如果sum-k存在的话，必定存在有和
为k的子数组，因为去掉和为k，剩下的为sum-k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res += m[sum - k];
            ++m[sum]; 
        }
        return res;
    }
};
