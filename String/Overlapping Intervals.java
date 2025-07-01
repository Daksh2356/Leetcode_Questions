/*
Date : 30/06/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Medium

Problem Statement:
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:
*Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].

*Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].

*Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105
*/

class Solution {
    public List<int[]> mergeOverlap(int[][] arr) {
        
        int n = arr.length;
        
        if(n<=1)
            return n == 1 ? Collections.singletonList(arr[0]) : new ArrayList<>();
            
        
        Arrays.sort(arr, (a,b) -> Integer.compare(a[0], b[0]));
        
        List<int[]> lst = new ArrayList<>();
        int[] temp = arr[0];
        
        for(int i =1; i<n; i++){
            if(temp[1] >= arr[i][0]){
                temp[1] = Math.max(temp[1], arr[i][1]);
            }else{
                lst.add(temp);
                temp = arr[i];
            }
        }
        
        lst.add(temp);
        return lst;
    }
}