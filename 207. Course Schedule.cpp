/*
**** https://www.hrwhisper.me/leetcode-graph/ ****
*/
/*
*将其转换为拓扑排序
*每次找入度为0的点，输出该入度为0的点，并删除与之相连接的边
*重复上一步，直到没有入度为0的点，然后判断图中有没有存在环。
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            /*寻找每一个节点所存在的所有的边*/
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            in_degree[prerequisites[i].first]++;/*每一个节点的度*/
        }
        
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            /*c++ .begin()返回的是指针*/
            for(auto it=g[cur].begin();it!=g[cur].end();it++)
                if(--in_degree[*it]==0) q.push(*it);
        }
        
        for(int i=0;i<numCourses;i++) if(in_degree[i]!=0) return false;
        return true;
    }
};
