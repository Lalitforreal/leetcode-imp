class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1); //{-1, -1}
        ans[0] = search(nums, target, true);
        if(ans[0] != -1){
            ans[1] = search(nums, target, false);
        }
        return ans;
    }


    int search(vector<int>& nums, int target , bool findFirstIndex){
            int ans = -1;
            int start = 0;
            int end = nums.size()-1;
            while(start <= end){
                int mid = start + (end - start)/2;

                if(target < nums[mid]){
                    end = mid -1 ;
                }else if(target> nums[mid]){
                    start = mid+1;
                }
                else{
                    ans = mid;
                    if(findFirstIndex == true){
                        end = mid -1;
                    }else{
                        start = mid+1;
                    }
                    
                }
            }
            return ans;
    }
};