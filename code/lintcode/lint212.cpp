// lintcode 212.Space Replacement
// Easy
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
//比较好的写法  
/*
class Solution {
public:
    int replaceBlank(char s[], int length) {
        if(length == 0) return 0;
        int len = length;
        for(int i = 0; i < length; i++){
            if(s[i] == ' ')
                len = len + 2;
        }
        int res = len;
        s[len] = '\0';
        --len;
        for(int i = length - 1; i >= 0; i--){
            if(s[i] == ' '){
                s[len--] = '0';
                s[len--] = '2';
                s[len--] = '%';
            }
            else
                s[len--] = s[i];
        }
        return res;
    }
};
*/

//我自己写的比较挫 
class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    string s="";
    int replaceBlank(char string[], int length) {
        // Write your code here
        if(length == 0) return 0;
        int begin = 0, end = 0;
        while(end < length)
        {
        	if(string[end] != ' ')	end++;
        	else
        	{
        		for(int j=begin; j<end; j++)
        			s += string[j];
        		end++;
        		begin = end;
        		s += "%20";
        	}
        }
        for(int i=begin; i<length; i++)	s += string[i];
        for(int i=0; i<s.size(); i++)
        	string[i] = s[i];
        string[s.size()] = '\0';
        //cout << string << endl;
        //cout << s << endl;
        return s.size();
    }
};  


int main()
{
	Solution sol;
	char s[] = "hello world";
	int len = strlen(s);
	cout << sol.replaceBlank(s, len) << endl;
	return 0;
}
