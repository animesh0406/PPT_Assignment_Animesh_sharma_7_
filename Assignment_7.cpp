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


/*
<aside>
*Question 2**

Given a string num which represents an integer, return true *if* num *is a **strobogrammatic number***.

A **strobogrammatic number** is a number that looks the same when rotated 180 degrees (looked at upside down).

**Example 1:**

**Input:** num = "69"

**Output:**

true

</aside>
*/
#include<bits/stdc++.h>
using namespace std;
bool isStrobogrammatic(string num) {
        unordered_map<char, char> lut{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        for (int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r]) {
                return false;
            }
        }
        return true;
    }


#include<bits/stdc++.h>
using namespace std;
/*
<aside>
💡 **Question 3**

Given two non-negative integers, num1 and num2 represented as string, return *the sum of* num1 *and* num2 *as a string*.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

**Example 1:**

**Input:** num1 = "11", num2 = "123"

**Output:**

"134"

</aside>
*/
string addStrings(string num1, string num2) {
    if (num1.size() > num2.size())
	return addStrings(num2, num1);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string sum;
    int carry = 0, i = 0;

    for (; i < num1.size(); i++) {
    	int curDigit = (num1[i] - '0' + num2[i] - '0' + carry) % 10;
    	carry = (num1[i] - '0' + num2[i] - '0' + carry) / 10;
    	sum += to_string(curDigit);
    }
    for (; i < num2.size(); i++) {
    	int curDigit = (num2[i] - '0' + carry) % 10;
    	carry = (num2[i] - '0' + carry) / 10;
    	sum += to_string(curDigit);
    }
    if (carry == 1)
    	sum += "1";
    reverse(sum.begin(), sum.end());
    return sum;
}

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

/*
<aside>
💡 **Question 6**

Given two strings s and goal, return true *if and only if* s *can become* goal *after some number of **shifts** on* s.

A **shift** on s consists of moving the leftmost character of s to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

**Example 1:**

**Input:** s = "abcde", goal = "cdeab"

**Output:**

true

</aside>
*/

#include <bits/stdc++.h>
using namespace std;
 
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
 
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
 
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
 
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}




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






/*
Question 8
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / 
                (coordinates[1][0] - coordinates[0][0]);
       
        for(int i = 2; i < coordinates.size(); i++){
            vector<int> a = coordinates[i], b = coordinates[i-1];
            
            if(slope != (double)(a[1] - b[1]) / (a[0] - b[0])){
                return false;
            }
        }
        cout << endl;
        
        return true;
    }