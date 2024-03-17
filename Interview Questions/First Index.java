Problem Description

You are given an array A of length N. You need to solve Q queries. In each query, you will be given an integer B[i] and you need to 
find the index of the element which is at least B[i]. If there are several such indexes, return the minimum such index. Return -1 if no 
such index exists.

Note- The array is 0 indexed.

Problem Constraints
1 <= N,Q <= 5 x 10^5 
1 <= A[i], B[i] <= 10^9


Input Format
The first argument contains an integer array A of length N.
The second argument contains an integer array B of length Q, denoting the queries.


Output Format
Return an array of length Q, containing the answer to the queries.


Example Input

  Input 1:

  A : [ 9, 1 ]
  B : [ 7, 10, 3 ]

  Input 2:
   A : [ 2, 3, 4 ]
  B : [ 2, 3, 4 ]


Example Output

  Output 1:
  [0, -1, 0]

  Output 2:
  [0, 1, 2]

  // code : 
  public class Solution {
    public ArrayList<Integer> solve(ArrayList<Integer> A, ArrayList<Integer> B) {
         ArrayList<Integer> result = new ArrayList<>();
       
        for(int i = 0; i < B.size(); i++){
           
            int minIndex = -1;
           
            for(int j = 0; j < A.size(); j++){
               
                if(A.get(j) >= B.get(i)){
                    minIndex=j;
                    break;
                }    
            }
            result.add(minIndex);
        }
       
        return result;
    }
    }