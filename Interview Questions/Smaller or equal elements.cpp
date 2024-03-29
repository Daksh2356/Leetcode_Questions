// ! Problem Description

// ? Given an sorted array A of size N. Find number of elements which are less than or equal to B.

// ? NOTE: Expected Time Complexity O(log N)


// ! Problem Constraints
// ! 1 <= N <= 10^6
// !1 <= A[i], B <= 10^9


// ! Input Format
// !First agument is an integer array A of size N.
// !Second argument is an integer B.

// ! Output Format
// !Return an integer denoting the number of elements which are less than or equal to B.


// ?Example Input
// ? Input 1:

//  ? A = [1, 3, 4, 4, 6]
//  ? B = 4

// ? Input 2:

//  ? A = [1, 2, 5, 5]
//  ? B = 3


// ?Example Output
// ? Output 1:
//  ? 4

// ? Output 2:
//  ? 2


// ! Example Explanation

// ! Explanation 1:
// ! Elements (1, 3, 4, 4) are less than or equal to 4.

// ! Explanation 2:
// ! Elements (1, 2) are less than or equal to 3.

// !? code
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int left = 0;
    int right = n -1;
    int count = 0;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(A[mid] <= B){
            count += (mid-left) +1;        
            left = mid + 1;
        }
        else    
            right = mid - 1;
    }
    
    return count;
}
