/*是给出一个数字n，要求利用1~n这n个数字构建一个完全二叉树，它有这样一个要求，
父节点和子节点的乘积为偶数，返回这棵树层序遍历的结果 */
#include<bits/stdc++.h>
using namespace std;
int main() {
    //先输出n以内全部的偶数，再输出n以内全部的奇数
    int ji = 1, ou = 2, n;
    cin>>n;
    while(ou <= n) {
        cout<<ou<<" ";
        ou = ou + 2;
    }
    while(ji <= n) {
        cout<<ji<<" ";
        ji = ji + 2;
    }
    return 0;
}