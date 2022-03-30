/*
题目1：给A,B,X,Y四个值，其中A和B分别代表两个怪物的血量，X和Y分别代表两个技能对怪物造成的伤害，
不同的是，X是单体伤害，Y是群体伤害（对A和B都造成Y伤害），求杀死（A和B小于等于0）两只怪物所需的最小技能数
输入:5 2 3 1
输出:3
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    //把大的统一放前面
    if(a < b) {
        swap(a, b);
    }
    //分情况讨论
    //情况一：使用技能一
    int ans1 = a/x + (a % x != 0) + b/x + (b % x != 0);
    //情况二：使用技能二
    int ans2 = a/y + (a % y != 0);
    //情况三:先用技能二打血量少的那个
    //如果不能整除
    int ans3;
    if(b % y) {
        int ans3 = (a-(b - b % y + y))/x + ((a-(b - b % y + y)) % x != 0) + b/y + 1; 
    }else 
    {
        int ans3 = (a - b)/x + ((a - b) % x != 0) + b/y ;
    }
    int res = min(min(ans1,ans2),ans3);
    cout<<res;
    
}
