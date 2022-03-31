/*题目2:给出一个字母字符串，如果相邻两个字母相同或者在字母表中相邻，则标记这两个字母，
并把这两个字母的分数加到你获得的分数中，‘a’等于1，‘b’等于2，以此类推，要求被标记过的不能再使用  
输入:a b d b b
输出:7
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    char s[101];
    //从第二位开始输入,方便后面的操作
    cin>>s + 1;
    int n = strlen(s + 1);
    vector<int> dp(101,0);
    //设置初始值
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        //字母相等或相邻
        if(abs(s[i] - s[i - 1]) <= 1) {
            dp[i] = max(dp[i], dp[i-2] + (s[i] - 'a' + 1) + (s[i-1] - 'a' + 1));
        }
    }
    cout<<dp[n];
    return 0;
}