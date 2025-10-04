class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        int max = 0;
        int n = nums.size();
        int j = -1;
        for(int i = 0; i<n-1; i++){ //find first zero
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1){ //no zeroes
            return;
        }

        for(int i = j+1; i< n; i++){
            if(nums[i]!= 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};