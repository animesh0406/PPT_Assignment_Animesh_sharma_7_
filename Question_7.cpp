/*
<aside>
💡 **Question 7**

Given two strings s and t, return true *if they are equal when both are typed into empty text editors*. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

**Input:** s = "ab#c", t = "ad#c"

**Output:** true

**Explanation:**

Both s and t become "ac".

</aside>
*/
#include <bits/stdc++.h>
using namespace std;
 

string removeBackspaces(string& s)
{
    int n = s.size();
 
    int idx = 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') {
            s[idx] = s[i];
            idx++;
        }
        else if (s[i] == '#' && idx >= 0) {
            idx--;
        }
        if (idx < 0)
            idx = 0;
    }
 
    return s.substr(0, idx);
}