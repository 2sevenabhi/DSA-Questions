class Solution {
private:
    // Backtracking function to explore all possible distributions of cookies
    void backtrack(const vector<int>& cookies, int k, int index, int& minUnfairness, vector<int>& distribution) {
        // Calculate the maximum number of cookies received by any child
        int maxi = *max_element(distribution.begin(), distribution.end());

        // Base case: all cookies have been distributed
        if (index == cookies.size()) {
            // Update the minimum unfairness if the current distribution is smaller
            minUnfairness = min(minUnfairness, maxi);
            return;
        }

        // If the current minimum unfairness is smaller or equal to the maximum number of cookies,
        // there is no need to continue exploring this branch of the recursion
        if (minUnfairness <= maxi) {
            return;
        }

        // Try all possible choices for distributing the current cookie
        for (int i = 0; i < k; i++) {
            distribution[i] += cookies[index];  // Add the current cookie to the i-th child's distribution
            backtrack(cookies, k, index + 1, minUnfairness, distribution);  // Recursive call to explore further distributions
            distribution[i] -= cookies[index];  // Remove the current cookie from the i-th child's distribution (backtrack)
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        int minUnfairness = numeric_limits<int>::max();
        vector<int> distribution(k, 0);  // Track the number of cookies each child receives

        // Start the backtracking algorithm
        backtrack(cookies, k, 0, minUnfairness, distribution);
        
        return minUnfairness;  // Return the minimum unfairness found
    }
};