#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

class Solution {
public:
	bool possible(int row, int col, vector<string> &temp, vector<int> &ColOfRow)
	{
		for(int i=0;i<row;i++)
		{
			if(temp[i][col] == 'Q')
				return false;
			if(fabs(row-i) == fabs(col-ColOfRow[i]))
				return false;
		}	
		return true;
	}
	
	void recSolve(int row, int n, vector<string> &temp, vector<vector<string> > &res,
					vector<int> &ColOfRow)
	{
		if(n==row)
		{
			res.push_back(temp);
			return;
		}
		for( int col=0;col<n;++col)
		{
			//If possible, Keep a queen in the col; try for next row;
			if(possible(row, col, temp, ColOfRow))
			{
				temp[row][col] = 'Q';
				ColOfRow[row] = col;
				recSolve(row+1, n, temp, res , ColOfRow);
				temp[row][col] = '.';
			}
		}
	}
	
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        	vector<string> temp(n, string(n, '.'));//Each string has 9 dots
        	vector<int> ColOfRow(n, -1);
			recSolve(0, n, temp, res, ColOfRow);
			return res;
    }
};

int main()
{
	Solution sol;
	vector<vector<string> > res = sol.solveNQueens(4);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<endl;
		}
		cout<<endl<<endl<<endl;
	}
	return 0;
}
