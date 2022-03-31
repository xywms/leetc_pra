/*
小美会做m种菜，每种菜只能做一份，现在有n个顾客，每个顾客点两道菜，两道菜都吃到才满意，问最多有多少顾客满意
*/
/*
输入：
3 4
1 2
2 3
3 4
输出：
2
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 22;
//vis判断食材是否被用过
int m, n, a[N], b[N], ans, vis[N];
//问题在于选顾客和不选顾客，cur是选了多少顾客
void dfs(int x, int cur) {
    if(x == n + 1) {
        ans = max(cur, ans);
        return ;
    }
    //选择
    if(!vis[a[x]] && !vis[b[x]]) {
        vis[a[x]] = 1;
        vis[b[x]] = 1;
        dfs(x + 1, cur + 1);
        //递归结束取消标记
        vis[a[x]] = vis[b[x]] = 0;
    }
    //不选择
    dfs(x + 1,cur);
}
int main() {
    int i ,j;
    cin>>n>>m;
    for(i = 1; i <= n; i++) {
        cin>>a[i]>>b[i];
    }
    dfs(1, 0);
    cout<<ans;
    return 0;
}