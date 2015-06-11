#include <iostream>
#include<cmath>
#include <vector>
#include <unordered_map>
using namespace std;

/*
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
        	return false;
        bool res[s1.size()+1][s2.size()+1];
        for(int i=0;i<s1.size()+1;i++)
        {
        	for(int j=0;j<s2.size()+1;j++)
        	{
        		if(i==0 and j==0)
        			res[i][j] = true;
        		else if(i==0)
        			res[i][j] = res[i][j-1] and s2[j-1]==s3[i+j-1];
        		else if(j==0)
        			res[i][j] = res[i-1][j] and s1[i-1]==s3[i+j-1];
        		else
        			res[i][j] = (res[i-1][j] and s1[i-1] == s3[i+j-1])
        					  or(res[i][j-1] and s2[j-1] == s3[i+j-1]);
        	}
        }
        return res[s1.size()][s2.size()];
    }
};

int main()
{
	Solution sol;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout<<sol.isInterleave(s1,s2,s3);
	return 0;
}
