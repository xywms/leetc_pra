#include<bits/stdc++.h>
using namespace std;
int a[1001];
int step[1001];
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,l,t,i,j;
    cin>>n>>l>>t;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        //开始往右走，到达两端就回头。
        step[i]=1;
        if(a[i]==l||a[i]==0)
        {
            step[i]=-step[i];
        }
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<n;j++)
        {
            a[j]=a[j]+step[j];
            if(a[j]==0||a[j]==l)
            {
                step[j]=-step[j];
            }
        }
        for(j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[j]==a[k])
                {
                    step[k]=-step[k];
                    step[j]=-step[j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
     cout<<endl;
    return 0;
}