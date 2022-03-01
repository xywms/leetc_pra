#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int main()
{
    int n,a,b,i,index,val;
    long long res=0;
    cin>>n>>a>>b;
    for(i=0;i<a;i++)
    {
        cin>>index>>val;
        m[index]=val;
    }
    for(i=0;i<b;i++)
    {
        cin>>index>>val;
        res=res+val*m[index];
    }
    cout<<res;
    return 0;
}
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/