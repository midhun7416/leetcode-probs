#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void swap(vector<int> &num, int i, int j)
	{
		num[i] = num[i] xor num[j];
		num[j] = num[i] xor num[j];
		num[i] = num[i] xor num[j];
	}
	void permute(vector<int> num, vector<vector<int> > &res, int curr)
	{
		if(curr==num.size())
		{
			res.push_back(num);
			return;
		}
		for(int i=curr;i<num.size();i++)
		{
			if(i==curr)
				permute(num, res, i+1);
			else {
				if(num[i]!=num[curr])
				{
					swap(num, i, curr);
					permute(num, res, curr+1);
					swap(num, i, curr);
				}
			}
		}
	}
	
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        permute(num, res, 0);
        return res;
    }
};

int main()
{
	Solution sol;
	int x[] = {1,2,1};
	vector<int> v(x, x+sizeof(x)/sizeof(x[0]));
	vector<vector<int> > res = sol.permuteUnique(v);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();++j)
			cout<<res[i][j];
		cout<<endl;
	}
	return 0;
}
