class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         return helper(nums, k) - helper(nums, k - 1); // at most k - at most (k-1)
    }
    int helper(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ctr = 0, sum = 0;
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (nums[i]%2 == 0) nums[i] = 0; // even no. -> 0
            else{
                nums[i] = 1; // odd no. -> 1
                flag = true;
            }
        }
        if (!flag) return 0; // if no odd no. => no subarrays with k odd
        while (r<n){
            sum += nums[r]; // sum used to calculate no. of odd
            while (sum >k){ // shrink if no. of odd exceeds k 
                sum -= nums[l];
                l++;
            }
            if (sum <= k) ctr += r - l + 1; // no. of subarrays having atmost k odd
            r++;
        }
        return ctr; 
    }
};