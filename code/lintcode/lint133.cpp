// lintcode 133.Longest Words
// Easy 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int len = dictionary.size();
        int maxn = 0;
        for(int i=0; i<len; i++)
        {
        	int x = dictionary[i].size();
        	maxn = max(maxn, x);
        }
        vector <string> vs;
        for(int i=0; i<len; i++)
        {
        	if(dictionary[i].size() == maxn)
        		vs.push_back(dictionary[i]);
        }
        return vs;
    }
};

int main()
{
	vector <string> dictionary;
	dictionary.push_back("like");
	dictionary.push_back("love");
	dictionary.push_back("yes");
	Solution sol;
	vector <string> v;
	v = sol.longestWords(dictionary);
	for(int i=0; i<v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
