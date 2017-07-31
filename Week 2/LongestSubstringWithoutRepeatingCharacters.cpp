// Microsoft Interview College Program

// Week 2 - Problem 1 - Longest Substring Without Repeating Characters

/*
LEETCODE LINK: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 - Given "abcabcbb", the answer is "abc", which the length is 3.
 - Given "bbbbb", the answer is "b", with the length of 1.
 - Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

// TEBOW IT

// T - TALK
/*
 * Asumptions or clarifications
 - ASCII Standard [128]
 - Use any library
 - Caps sensitive
 */

// E - EXAMPLES
/*
	Sample Input 						->		Class				-> 			Out
	- bbbbbbb                           -> Same char                -> 1
	- ""                                -> Empty string     		-> 0
	- a                                 -> 1 char                   -> 1
	- r743f3, 4ehu4abcde                -> With numbers				-> 5, 8
	- 7.2!ag!, 1222:abc                 -> With special char		-> 6, 5
	- abccdfegh,pwwkew                  -> Standard Input           -> 6, 3
    - aAb, Aa                           -> Lower and upper letters  -> 3, 2
 */

// B - BRUTE FORCE
/*
    - Compare all the possible substrings, however this has an efficency of O (n^3)
 */

// O - OPTIMIZATION
/*
    - Assuming we have 128 ASCII
        - Use an array to save the length of the longest substring, using the ascii value for each char
    - Only need to loop through the string once, so we have a O(n) complexity
 */

// W - WALK THROUGH
/* 
    - Validate if empty
    - Validate if length 1
    - Get lenght
    - Start Loop until reach the end of the string
        - Compare the value stored in the array for the selected char with the previous stored value, and get the max
        - Compare the longest length with the current position less the stored value + 1, and get the max
        - Store the the current position + 1 in the array
        - Move position in string
 */

// I - IMPLEMENT
#include <iostream>

using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string str) {
        // Check if empty strig
        if (str == ""){
            return 0;
        }
        
        // Check if length is 1
        if (str.length() == 1){
            return 1;
        }
        
        int stringLength = int(str.length());
        int length = 0, storedValue = 0, index = 0;
        int ascii[128] = {0};
        
        while (index < stringLength) {
            // Compare the value stored in the array and the previous stored value, and get the max
            storedValue = max(ascii[str[index]], storedValue);
            // Compare the longest length with the current position less the stored value + 1, and get the max
            length = max(length, index - storedValue + 1);
            // Store the the current position + 1 in the array
            ascii[str[index]] = index + 1;
            // Move position in string
            index++;
        }
        return length;
    }
};

// T - TEST

int main() {
    
    Solution s;
    
    cout << "The Length of the Longest Substring Without Repeating Characters" << endl;
    
    // 1) Same char
    cout << "bbbbbbb is: " << s.lengthOfLongestSubstring("bbbbbbb") << endl;
    
    // 2) Empty string
    cout << "'' is: " << s.lengthOfLongestSubstring("") << endl;
    
    // 3) 1 char
    cout << "a is: " << s.lengthOfLongestSubstring("a") << endl;
    
    // 4) With numbers
    cout << "r743f3 is: " << s.lengthOfLongestSubstring("r743f3") << endl;
    
    // 5) With special char
    cout << "7.2!ag! is: " << s.lengthOfLongestSubstring("7.2!ag!") << endl;
    
    // 6) Standard Input
    cout << "abccdfegh is: " << s.lengthOfLongestSubstring("abccdfegh") << endl;
    
    // 7)  Lower and upper letters
    cout << "aAb is: " << s.lengthOfLongestSubstring("aAb") << endl;
    
    return 0;
}
