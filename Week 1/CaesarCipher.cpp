
// Microsoft Interview College Program

// Week 1 - Problem 1 - Caesar Cipher

/*
The code you will write is based on the “Caesar Cipher” where each letter is shifted a certain number of places 
left or right through the alphabet. The alphabet is treated as being circular so that the first letter follows 
after the last letter, and the last letter precedes the first letter.  These ideas will be applied separately 
to uppercase letters, lower case letters, and digits. For example, with a shift of 1, ‘A’ becomes ‘B’, 
‘Z’ becomes ‘A’, ‘a’ becomes ‘b’, ‘z’ becomes ‘a’, ‘0’ becomes ‘1’, ‘9’ becomes ‘0’. Spaces, punctuation, 
and any other symbols are unaffected in this scheme. Your task is to write a function to encrypt a string 
using this Caesar Cipher. 

INPUT FORMAT
Your function will take an input string that begins with a number representing the shift. 
The number will be in the range -1000000000 to 1000000000 (negative 1 billion to 1 billion). 
The number is followed by a colon (‘:’). The rest of the line consists of a string of 1 to 200 
arbitrary characters and represents a fragment of the text to be encrypted.
 
OUTPUT FORMAT
Output will be the corresponding encrypted text fragment
  
SAMPLE INPUT:
1:some text
 
SAMPLE OUTPUT:
tpnf ufyu
*/

// TEBOW IT

// T - TALK
/*
 * Asumptions or clarifications
 	- Allowed to use any library
 	- Ignore "special characters" (leave them like that)
 	- Throw exception if not valid input:
 		- Wrong number
 		- Wrong string length
 		- ":" not found
 */

// E - EXAMPLES
/*
	Sample Input 										->		Class				-> 			Out
	- :23A, :Sfds!										-> No number found 			-> "Input Error"
	- 9:   , 1:											-> Empty string     		-> "Input Error"
	- 0:fh34e, 0:dhefAd									-> 0 shifts					-> fh34e, dhefAd
	- r743fdhu3, 4ehui!43								-> No found :				-> "Input Error"
	- 7.232:dfdf, 1111111111:f 							-> Wrong number				-> "Input Error"
	- -92323:a!36 Abc,  -89212121:ySaewS aw121 			-> Negative shift (left)	-> d!03 Def, nHptlH pl010
	- 232:ABCAbcZaz, 123232322:dEH43@					-> Positive shift (right)	-> YZAYzaXyx, vWZ65@
*/

// B - BRUTE FORCE
/*
string caesarCipher(string str) {
	Start Loop until length of str
		If not number and not : //Invalid char in number input
			break
		If : found and is not in first position nor last one
			Save position of :
	End loop

	If : not found
		return "Error"

	If shift number is empty
		return "Empty number"

	If shift number is not in range
		return "Error"

	If string is empty
		return "Empty text"

	If string to cipher is longer
		return "Error"

	Start Loop until length of str
		Check if char is number
			char in string = char in string + (shift % 10)
		Check if char is letter
			char in string = char in string + (shift % 26)
		Check if any other char
			char in string = char in string
	End Loop

	return str
}

*/

// O - OPTIMIZATION 
/*
	- Make certain validations by making them inside the loop, and if something is not valid we return inmediatly "Error"
*/

// W - WALK THROUGH


// I - IMPLEMENT
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Caesar Cipher function
// Param    : string str
// Returns  : string text
string caesarCipher(string str){
    
    // Variables
    long shiftNumber = 0;
    string text = "";
    bool found = false;         // Boolean to mark if : was found
    
    for (long i = 0; i < str.length(); i++){ // O(n) Time Complexity
        // Validate if char is a valid number (positive or negative) or :
        if ((isnumber(str[i]) || str[i] == ':' || str[i] == '-' ) && !found) {
            // Validate if char is : and not on the first position
            if (str[i] == ':' && i != 0){
                shiftNumber = stoi(str.substr(0,i)); // Get number with atoi function
                text = str.substr(i+1,str.length() - i);
                found = true;
                
                // Number range validation
                if ((shiftNumber < -1000000000) || (shiftNumber > 1000000000)){
                    return "Input Error";
                }
                
                // Empty text validation
                if (text == "") {
                    return "Input Error";
                }
                
                // String wrong length validation
                if (text.length() > 200) {
                    return "Input Error";
                }
                
                // Check for 0 shifts
                if (shiftNumber == 0) {
                    return text;
                }
            }
        }
    }
    
    // If : wasn't found
    if (!found) {
        return "Input Error";
    }
    
    for (long i = 0; i < text.length(); i++){
        
        // Check if char is number
        if (isnumber(text[i])){
            // Depending on the shift number
            // If the char arrives to the end
            // We change it to the beginning
            if (text[i] == '9' && shiftNumber > 0){
                text[i] = text[i] - 10;
            }
            
            if (text[i] == '0' && shiftNumber < 0){
                text[i] = text[i] + 10;
            }
            
            text[i] = text[i] + (shiftNumber % 10);
        }
        
        // Check if char is letter
        else if (isalpha(text[i])) {
            bool isLower = false;
            
            if (islower(text[i])) {
                isLower = true;
            }
            
            if ((text[i] == 'z' || text[i] == 'Z') && shiftNumber > 0){
                text[i] = text[i] - 26;
            }
            
            if ((text[i] == 'a' || text[i] == 'A') && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
            text[i] = text[i] + (shiftNumber % 26);
            
            // If the new char is bigger than Z or z
            // We add or substract update the value of the char
            if (text[i] > 'z' && isLower && shiftNumber > 0){
                text[i] = text[i] - 26;
            }
            
            if (text[i] > 'Z' && !isLower && shiftNumber > 0){
                text[i] = text[i] - 26;
            }

            if (text[i] < 'a' && isLower && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
            if (text[i] < 'A' && !isLower && shiftNumber < 0){
                text[i] = text[i] + 26;
            }
            
        }
        // Any other char stays the same
        else {
            text[i] = text[i];
        }
    }
    
    return text;
}

int main(){
    cout << "TEST CASES" << endl;
    
    cout << "1) No number found" << endl;
    cout << caesarCipher(":23A") << ", " << caesarCipher(":Sfds!") << endl;
    
    cout << "2) Empty string " << endl;
    cout << caesarCipher("9:") << ", " << caesarCipher("1748343:") << endl;
    
    cout << "3) 0 shifts	" << endl;
    cout << caesarCipher("0:fh34e") << ", " << caesarCipher("0:dhefAd") << endl;
    
    cout << "4) No found :" << endl;
    cout << caesarCipher("r743fdhu3") << ", " << caesarCipher("4ehui!43") << endl;
    
    cout << "5) Wrong number" << endl;
    cout << caesarCipher("7.232:dfdf,") << ", " << caesarCipher("1111111111:f") << endl;
    
    cout << "6) Negative shift (left)" << endl;
    cout << caesarCipher("-92323:a!36 Abc") << ", " << caesarCipher("-89212121:ySaewS aw121") << endl;
    
    cout << "6) Positive shift (right)" << endl;
    cout << caesarCipher("232:ABCAbcZaz") << ", " << caesarCipher("123232322:dEH43@") << endl;

    return 0;
}

// T - TEST
/*
TEST CASES
1) No number found
Input Error, Input Error

2) Empty string 
Input Error, Input Error

3) 0 shifts	
fh34e, dhefAd

4) No found :
Input Error, Input Error

5) Wrong number
kmkm,, Input Error

6) Negative shift (left)
d!03 Def, nHptlH pl010

6) Positive shift (right)
YZAYzaXyx, vWZ65@
*7
