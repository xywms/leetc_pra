#include<bits/stdc++.h>
using namespace std;
int t[101][101];
struct p
{
    int x1,y1,x2,y2;
};
vector<p>v(101);
int main()
{
    memset(t,0,sizeof(t));
    int i,n,j,k,res=0;
    cin>>n;
    v.resize(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
        for(j=v[i].x1;j<v[i].x2;j++)
        {
            //为什么进不去这个for
            for(k=v[i].y1;k<v[i].y2;k++)
            {
                //cout<<"why"<<endl;
                if(t[j][k]==0)
                {
                    res++;
                    t[j][k]=1;
                }
            }
            
        }
    }
    cout<<res;
    return 0;
}