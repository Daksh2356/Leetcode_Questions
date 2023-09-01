/*
Question : 767. Reorganize String
Date : 23-08-23
Problem Difficulty level : Medium
Related Topics : String, Hash, Heap and Greedy
Problem Statement:
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> charCount;
        for(char c : s)
        {
            charCount[c]++;
        }

        auto compare = [] (const pair<char,int> &a , const pair<char,int> &b) {
            return a.second < b.second;
        };

        priority_queue<pair<char,int>, vector<pair<char,int>> , decltype(compare)> maxHeap
        (compare);

        for(const auto& entry: charCount)
        {
            maxHeap.push({entry.first, entry.second});
        }

        string result = "";

        while(!maxHeap.empty())
        {
            pair<char,int> curr = maxHeap.top();
            maxHeap.pop();       // highest priority element is popped from top of priority Q

            if(result.empty() || result.back() != curr.first)
            {
                result += curr.first;
                if(--curr.second > 0 )
                {
                    maxHeap.push(curr);
                }
            }

            else
            {
                if(maxHeap.empty())
                {
                    return "";
                }
                
                pair<char,int> next = maxHeap.top();
                maxHeap.pop();

                result +=next.first;
                if(--next.second > 0)
                {
                    maxHeap.push(next);
                }
                maxHeap.push(curr);  // Put back the previous character for next iteration
            }
        }
            return result;
    }

    // time complexity = O(logn)
    // space complexity = O(n)

};