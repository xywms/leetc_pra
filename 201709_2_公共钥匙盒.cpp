#include<bits/stdc++.h>
using namespace std;
struct tea
{
    int no;
    int start;
    int last;
};
vector<tea>v;
tea temp;
bool cmp(tea a,tea b)
{
    return (a.start+a.last)<(b.start+b.last);
}
bool cmp1(tea a,tea b)
{
    return a.no<b.no;
}
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,k,i,j,kk;
    int w,s,c;
    cin>>n>>k;
    int key[n+1];
    for(i=1;i<=n;i++)
    {
        key[i]=i;
    }
    for(i=0;i<k;i++)
    {
        cin>>w>>s>>c;
        temp.no=w;
        temp.start=s;
        temp.last=c;
        v.push_back(temp);
    }
    //按时间先还再取,如何求最大时间
    sort(v.begin(),v.end(),cmp);
    int lastime=v[k-1].start+v[k-1].last;
   // cout<<"lastime:"<<lastime<<endl;
    sort(v.begin(),v.end(),cmp1);
    for(i=1;i<=lastime+1;i++)
    {
        //还
        //如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。
        for(j=0;j<k;j++)
        {
            if(v[j].start+v[j].last==i)
            {
                for(kk=1;kk<=n;kk++)
                {
                    if(key[kk]==0)
                    {
                        key[kk]=v[j].no;
                        //cout<<"time"<<i<<"back"<<v[j].no<<endl;
                        break;
                    }
                }
            }
        }
        //取
        for(j=0;j<k;j++)
        {
            if(v[j].start==i)
            {
                //上一回的v[j].no是放哪儿的？
                for(kk=1;kk<=n;kk++)
                {
                    if(key[kk]==v[j].no)
                    {
                        key[kk]=0;
                    }
                }
                //cout<<"time"<<i<<"borrow"<<v[j].no<<endl;
            }
        }
    
    }
    for(i=1;i<=n;i++)
    {
        cout<<key[i]<<" ";
    }
    return 0;
}