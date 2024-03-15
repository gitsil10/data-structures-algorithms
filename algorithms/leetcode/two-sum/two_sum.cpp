//two sum cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSumOn2(vector<int>&, int);
    vector<int>twoSumOn(vector<int>&, int);
}
vector<int> Solution::twoSumOn2(vector<int> &nums, int target) {
    /*
    brute force approach
    time o(n^2)
    space o(1)

    iterate through the array and find the sum of each pair
    */
    vector<int> result;
    for (auto i{0}; i < nums.size(); i++) {
        for (auto j{i+1}; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}
vector<int> Solution::twoSumOn(vector<int> &nums, int target) {
    /*
    hash map approach
    time o(n)
    space o(n)

    iterate through the array and find the difference of the target and the current element
    if the difference is found in the hash map, return the index of the difference and the current index
    */
    unordered_map<int, int> hash_map;
    vector<int> result;
    for (auto i{0}; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (hash_map.find(diff) != hash_map.end()) {
            result.push_back(hash_map[diff]);
            result.push_back(i);
            return result;
        }
        hash_map[nums[i]] = i;
    }
    return result;
}
