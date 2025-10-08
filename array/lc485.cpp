class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int max = 0;
        int n = nums.size();
        for(int i = 0; i< n ; i++){
            if(nums[i] == 1){
                counter++;
            }else{
                if(counter > max){
                    max = counter;
                    counter = 0;
                }else{ //reset counter
                    counter =0;
                }
            }
        }
        //now what if last elem is 1 
        if(counter > max){
            max = counter;
        }
        return max;
    }
};