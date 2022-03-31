#include<bits/stdc++.h>
using namespace std;
//求0到i-1之间有多少个-1
vector<int> presum(vector<int> nums) {
    vector<int> cnt(nums.size(),0);
    for(int i = 0; i < nums.size(); i++) {
        cnt[i+1] =cnt[i]; 
        if(nums[i] == -1) {
            cnt[i + 1]++;
        }
    }
    return cnt;
}
int main() {
    int result = 0,n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    vector<int>cntf1 = presum(nums);
    //只要子序列中-1是偶数，，那么它们的乘积就是整数
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if((cntf1[j+1] - cntf1[i]) % 2 == 0) {
                result ++;
            }
        }
    }
    
    cout<<result;
    return 0;
}