#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,sum;
    while(n--)
    {
        stack<int>st;
        string s;
        cin>>s;
        for(i=0;s[i];i++)
        {
            if(s[i]>='1'&&s[i]<='9')
            {
                st.push(s[i]-'0');
            }
            else if(s[i]=='+')
            {
                st.push(s[++i]-'0');
            }else if(s[i]=='-')
            {
                st.push('0'-s[++i]);
            }else if(s[i]=='x')
            {
                sum=st.top();
                st.pop();
                st.push(sum*(s[++i]-'0'));
            }
            else if(s[i]=='/')
            {
                sum=st.top();
                st.pop();
                st.push(sum/(s[++i]-'0'));
            }
        }
        int ss=0;
        while(!st.empty())
        {
            ss=ss+st.top();
            st.pop();
        }
        if(ss==24)
        {
            cout<<"Yes"<<endl;
        }
        else 
            cout<<"No"<<endl;
            //cout<<"sum="<<ss<<endl;
    }
    return 0;
}
/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
*/