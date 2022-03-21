class Solution {
public:
void fastsort(vector<int>& nums,int l,int r) {
    int i = l, j = r;
    if(l > r) {
        return ;
    }
  //基准值相关操作如下
    int ran = l + rand() % (r -l + 1);
    int x = nums[ran];
    swap(nums[ran],nums[l]);
    while(i < j) {
        while(i < j && nums[j] > x) {
            j--;
        }
        if(i < j) {
            nums[i++] = nums[j]; 
        }
        while(i < j && nums[i] < x) {
            i++;
        }
        if(i < j) {
            nums[j--] = nums[i];
        }
    }
    //不要忘记下面这一行
    nums[i] = x;
    fastsort(nums, l, i - 1);
    fastsort(nums, i + 1, r);

}
    vector<int> sortArray(vector<int>& nums) {
        fastsort(nums, 0, nums.size()-1);
        return nums;
    }
};
