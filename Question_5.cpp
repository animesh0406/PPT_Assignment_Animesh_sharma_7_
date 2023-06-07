/*
<aside>
*Question 5**

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

**Example 1:**

**Input:** s = "abcdefg", k = 2

**Output:**

"bacdfeg"

</aside>
*/
#include <bits/stdc++.h>
using namespace std;
 string reverseStr(string s, int k)
    {
        int n=s.length();
        if(k>n)
        { 
            reverse(s.begin(),s.end());
            return s;
        }
      
       int j=0;
    string ans;
    
    for (int i = 0; i < n; i += (2 * k))
    {
        string temp = s.substr(i, k);
        reverse(temp.begin(), temp.end());
        ans += temp;

        j += k ;
        while (j < n && j < (i+2*k))
        {
            ans.push_back(s[j]);
            j++;
        }
    }
    return ans;
        
    }