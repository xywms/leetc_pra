#include<bits/stdc++.h>
using namespace std;
int p[500001];
//一个数字可能出现在多个位置
map<int,vector<int>>m;
//空间换时间,记录数字的位置
int main()
{
    int n,i,fld=0,res,j;
    cin>>n;
    memset(p,0,sizeof(p));
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(i=1;i<=n;i++)
    {
        if(p[i-1]==0&&p[i]!=0)
        {
            fld++;
        }
        //没有这一步，结果会不同
        if(p[i]!=0)
        {
             m[p[i]].push_back(i);
        }
      
    }
    //分三种情况，
    res=fld;
    for(i=0;i<m.size();i++)
    {
        for(j=0;j<m[i].size();j++)
        {
            if(p[m[i][j]-1]==0&&p[m[i][j]+1]==0)
            res--;
            if(p[m[i][j]-1]!=0&&p[m[i][j]+1]!=0)
            {
                res++;
            }
            p[m[i][j]]=0;
        }
        
        fld=max(res,fld);
    }
    cout<<fld;
    return 0;
}