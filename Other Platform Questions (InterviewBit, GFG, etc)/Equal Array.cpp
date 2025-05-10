/*
INTERVIEW BIT QUESTION
Problem Description

Given an integer array A of size N, you are asked to make all the elements of the array equal by performing the following operation minimum number of times.

Choose any element and do the bitwise XOR with 2x, where x >= 0.
Return the minimum number of operations required.



Problem Constraints
1 <= N <= 105

0 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return the minimum number of operations required.



Example Input
Input 1:

 A = [10, 1, 4, 2]
Input 2:

 A = [5, 7, 4, 3, 5]


Example Output
Output 1:

 5
Output 2:

 4


Example Explanation
Explanation 1:

 We will make all the values equal to 2 or 0 so that the operations required are minimum, i.e 5.
Explanation 2:

 We will make all the values equal to 5 so that the operations required are minimum, i.e 4.
*/

// code: 

int Solution::solve(vector<int> &A) {
        int n = A.size();
    int arr[32] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 30; j++){
            if(A[i] & (1 << j))
                arr[j]++;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 30; i++){
        ans += min(arr[i], n - arr[i]);
    }
    return ans;
}
