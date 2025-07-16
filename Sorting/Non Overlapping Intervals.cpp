/*
Date : 13/07/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Medium

Problem Statement:
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. 
Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

? Example 1:
Input: intervals[] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
* Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

? Example 2:
Input: intervals[] = [[1, 3], [1, 3], [1, 3]]
Output: 2
* Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.

? Example 3:
Input: intervals[] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
* Explanation: All ranges are already non overlapping.

Constraints:
! 1 ≤ intervals.size() ≤  10^5
! |intervalsi| == 2
! 0 ≤ starti < endi <=5*10^4
*/
// User function Template for Java

class Solution {
    static int minRemoval(int intervals[][]) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        
        int removalCount = 0, end = intervals[0][1];
        
        for(int i=1; i<intervals.length; i++){
            if(end > intervals[i][0]){
                removalCount++;
                end = Math.min(end, intervals[i][1]);
            } else{
                end = intervals[i][1];
            }
        }
        
        return removalCount;
        
    }
}

// time complexity = O(nlogn)
// space complexity = O(1)