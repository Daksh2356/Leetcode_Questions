/*
Question : 67. Add Binary
Date : 15-02-24
Problem Difficulty level : Easy
Related Topics : Math, String, Bit Manipulation, Simulation

Problem Statement :
Given two binary strings a and b, return their sum as a binary string.

? Example 1:
Input: a = "11", b = "1"
Output: "100"

? Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
! 1 <= a.length, b.length <= 10^4
! a and b consist only of '0' or '1' characters.
! Each string does not contain leading zeros except for the zero itself.

*/
class Solution {
    public String addBinary(String a, String b) {
        int i = a.length()-1, j = b.length()-1, carry = 0;
        StringBuilder res = new StringBuilder();
        while(i >= 0 || j >= 0 || carry!=0){
            int sum = carry;
            if(i>= 0) sum += a.charAt(i--) - '0';
            if(j>= 0) sum += b.charAt(j--) - '0';
            res.append(sum%2);
            carry = sum/2;
        }
        return res.reverse().toString();
    }

    // time complexity = O(n)
    // space complexity = O(n)
}