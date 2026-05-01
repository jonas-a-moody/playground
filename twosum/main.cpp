#include <iostream> 
#include <vector> 

/*
Constraints: 
    . 2 <= nums.length <= 10^4
    . -10^9 <= nums[i] <= 10^9
    . -10^9 <= target <= 10^9
    . Only one valid answer exists
*/

int two_sum(std::vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++) { 
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                std::cout << "[" << i << ", " << j << "]\n";
                return 0; 
            }
        }        
    }
    return 0; 
}

int main() {
    std::vector<int> nums = {3,2,4};
    int target = 6;
    two_sum(nums, target); 
    return 0; 
}