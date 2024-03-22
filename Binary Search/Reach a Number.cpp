/*
Question : 754. Reach A Number
Date : 22-03-24
Problem Difficulty level : Medium
Related Topics: Math, Binary Search

!Problem Statement:
    - You are standing at position 0 on an infinite number line. There is a destination at position target.
    - You can make some number of moves numMoves so that:
         On each move, you can either go left or right.
         During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.

?Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.

Example 1:
Input: target = 2
Output: 3
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to -1 (2 steps).
On the 3rd move, we step from -1 to 2 (3 steps).

Example 2:
Input: target = 3
Output: 2
Explanation:
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to 3 (2 steps).
 
Constraints:
-10^9 <= target <= 10^9
target != 0
*/


class Solution {
public:
    int reachNumber(int target) {

        target = abs(target); // for handling cases where target < 0
                              // here moving on the positive side will also give the same results
        int temp = 0; // total number of steps moved 
        int numMoves = 0; // min number of moves to reach target

        while(temp < target || (temp-target)%2 != 0){
            temp += ++numMoves;
        }

        return numMoves;
    }

    // time complexity = O(target)
    // space complexity = O(1)
};