class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //双指针逆序放入
        //0左侧的数平方之后按从大到小排列，右侧从小到大
        //所以left与right比较，取大值排在结果数组的末尾,指针移动，结果并向前排
        int left = 0, right = nums.size() - 1;
        int n = nums.size()-1;
        vector<int>res(n+1);
        while(left <= right && right >= 0 && n >= 0) {
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                res[n--] = nums[left] * nums[left];
                left++;
            }else {
                res[n--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};
