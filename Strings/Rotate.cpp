// A Program to check if strings are rotations of each other or not
// Difficulty Level : Easy
// Last Updated : 06 Nov, 2020
// Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
// Algorithm: areRotations(str1, str2)
//  1. Create a temp string and store concatenation of str1 to
//        str1 in temp.
//                           temp = str1.str1
//     2. If str2 is a substring of temp then str1 and str2 are
//        rotations of each other.

//     Example:
//                      str1 = "ABACD"
//                      str2 = "CDABA"

//      temp = str1.str1 = "ABACDABACD"
//      Since str2 is a substring of temp, str1 and str2 are
//      rotations of each other.

// C++ program to check if two given strings
// are rotations of each other
#include <bits/stdc++.h>
using namespace std;

/* Function checks if passed strings (str1
and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

/* Driver program to test areRotations */
int main()
{
    string str1 = "AACD", str2 = "ACDA";
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
