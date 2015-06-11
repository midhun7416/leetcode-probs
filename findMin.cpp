#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
		k = min(n-1,k);
        vector<vector<int> > profits(prices.size(), vector<int>(k+1, 0));
		if(n<2)
			return -1;
        profits[n-1][0] = 0;
        profits[n-2][1] = max(prices[n-1]-prices[n-2], 0);
        for(int i=n-3;i>=0;i--)
        {
        	for(int j=i+1;j<n;j++)
        	{
				profits[i][0] =  max(profits[i][0],profits[j][min(n-j,k)]);
				for(int l=1;l<min(n-j,k)+1;l++)
				{
					profits[i][l] = max(profits[i][l-1],profits[i][l]);
					profits[i][l] = max(profits[i][l], prices[j]-prices[i]+profits[j][l-1]);
				}
        	}
        }
		return profits[0][k];
    }
};

int main()
{
	Solution sol;
	int x[] = {4, 5, 6};
	vector<int> v(x, x+sizeof(x)/sizeof(x[0]));
	int k=9;
	cout<<sol.maxProfit(k, v);
	return 0;
}
