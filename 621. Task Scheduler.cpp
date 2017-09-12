/*
*贪心算法，优先选择那些数量多的任务。
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //定义长度为26的vector来存储每个tasks需要重复的次数
        vector<int>Letters(26,0);
        //统计
        for(int i=0;i<tasks.size();i++)
            Letters[tasks[i]-'A']++;
        //排序
        sort(Letters.begin(),Letters.end());
        //最少需要用到的时间
        int minInterval=0;  
        //在贪心的策略下，每一步用到的时间
        int perInterval=0;  
        //作为一个标志，判断每一步是否有新的未完成的任务
        bool flag=false;  
        while(1){
            perInterval=0;
            //查找在贪心的策略下，每一步要完成的任务
            for(int i=25;i>=0;i--){
                if(Letters[i]>0){
                    perInterval++;
                    Letters[i]--;
                    flag=true;
                }
                if(perInterval>n)
                    break;
            }
            sort(Letters.begin(),Letters.end());
            if(flag){
                //每一步完成的不重复任务大于n的情况，即不需要空闲时间等的情况
                if(perInterval>n)
                    minInterval+=perInterval;
                else{
                    //如果已经是最后一步，就不需要再空出时间时间来等
                    if(Letters[25]==0)
                        minInterval+=perInterval;
                    //若不是最后一步，要等够n+1时间才能继续进行下一步
                    else
                        minInterval+=(n+1);
                }
            }else{
                //若不存在flag=false，说明任务已经全部被完成
                break;
            }
            flag=false;
        }
        return minInterval;
    }
};
