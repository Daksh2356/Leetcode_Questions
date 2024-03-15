// Problem Description
 
// You are given two numbers represented as integer arrays A and B, where each digit is an element.
//  You have to return an array which representing the sum of the two given numbers.

// The last element denotes the least significant bit, and the first element denotes the most significant bit.

// Note : Array A and Array B can be of different size. ( i.e. length of Array A may not be equal to length of Array B ).


// Problem Constraints
// 1 <= |A|, |B| <= 10^5
// 0 <= Ai, Bi <= 9


// Input Format
// The first argument is an integer array A. The second argument is an integer array B.


// Output Format
// Return an array denoting the sum of the two numbers.


// Example Input
// Input 1:
// A = [1, 2, 3]
// B = [2, 5, 5]

// Input 2:
// A = [9, 9, 1]
// B = [1, 2, 1]


// Example Output
// Output 1:
// [3, 7, 8]

// Output 2:
// [1, 1, 1, 2]


// Example Explanation
// Explanation 1:
// Simply, add all the digits in their place.
// Explanation 2:

// 991 + 121 = 1112
// Note that the resultant array size might be larger.


// code : 
vector<int> sum(vector<int> &A, vector<int> &B, int n ,int m){
    int i = n - 1, j = m - 1;
    int carry = 0;
    int sum = 0;
    vector<int> result;
    
    while(j>=0){
        sum = A[i] + B[j] + carry;
        result.push_back(sum%10);
        carry = sum/10;
        i--;
        j--;
    }
    
    while(i>=0){
        sum = A[i] + carry;
        result.push_back(sum%10);
        carry = sum/10;
        i--;
    }
    
    if(carry > 0){
        result.push_back(carry);
    }
    
    reverse(result.begin(), result.end());
    
    return result;
    
}


vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int n  = A.size();
    int m = B.size();
    
    if(n>=m)
        return sum(A,B,n,m);
    else
        return sum(B,A,m,n);
}

// time complexity = O(max(n,m))
// space complexity = O(1) , where n = size of A and m = size of B