/*
Date : 14-03-24
Platform : GFG
Track : GFG-160-problems
Difficulty : Medium
Problem Statement:

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith
interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the
start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any
overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5
*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> result;

        // Add all smaller intervals that come before the new interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        // Merging overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        // Adding remaining intervals
        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

/*

another approach (but with TLE)
// User function Template for Java

class Solution {
    static ArrayList<int[]> insertInterval(int[][] intervals, int[] newInterval) {
        // code here
        ArrayList<int[]> intervalList = new ArrayList<>(Arrays.asList(intervals));
        
        intervalList.add(newInterval);
 
        intervals = intervalList.toArray(new int[0][]);
        
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        
        ArrayList<int[]> res = new ArrayList<>();
        
        int idx = 0;
        
        for(int i=1; i<intervals.length;i++){
            if(intervals[idx][1] >= intervals[i][0]){
              intervals[idx][1] = Math.max(intervals[idx][1], intervals[i][1]);
            } else{
              res.add(intervals[idx]);
              intervals[idx] = intervals[i];
            }
        }
        
        res.add(intervals[idx]);
        
        return res;
    }
}

*/