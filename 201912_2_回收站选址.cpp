#include<bits/stdc++.h>
using namespace std;
pair<int,int>p[1000];
map<pair<int,int>,int>m;
int main()
{
    ios::sync_with_stdio(false);
    int i,n,cnt[5],x,y;
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        p[i]=make_pair(x,y);
        m[p[i]]=1;
        
    }
    for(i=0;i<n;i++)
    {
        x=p[i].first;
        y=p[i].second;
         if(m[make_pair(x,y)]&&m[make_pair(x,y+1)]&&m[make_pair(x,y-1)]&&m[make_pair(x+1,y)]&&m[make_pair(x-1,y)])
        {
            cnt[m[make_pair(x-1,y-1)]+m[make_pair(x-1,y+1)]+m[make_pair(x+1,y-1)]+m[make_pair(x+1,y+1)]]++;
        }
    }
    for(i=0;i<5;i++)
    {
        cout<<cnt[i]<<endl;
    }
    return 0;
}