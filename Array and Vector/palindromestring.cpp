// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string a = "";
        string b = "";
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        {
            while (!isalnum(s[i]) && i < j)
                i++;
            while (!isalnum(s[j]) && i < j)
                j--;
            if (!(tolower(s[i]) == (tolower(s[j]))))
                return false;
        }
        return true;
    }
};