class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; // If there is one value, return it.
		
        sort(nums.begin(), nums.end()); // Sort the vector, groups of three will appear beside each other
		
        int res{}; // Stores result
		
        for (int i{2}; i < nums.size(); i += 3) { // Progress in groups of three.
            if (nums[i]^nums[i-1]^nums[i-2] != nums[i]) { // Check the previous three elements. If they don't XOR to one of the elements
                if (nums[i]^nums[i-1] == 0) { //  then our single element is hidden in one of these three. 
                    res = nums[i-2]; // Check them individually. If two XOR to 0, the third one is out of place
                    break; // Important - break when you found it!
                }
                if (nums[i]^nums[i-2] == 0) {
                    res = nums[i-1];
                    break;
                }
                if (nums[i-i]^nums[i-2] == 0) {
                    res = nums[i];
                    break;
                }
            }
            if (i + 3 > nums.size()) return res = nums[nums.size()-1]; // Edge casae where single element is the last element.
        } // It is the last element if we still don't have a solution and 
		// we have processed the last group of three elements.
        return res;
    }
};