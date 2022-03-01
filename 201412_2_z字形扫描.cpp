#include<bits/stdc++.h>
using namespace std;
int m[501][501];
const int east=0;
const int southwest=1;
const int south=2;
const int northeast=3;
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
    int dir[4][2]={{0,1},{1,-1},{1,0},{-1,1}};
    int row=0,col=0;
    int next=east;
    cout<<m[row][col];
    while(row!=n-1||col!=n-1)
    {
        row=row+dir[next][0];
        col=col+dir[next][1];
        //cout<<"row="<<row<<" "<<"col="<<col<<" m=";
        cout<<" "<<m[row][col];
        //为什么要把n-1的if放在前面呢
       if(next==east&&row==n-1)
        {
            next=northeast;
        }
        else if(next==east&&row==0)
        {
            next=southwest;
        }
        
        else if(next==southwest&&row==n-1)
        {
            next=east;
        }
        else if(next==southwest&&col==0)
        {
            next=south;
        }
         else if(next==south&&col==n-1)
        {
            next=southwest;
        }
        else if(next==south&&col==0)
        {
            next=northeast;
        }
        else if(next==northeast&&col==n-1)
        {
            next=south;
        }
        else if(next==northeast&&row==0)
        {
            next=east;
        }
       
    }
    cout<<endl;
    return 0;
}