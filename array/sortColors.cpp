class Solution {
public:
    //follow up answer
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int mid = 0;
        int last = n -1;

        while(mid<=last){ //less than 2
            if(nums[mid] == 0){
                swap(nums[first], nums[mid]);
                first++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{//
                swap(nums[mid], nums[last]);
                last--;
            }
        }
    }
};