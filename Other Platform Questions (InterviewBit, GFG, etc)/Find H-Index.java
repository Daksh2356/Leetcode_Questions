/*
Date : 09/07/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Medium

Problem Statement:
Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

? Example 1:
Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
* Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

? Example 2:
Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
* Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.

? Example 3:
Input: citations[] = [0, 0]
Output: 0

Constraints:
! 1 ≤ citations.size() ≤ 10^6
! 0 ≤ citations[i] ≤ 10^6
*/

class Solution {
    // Function to find hIndex
    public int hIndex(int[] citations) {
        // code here
    Integer[] arr = Arrays.stream(citations).boxed().toArray(Integer[] :: new);
    Arrays.sort(arr, Collections.reverseOrder());
    
    int idx = 0 , n = arr.length;
    while(idx < n && arr[idx] > idx){
        idx++;
    }
    
    return idx;
    }
}

// time complexity = O(nlogn)
// space complexity = O(n)


2nd approach:

    Arrays.sort(citations);
    
    int n = citations.length;
    
    for(int i=0; i<n; i++){
        int h = n-i;
        
        if(citations[i] >= h)
            return h;
    }
    
    return 0;

// time complexity = O(nlogn)
// space complexity = O(1)