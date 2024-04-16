class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int last = nums.size();
        if(target > nums[last - 1]) return last;
        while(start <= last){
            int mid = (start + last) / 2;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) last = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};