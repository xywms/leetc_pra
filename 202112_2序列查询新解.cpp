/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,N,i;
    cin>>n>>N;
    int a[n+1];
    a[0]=0;
    int r;
    r=N/(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long res=0;
    //a[i]是索引，i是f(i)的值
    int j,temp,numr;
    //j会不会很大
    for(i=0;i<n;i++)
    {
       // cout<<"i="<<i<<endl;
        if((a[i]%r==0)&&(a[i+1]%r==0))
        {
           // cout<<"case1"<<endl;
            //刚好若干个r,r肯定是以1为单位递增的，可是fi与gi之间谁大谁小不好判断
            //该区间第一个差值
            temp=i-a[i]/r;
            numr=(a[i+1]-a[i])/r;
            for(j=0;j<numr;j++)
            {
                res=res+r*abs(temp+j);
            }
            
        }
        //右对齐，左不对齐
        else if(a[i+1]%r==0)
        {
            // cout<<"case2"<<endl;
            //左余
            res=res+((a[i+1]-a[i])%r)*(i-a[i]/r);
            //中
             temp=i-(a[i]/r+1);
            numr=(a[i+1]-a[i])/r;
            for(j=0;j<(a[i+1]-a[i])/r;j++)
            {
                res=res+r*abs(temp+j);
            }
        }
        //左对齐，右不对齐
        else if(a[i]%r==0)
        {
             //cout<<"case3"<<endl;
            temp=i-a[i]/r;
            numr=(a[i+1]-a[i])/r;
            for(j=0;j<(a[i+1]-a[i])/r;j++)
            {
                res=res+r*abs(temp+j);
            }
            //右边还有余下的，不足一个r,此时gi的i可以用(a[i+1]-1)/r吗
            res=res+abs(i-(a[i+1]-1)/r)*((a[i+1]-a[i])%r);
        }
        //两边都不对齐
        else{
            //左边
             //cout<<"case4"<<endl;
            res=res+(r-a[i]%r)*(i-a[i]/r);
            temp=i-a[i]/r;
            numr=(a[i+1]-a[i])/r;
            for(j=0;j<=(a[i+1]-a[i])/r;j++)
            {
                res=res+r*abs(temp+j);
            }
            //右边
            res=res+(a[i+1]-1)%r*(i-(a[i+1]-1)/r);
        }
        //cout<<"res="<<res<<endl;
        //cout<<endl;
    }
    //还漏了a[n]到N
    if(N>a[n]+1)
    {
        temp=(a[n]+1)/r-n;
        for(j=0;j<(N-a[n])/r;j++)
        {
            res=res+abs(temp+j)*r;
         }
        if(N%r!=0)
        {
            res=res+abs(n-N/r)*(N%r);
        }
    }
    
    cout<<res<<endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

long long cal(long long fi, long long lft, long long rgt, long long r) {
	long long ans = 0, con_lft = ceil((double)lft / (double)r) * r, con_num = (rgt - con_lft + 1) / r;
	ans += r * (2 * (con_lft / r - fi) + con_num - 1) * con_num / 2 + (lft / r - fi) * (con_lft - lft) + (rgt / r - fi) * (rgt - con_lft - r * con_num + 1);
	return abs(ans);
}

int main()
{
	long long n, m, t;
	cin >> n >> m;
	vector<long long> a = {0};
	for (int i = 0; i < n; ++i) {
		cin >> t;
		a.push_back(t);
	}
	a.push_back(m);
	long long r = m / (n + 1), ans = 0;
	for (long long i = 0; i <= n; ++i) {
		long long lft = a[i], rgt = a[i + 1] - 1;
		if (lft / r >= i || rgt / r <= i) ans += cal(i, lft, rgt, r);	
		else ans += cal(i, lft, r * i, r) + cal(i, r * i + 1, rgt, r);
	}
	cout << ans << endl;
	return 0;
}
