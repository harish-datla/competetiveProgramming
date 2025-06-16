/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
// #include <bits/stdc++.h> // doesnt work on g++ on windows
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(size_t i = 0 ; i < nums.size() ; i++){
            if(mp.count(target-nums[i])){
                return vector<int>{int(i),mp[target-nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};

template<typename T>
bool areEqual(const T&a, const T&b){
    return a == b;
}
// @lc code=end
template<>
bool areEqual<vector<int>>(const vector<int>& a, const vector<int>& b){
    if(a.size() != b.size()) return false;
    for(size_t i = 0 ; i < b.size() ; i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}


struct TwoSumInput{
    vector<int> nums;
    int target;
};

struct TestCase{
    string description;
    TwoSumInput input;
    vector<int> expected;
};

int main(){
    Solution solution;
    vector<TestCase> testCases = {
        {"Normal case: ",{{2,6,1,9,11}, 13},{0,4}},
        {"Duplicate Case: ", {{3,3,4}, 6},{0,1}},
        {"Negative Case:", {{-1,-2,-6,-3,-4},-9}, {2,3}},
        {"Zeros", {{0,4,3,0},0}, {0,3}},
        {"Empty result", {{1,2,3},11}, {}}
    };

    for(size_t i = 0 ; i < testCases.size() ; i++){
        auto& tc = testCases[i];
        vector<int> expectedOutput = tc.expected;
        vector<int> actualOutput = solution.twoSum(tc.input.nums, tc.input.target);
        sort(actualOutput.begin(), actualOutput.end());
        bool matched = areEqual(expectedOutput, actualOutput);
        cout << "Test case " << i+1 << ": " << tc.description << "--->"
             << (matched? "Passed" : "Failed") << endl;

        if(!matched){
            cout << "Expected : ";
            for(int x : expectedOutput) cout << x << " ";
            cout << "\nGot : ";
            for(int x : actualOutput) cout << x << " ";
            cout << endl;
        }
    }
}
