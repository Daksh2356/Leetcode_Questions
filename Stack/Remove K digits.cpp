/*
Question : 402. Remove K Digits
Date : 11-04-24
Problem Difficulty level : Medium
Related Topics: Stack, Greedy, String, Monotonic Stack
Problem Statement:
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits 
from num.

 
Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:
1 <= k <= num.length <= 10^5
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        std::stack<char>smallest;


        // all small digits are put till condition of (top > curr) is met
        for(char c : num){
            while(!smallest.empty() && k>0 && smallest.top() > c){
                smallest.pop();
                k--;
            }

            smallest.push(c);
        }

        // pop the digits if k > 0 still
        while(k > 0 && !smallest.empty()){
            smallest.pop();
            k--;
        }

        // create the string result from the stack characters
        while(!smallest.empty()){
            result += smallest.top();
            smallest.pop();
        }

       std::reverse(result.begin(), result.end());

        // remove the leading '0s' from the string
        while(!result.empty() && result.front() == '0'){
            result.erase(result.begin());
        }


        return result.empty() ? "0" : result;
    }

    // time complexity = O(n) 
    // space complexity = O(n) also, where 'n' is length of num string
};