/*
*way1:使用排序的方法，然后在中间的必定是众数；
*way2:使用相消的方法。
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int result=num[0];int len = num.size();
        int count = 0;
        for (int i=0;i<len;i++){
            if (count==0||result==num[i]) {
                result = num[i];count++;}   //count清零时，取当前数作为result
            else count--;
        }
        return result;
    }
};
