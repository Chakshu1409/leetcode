class Solution {
public:
        bool threeConsecutiveOdds(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Iterate over the array, stopping 2 elements before the end to avoid out-of-bounds access
        for (int i = 0; i <= n - 3; i++) {
            // Check if the current element is odd using bitwise AND operation
            if (arr[i] & 1) {
                // Check if the next element is odd
                if (arr[i + 1] & 1) {
                    // Check if the element after the next is odd
                    if (arr[i + 2] & 1) {
                        // If all three consecutive numbers are odd, return true
                        return true;
                    }
                }
            }
        }

        // If no such sequence is found, return false
        return false;
    }
};