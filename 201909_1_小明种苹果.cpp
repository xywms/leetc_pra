#include<bits/stdc++.h>
using namespace std;
int sumb[1001];
int sumdrop[1001];
int maxdrop=0,dropsum;
int main()
{
    int n,m,t=0,k,p=0,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        dropsum=0;
        cin>>sumb[i];
        t=t+sumb[i];
        for(j=0;j<m;j++)
        {
            cin>>sumdrop[j];
            dropsum=dropsum-sumdrop[j];
            if(dropsum>maxdrop)
            {
                k=i+1;
                maxdrop=dropsum;
                p=maxdrop;
            }
        }
         t=t-dropsum;   
    }
    cout<<t<<" "<<k<<" "<<p;
    return 0;
}
/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
*/