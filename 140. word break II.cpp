/*
*使用DFS方法，没有剪枝，会出现重复计算。
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void GetAllSolution(int start,const string& s,const vector<string>& wordDict,int len,string& result,vector<string>& solutions)
{
    if(start==len)
    {
        solutions.push_back(result.substr(0,result.size()-1));
        return;
    }
    for(int i=start;i<len;i++)
    {
        string piece=s.substr(start,i-start+1);
        if(find(wordDict.begin(),wordDict.end(),piece)!=wordDict.end())
        {
            result.append(piece).append(" ");
            GetAllSolution(i+1, s, wordDict, len, result, solutions);
            result.resize(result.size()-piece.size()-1);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    string result;
    vector<string> solutions;
    int len=s.size();
    GetAllSolution(0, s, wordDict, len, result, solutions);
    return solutions;
}

int main()
{
    vector<string> wordBreak(string s, vector<string>& wordDict);
    string s="catsanddog";
    vector<string> wordDist={"cat","cats","and","sand","dog"};
    vector<string> ans=wordBreak(s, wordDist);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}


/*
*剪枝,就是记录这个节点后面的，我们已经计算过了。
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void GetAllSolution(int start,const string& s,const vector<string>& wordDict,int len,string& result,vector<string>& solutions,vector<bool>& possible)
{
    if(start==len)
    {
        solutions.push_back(result.substr(0,result.size()-1));
        return;
    }
    for(int i=start;i<len;i++)
    {
        string piece=s.substr(start,i-start+1);
        if(find(wordDict.begin(),wordDict.end(),piece)!=wordDict.end() && possible[i+1])
        {
            result.append(piece).append(" ");
            int beforeChange=solutions.size();//cut2
            GetAllSolution(i+1, s, wordDict, len, result, solutions,possible);
            if(solutions.size()==beforeChange)//cut3
                possible[i+1]=false;
            result.resize(result.size()-piece.size()-1);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    string result;
    vector<string> solutions;
    int len=s.size();
    vector<bool> possible(len+1,true);//cut
    GetAllSolution(0, s, wordDict, len, result, solutions,possible);
    return solutions;
}

int main()
{
    vector<string> wordBreak(string s, vector<string>& wordDict);
    string s="catsanddog";
    vector<string> wordDist={"cat","cats","and","sand","dog"};
    vector<string> ans=wordBreak(s, wordDist);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
