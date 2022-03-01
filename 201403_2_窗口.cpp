#include<bits/stdc++.h>
using namespace std;
//用什么存储这多个窗口和它的层数呢，map，vector?
struct w
{
    int x1,y1,x2,y2,no,pos;
};
bool cmp(w a,w b)
{
    return a.pos<b.pos;
}
vector<w>v(20);
int main()
{
    int n,m,i,j,x,y,flag=0,cur,k;
    cin>>n>>m;
    v.resize(n);
    //输入从下层到顶层
    for(i=0;i<n;i++)
    {
        cin>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
        v[i].no=i+1;
        //顶层最小,不减一只有90分？
        v[i].pos=n-i-1;
    }
    
    //点击
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        flag=0;
        //从顶层到底层遍历窗口
        sort(v.begin(),v.end(),cmp);
        /*
        for(auto a:v)
        {
            cout<<"after sorting:"<<a.x1<<a.y1<<a.x2<<a.y2<<endl;
        }
        */
        for(j=0;j<n;j++)
        {
            if(x>=v[j].x1&&x<=v[j].x2&&y>=v[j].y1&&y<=v[j].y2)
            {
                //将该窗口放至顶层1
                cur=v[j].pos;
                //必须是0吗
                v[j].pos=0;
                //输出窗口编号
                cout<<v[j].no<<endl;
                flag=1;
                //其他窗口层数怎么变化
                for(k=0;k<cur;k++)
                {
                    v[k].pos++;
                }
                break;
            }
        }
        if(flag==0)
        {
            cout<<"IGNORED"<<endl;
        }

    }
    return 0;
}