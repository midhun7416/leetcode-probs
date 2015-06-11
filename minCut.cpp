#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int n = s.size();
        vector<vector<bool> > bpal(n+1, vector<bool>(n+1,0));
        vector<int> minCut(n,INT_MAX);
        minCut[n-1] = 0;
        for(int i=n-2;i>=0;i--)
        {
        	for(int len=1;len<n+1-i;len++)
        	{
        		if(s[i] ==s[i+len-1] and (len<=2 or bpal[i+1][len-2]))
        		{
        			bpal[i][len] = true;
        			if(i+len==n)
        				minCut[i] = 0;
        			else if(i+len<n and minCut[i+len] !=INT_MAX)
        				minCut[i] = min(minCut[i+len]+1, minCut[i]);
        		}
        	}
        }
        return minCut[0];
    }
};

int main()
{
	Solution sol;
	string s="abcccb";
	cout<<endl;
	cout<<sol.minCut(s)<<endl;
	return 0;
}
