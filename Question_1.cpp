/*
<aside>
*Question 1**

Given two strings s and t, *determine if they are isomorphic*.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true

</aside>
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string str1, string str2)
{
 
    int m = str1.length(), n = str2.length();
 
    if (m != n)
        return false;
    bool marked[MAX_CHARS] = { false };
 
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
 
   
    for (int i = 0; i < n; i++) {
       
        if (map[str1[i]] == -1) {
           
            if (marked[str2[i]] == true)
                return false;
 
            
            marked[str2[i]] = true;
 
            map[str1[i]] = str2[i];
        }
 
       
        else if (map[str1[i]] != str2[i])
            return false;
    }
 
    return true;
}