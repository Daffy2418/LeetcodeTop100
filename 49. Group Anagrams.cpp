/*
*必须是泛型才能用如下循环
*for(String str:strs){
*}

*泛型和布什泛型都可以用如下
*相当于 for(int i=0;i<strs.size();i++){
*   String str=(String)strs.get(i);
*}
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,vector<string>> ht;
        
        for(string str: strs){
            string t=str;
            sort(t.begin(),t.end());
            ht[t].push_back(str);
        }
        
        for(auto a:ht)
            ret.push_back(a.second);
        return ret;
    }
};
