//
//  main.cpp
//  StudyCPlus
//
//  Created by Daffy on 2017/8/10.
//  Copyright © 2017 Daffy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int left,int avaliable,int length,int n,vector<string> &ans,string temp)
{
    if(length==2*n)
    {
        ans.push_back(temp);
        return;
    }
    
    if(left)
    {
        if(avaliable)
        {
            temp+='(';
            dfs(left+1,avaliable-1,length+1,n,ans,temp);
            temp.pop_back();
        }
        
        temp+=')';
        dfs(left-1,avaliable,length+1,n,ans,temp);
        temp.pop_back();
    }else{
        if(avaliable)
        {
            temp+='(';
            dfs(left+1,avaliable-1,length+1,n,ans,temp);
            temp.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string temp;
    dfs(0,n,0,n,ans,temp);
    return ans;
}


int main()
{
    vector<string> result;
    result=generateParenthesis(3);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
}
