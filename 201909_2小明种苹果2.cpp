#include<bits/stdc++.h>
using namespace std;
int sum[1001];
int drop[1001];
int main()
{
    memset(sum,0,sizeof(sum));
    memset(drop,0,sizeof(drop));
    int n,m,i,j,temp=0;
    int t=0,d=0,e=0,k=0;
    bool flagp=false;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>m;
        cin>>sum[i];
        flagp=false;
        for(j=1;j<m;j++)
        {
            cin>>temp;
            if(temp<=0)
            {
                sum[i]=sum[i]+temp;
            }
            else
            {
                if(sum[i]>temp)
                {
                    flagp=true;
                }
                sum[i]=temp;
            }
        }
        //cout<<"sum"<<i<<"="<<sum[i]<<" ";
        if(flagp==true)
        {
            d++;
            drop[i]=1;
            
        }
         t=t+sum[i];
        
    }
    for(i=1;i<=n;i++)
    {
        if((i<n-1)&&(drop[i+1]&&drop[i+2]&&drop[i]))
        {
            //cout<<"i="<<i;
            e++;
         }
         else if((i==n)&&(drop[1]&&drop[2]&&drop[i]))
         {
             e++;
         }
         else if((i==n-1)&&(drop[n]&&drop[1]&&drop[i]))
         {
             e++;
         }

    }
    cout<<t<<" "<<d<<" "<<e;
    return 0;
}
/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/