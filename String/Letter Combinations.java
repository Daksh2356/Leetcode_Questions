/*
Question : 17. Letter Combinations of a Phone Number
Date : 03-08-23
Problem Difficulty level : Medium
Related Topics : Hash Table, String and Backtracking

Problem Statement:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */

public class Solution {
    List<String> combinations = new ArrayList<>();

    private void generateCombinations(Map<Integer,String> digitMapping, int start, 
    String digits, StringBuilder res )
    {
        if(res.length() == digits.length())
        {
            combinations.add(res.toString());
            return;
        }

        int digit = Character.getNumericValue(digits.charAt(start));
        String characters = digitMapping.get(digit);

        for(char c : characters.toCharArray())
        {
            res.append(c);
            generateCombinations(digitMapping, start+1, digits, res);
            res.deleteCharAt(res.length()-1);
        }
    }
    public static Map<Integer, String> buildMapping(String digits, List<Character>[] table) {
        Map<Integer, String> digitMapping = new HashMap<>();
        for (int i = 0; i < digits.length(); i++) {
            int digit = Character.getNumericValue(digits.charAt(i));
            if (digit >= 2 && digit <= 9) {
                String characters = "";
                for (char ch : table[digit - 2]) {
                    characters += ch; // Map to lowercase characters
                }
                digitMapping.put(digit, characters);
            }
        }
        return digitMapping;
    }

    public List<String> letterCombinations(String digits) {  
         if (digits.isEmpty()) {
            return combinations; 
        }
        List<Character>[] table = new ArrayList[] {
                new ArrayList<>(List.of('a', 'b', 'c')), // Lowercase characters here
                new ArrayList<>(List.of('d', 'e', 'f')),
                new ArrayList<>(List.of('g', 'h', 'i')),
                new ArrayList<>(List.of('j', 'k', 'l')),
                new ArrayList<>(List.of('m', 'n', 'o')),
                new ArrayList<>(List.of('p','q', 'r', 's')),
                new ArrayList<>(List.of('t', 'u', 'v')),
                new ArrayList<>(List.of('w', 'x', 'y', 'z'))
        };
        
        Map<Integer, String> digitMapping = buildMapping(digits, table);
        StringBuilder res = new StringBuilder("");
        
        // Generate all possible combinations
        generateCombinations(digitMapping, 0, digits, res);
        
        return combinations;
    }

    // time complexity = O(N + 4^N)
    // space complexity = O(M + N + K) - M is for Map, N is for String Builder and K is for storing combinations

}
