//
// Created by kimdoseong on 2022-10-11.
//

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        auto first = nums.begin();
        auto last = nums.end();

        while (true) {
            auto range_length = distance(first, last);
            auto mid = first + floor(range_length / 2);
            auto mid_idx = floor(range_length / 2);

            if (*mid == target) {
                return static_cast<int>(mid - nums.begin());
            } else if (*mid > target) {
                advance(last, -mid_idx);
            } else {
                advance(first, mid_idx);
            }

            if (range_length == 1) {
                if (*first > target) {
                    return static_cast<int>(distance(nums.begin(), first));
                } else {
                    return static_cast<int>(distance(nums.begin(), last));
                }
            }
        }
    }
};

int main() {
    vector<int> nums{1, 3, 5, 6};

    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
}
