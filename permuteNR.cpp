#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if(num.size() <=1)
        {
        	res.push_back(num);
        	return res;
        }
        //Put the elements in ascending order
        sort(num.begin(), num.end());       
        res.push_back(num);
        int i,j;
        while (1){
        	//Find if there is any strict asc order at i-1
        	i = num.size()-1;
        	while(i and num[i-1] >= num[i])
        		i--; 
        	
            //No asc order found; Done with all perm
            if(i == 0)
                return res;
            
			//Find nextHighestValue after i-1 
			j = num.size()-1;
        	while(j>i-1 and num[i-1] >= num[j])
        		j--;
        	
            //Move the NextHighestValue to i-1                   
            swap(num[i-1], num[j]);
            
            //Restore the order from i to end: Desc to Asc
            j = num.size()-1;
            while(i<j)
            {
            	swap(num[i], num[j]);
            	i++;j--;
            }
            res.push_back(num);
        }
        return res;
    }

    vector<vector<int> > res;
};

int main()
{
	Solution sol;
	int x[] = {1,1,3};
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
