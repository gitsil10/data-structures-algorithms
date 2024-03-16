/*
SF

Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb" 
Output: 3

Example 2:
Input: "bbbbb"
Output: 1

Example 3:
Input: "pwwkew"
Output: 3
*/
//imports
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
//data structure
class Solution {
public:
    //all unique
    bool all_unique(string str, int start, int end) {
        unordered_set<char> set;
        for (int i = start; i < end; i++) {
            char ch = str[i];
            if (set.find(ch) != set.end()) return false;
            set.insert(ch);
        }
        return true;
    }
    //brute force
    int brute_force_solution(string str) {
        int n = str.length(), ans{0};
        
        for (auto i{0}; i < n; i++) {
            for (auto j{i + 1}; j <= n; j++) {
                if (all_unique(str, i, j)) ans = max(ans, j - i);
            }
        }
        return ans;
    }
    //map
    int map_solution(string str) {
        //find the length of the longest substring without repeating characters
        int n = str.length(), ans{0};
        //unordered_map to store the index of the last occurrence of each character
        unordered_map<char, int> map;
        //two pointers, i and j
        for (auto j{0}, i{0}; j < n; j++) {
            //if the character is already in the map, move the pointer i to the right of the last occurrence of the character
            if (map.find(str[j]) != map.end()) i = max(map[str[j]], i);
            //update the answer
            ans = max(ans, j - i + 1);
            //update the index of the last occurrence of the character
            map[str[j]] = j + 1;
        }
        return ans;
    }
};

//run
int main(int argc, char **argv) {
    Solution s;
    auto strings = vector<string>();
    if (argc < 2) {
        string strs[] = {"abcabcbb", "bbbbb", "pwwkew"};

        for (string str : strs) strings.push_back(str);
        
    } else {
        for (auto i{1}; i < argc; i++) strings.push_back(argv[i]);
    }

    auto header{"(brute_force_solution, map_solution) ->"};
    for (auto str : strings) {
        auto first{str == strings.at(0)};
        if (first) cout << header;

        cout << "\t(" << s.brute_force_solution(str) << ',' 
            << s.map_solution(str) << ')';
    }
    return 0;
}