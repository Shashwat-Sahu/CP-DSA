class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0;  //Initialize variable with 0
        int maxsum = INT_MIN; //Initialize variable with the loweset integer number
        for(int i=0;i<nums.size();i++){
            currentsum+=nums[i]; //Add the values till the ith element of array 
            maxsum = max(maxsum,currentsum); //Check if the value is bigger than the max value, if it is update max value with that number, if it's not nothing will change
            if(currentsum<0)
                currentsum=0; //If the added value is less than 0, update the currentsum value with 0 since if the next element contains negetive value it will add it (- and - is +) and we don't want it to happen
        }
        return maxsum; //Return the maxsum of the array
    }
    
};
