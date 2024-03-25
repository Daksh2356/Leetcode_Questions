// Problem Description
 
// Find the number of integers in range [A, B] with last digit C.

// Problem Constraints
// 1 <= A <= B <= 10^9
// 0 <= C <= 9


// Input Format
// Given three integers A, B and C.


// Output Format
// Return an integer.


// Example Input
// Input 1:
// A = 11, B = 111, C = 1

// Input 2:
// A = 1, B = 9, C = 0


// Example Output
// Output 1:
// 11

// Output 2:
// 0


// Example Explanation
// Explanation 1:
// The integers are 11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111

// Explanation 2:
// There are no integers in the range with last digit 0.


// code : 

int Solution::solve(int A, int B, int C) {
    int count = 0;
    int cycles = (B-A+1)/10;
    int rem = (B-A+1)%10;
    
    for(int i = 0; i<=9; i++){
        if(i == C)
            count+= cycles;
    }
    
    for(int i=0; i<rem; i++){
        if( (A+i)%10 == C)
            count++;
    }

    return count;
    
    // space = O(1) => constant 
    // time = O(n) => from A to B that is linear
}
