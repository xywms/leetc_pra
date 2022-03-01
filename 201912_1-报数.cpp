#include<bits/stdc++.h>
using namespace std;
bool contains7(int num)
{
    int n;
    while(num>0)
    {
        if(num%10==7)
        {
            return true;
        }
        num=num/10;
    }
    return false;
}
int main()
{
    int i,n,num=1,skip=0,p[4];
    memset(p,0,sizeof(p));
    cin>>n;
    for(i=1;num<=n;i++)
    {
        //四个人轮流报数
        if(i%7==0||contains7(i))
        {
            p[(i-1)%4]++;
        }
        else
        {
            num++;
        }
    }
    cout<<p[0]<<endl;
    cout<<p[1]<<endl;
    cout<<p[2]<<endl;
    cout<<p[3]<<endl;
    return 0;
}
