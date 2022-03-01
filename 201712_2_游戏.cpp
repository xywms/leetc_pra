#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int i,n,k;
    //n个小朋友
    cin>>n>>k;
    queue<int> q;
    for(i=1;i<=n;i++)
    {
        q.push(i);
    }
    int temp=1,front;
    while(!q.empty())
    {
        front=q.front();
        q.pop();
        if(temp%10==k||temp%k==0)
        {

        }
        else 
        {
            q.push(front);
        }
        temp++;
    }
    cout<<front;
    return 0;
}