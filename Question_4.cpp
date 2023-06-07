/*
<aside>
💡 **Question 4**

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

**Input:** s = "Let's take LeetCode contest"

**Output:** "s'teL ekat edoCteeL tsetnoc"

</aside>
*/
#include<bits/stdc++.h>
using namespace std;
void reverseWords(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ')
            st.push(str[i]);
 
    
        else {
            while (st.empty() == false) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }

    while (st.empty() == false) {
        cout << st.top();
        st.pop();
    }
}