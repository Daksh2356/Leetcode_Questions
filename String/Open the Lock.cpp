/*
Question : 752. Open the Lock
Date : 22-04-24
Problem Difficulty level : Medium
Related Topics : Array, Hash table, String and Breadth First Search

Problem Statement:
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 

The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel 
one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and 
you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the 
lock, or -1 if it is impossible.


Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.
 
Constraints:
1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.

*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        // edge case => if the initial combination is our target only
        if (target == "0000")
            return 0; 

        // set to lookup for deadend combinations
        unordered_set<string> deadends_set(deadends.begin(),
                                           deadends.end()); // O(d) space

        // edge case => if initial combination or target is a dead end
        if(deadends_set.count("0000") || deadends_set.count(target))
            return -1;

        // queue to store the visited combinations and their movies
        queue<pair<string, int>> q; // uses 8^4 of the space
        q.push(
            {"0000", 0}); // initial combination ("0000") is passed in the queue

        // set to lookup for the visited combinations
        unordered_set<string> visited; // can use 8^4 of the space
        visited.insert("0000");

        // check if queue is empty or not
        while (!q.empty()) {
            auto curr = q.front();
            q.pop(); // remove the combination at front of queue

            string currCombo = curr.first; // current combination formed
            int moves =
                curr.second; // current total number of rotate moves taken

            if (currCombo == target) // target is reached to open the lock
                return moves;

            for (int i = 0; i < 4; i++) {
                for (int delta :
                     {-1, 1}) { // the wheel can be rotated either left or right
                    int newDigit = (currCombo[i] - '0' + delta + 10) % 10;
                    string newCombo = currCombo;
                    newCombo[i] = '0' + newDigit;

                    // if the newCombination is not in visited and deadends
                    // sets, then add it and proceed
                    if (visited.find(newCombo) == visited.end() &&
                        deadends_set.find(newCombo) == deadends_set.end()) {
                        visited.insert(newCombo);
                        q.push({newCombo, moves + 1});
                    }
                }
            }
        }

        return -1; // target not reachable
    }

    // time complexity = O(8^4) = O(1)=> traverse through all the 8^4 possible
    // combinations
    // space complexity =  O(8^4 + d) => where d is the total
    // number of deadends given in input
};