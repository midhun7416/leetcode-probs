#include <iostream>
#include<cmath>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> umap;
        int res = 0;
        for(int i=0;i<num.size();i++)
        {
        	if(umap.find(num[i]) == umap.end())
        	{
        		int left = (umap.find(num[i]-1)==umap.end()) ? 0: umap[num[i]-1];	
        		int right = (umap.find(num[i]+1)==umap.end()) ? 0: umap[num[i]+1];
        		int seq = left+1+right;	
        		res = max(res, seq);
        		//Update the seq for left and right ends of the seq
        		umap[num[i]] = seq;
        		umap[num[i]-left] = seq;
        		umap[num[i]+right] = seq;
        	}
        }
        return res;
    }
};
int main()
{
	Solution sol;
	int x[] = {100, 4, 200, 1, 3, 2};
	vector<int> A(x, x+sizeof(x)/sizeof(x[0]));
	cout<<sol.longestConsecutive(A);
	return 0;
}
