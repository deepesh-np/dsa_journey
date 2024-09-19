#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> groups;

        // Step 1: Group numbers by their largest digit and keep track of the two largest numbers in each group
        for (int num : nums) {
            int largest = largestDigit(num);
            if (groups.find(largest) == groups.end()) {
                groups[largest] = {num, -1};
            } else {
                if (num > groups[largest].first) {
                    groups[largest].second = groups[largest].first;
                    groups[largest].first = num;
                } else if (num > groups[largest].second) {
                    groups[largest].second = num;
                }
            }
        }

        int maxSum = -1;

        // Step 2: Find the maximum sum of pairs within each group
        for (auto& group : groups) {
            if (group.second.second != -1) {
                maxSum = max(maxSum, group.second.first + group.second.second);
            }
        }

        return maxSum;
    }

private:
    // Helper function to find the largest digit in a number
    int largestDigit(int num) {
        int maxDigit = 0;
        while (num > 0) {
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }
};