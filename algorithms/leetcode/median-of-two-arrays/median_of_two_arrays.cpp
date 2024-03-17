#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution{
public:
    double brute_force(vector<int>& nums1, vector<int>& nums2) {
        /*
        @brief brute force solution to find the median of two sorted arrays
        @param nums1: vector of integers
        @param nums2: vector of integers
        @return median of the two arrays

        @example
        nums1 = [1, 3]
        nums2 = [2]
        median = 2.0

        nums1 = [1, 2]
        nums2 = [3, 4]
        median = 2.5

        nums1 = [0, 0]
        nums2 = [0, 0]
        median = 0.0

        @note
        time: O(nlogn)
        space: O(n)

        @details
        The idea is to merge the two arrays and then sort them. Then, we can find the median by checking if the length of the merged array is odd or even
        */
        //array lengths
        int n = nums1.size();
        int m = nums2.size();
        //merge
        int i{0}, j{0};
        vector<int> merged;
        while(i < n || j < m) {
            if (i < n) {
                merged.push_back(nums1[i++]);
            } else if (j < m){
                merged.push_back(nums2[j++]);
            }
        }
        //sort
        sort(merged.begin(), merged.end());
        
        if (merged.size() % 2 == 1) {
            return merged[merged.size() / 2];
        } else {
            return (merged[merged.size() / 2] + merged[merged.size() / 2 - 1]) / 2.0;
        }
    }
    double binary_search(vector<int>& nums1, vector<int>& nums2) {
        /*
        @brief binary search solution to find the median of two sorted arrays
        @param nums1: vector of integers
        @param nums2: vector of integers
        @return median of the two arrays

        @example
        nums1 = [1, 3]
        nums2 = [2]
        median = 2.0

        nums1 = [1, 2]
        nums2 = [3, 4]
        median = 2.5

        @note
        time: O(logn)
        space: O(1)

        @details
        The idea is to partition the two arrays such that the left partition is less than the right partition
        */
        int n=nums1.size(), m=nums2.size();
        if (n > m) return binary_search(nums2, nums1);
        int total{n + m}, left{(n + m + 1) / 2}, low{0}, high{n};
        while(low <= high) {
            int mid_num1{(low + high) >> 1}, mid_num2{(left - mid_num1)};
            auto l1{INT_MIN}, l2{INT_MIN}, r1{INT_MAX}, r2{INT_MAX};
            if (mid_num1 < n) r1 = nums1.at(mid_num1);
            if (mid_num2 < m) r2 = nums2.at(mid_num2);
            if (mid_num1 - 1 >= 0) l1 = nums1.at(mid_num1 - 1);
            if (mid_num2 - 1 >= 0) l2 = nums2.at(mid_num2 - 1);

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 1) {
                    return static_cast<double>(max(l1, l2));
                } else {
                    return static_cast<double>(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                high = mid_num1 - 1;
            } else {
                low = mid_num1 + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    auto header{"(brute force, binary search)"};
    cout << header << " -> (" << s.brute_force(nums1, nums2) << ", " 
        << s.binary_search(nums1, nums2) << ")" << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << header << " -> (" << s.brute_force(nums1, nums2) << ", " 
        << s.binary_search(nums1, nums2) << ")" << endl;

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << header << " -> (" << s.brute_force(nums1, nums2) << ", " 
        << s.binary_search(nums1, nums2) << ")" << endl;

    return 0;
}