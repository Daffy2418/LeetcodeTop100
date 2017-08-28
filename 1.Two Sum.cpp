/*解法一
*双指针扫描
*将数组排序，然后双指针从前后往中间扫描。时间复杂度O(n*lgn)
*/
struct Node
{
	int val;
	int index;
	Node(int pVal,int pIndex):val(pVal),index(pIndex){}
};

static bool compare(const Node &left,const Node &right)
{
	return left.val<right.val;
}

vector<int> twoSum(vector<int> &numbers,int target){
	vector<Node> elements;
	for(int i=0;i<numbers.size();i++)
	{
		elements.push_back(Node(numbers[i],i))
	}
	std:sort(elements.begin(),elements.end(),compare);
	int start=0,end=numbers.size()-1;
	vector<int> result;
	while(start<end)
	{
		int sum=elements[start].val+elements[end].val;
		if(sum==target)
		{
			result.push_back(elements[start].index);
			if(elements[start].index<elements[end].index)
				result.push_back(elements[end].index);
			else
				result.insert(result.begin(),elements[end].index);
			break;
		}
		else if(sum>target)
			end--;
		else
			start++;
	}
	return result;
}


/*解法二
*哈希
*从左往右扫描一遍，然后将数及坐标，存到map中。然后再扫描一遍即可。时间复杂度O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            mapping[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int searched=target-nums[i];
            if(mapping.count(searched) && mapping[searched]!=i)
            {
                result.push_back(i);
                result.push_back(mapping[searched]);
                break;
            }
        }
        return result;
    }
};
