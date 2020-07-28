class Solution {
    
public:
    void qSort(vector<int>& nums, int first, int last) {
        if (first < last) {
            int left = first, right = last, middle = nums[(left + right) / 2];
            do {
                while (nums[left] < middle) left++;
                while (nums[right] > middle) right--;
                if (left <= right) {
                    int tmp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = tmp;
                    left++;
                    right--;
                }
            } while (left <= right);
            qSort(nums, first, right);
            qSort(nums, left, last);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        qSort(nums, 0, nums.size() - 1);
        return nums;
    }
};