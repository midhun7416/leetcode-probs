#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> can(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++)
        {
        	if(ratings[i]>ratings[i-1])
        		can[i] = can[i-1]+1;
        }
        for(int i=ratings.size()-1;i>0;i--)
        {
        	if(ratings[i] <ratings[i-1])
        		can[i-1] = max(can[i]+1, can[i-1]);
        }
        int res=0;
        for(int i=0;i<can.size();i++)
        	res+=can[i];
        return res; 
    }
};

int main()
{
	Solution sol;
	int x[] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> v(x, x+sizeof(x)/sizeof(x[0]));
	cout<<sol.candy(v);
	return 0;
}
