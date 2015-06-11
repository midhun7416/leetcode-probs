#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int res=0;
	bool possible(int row, int col, vector<int> &ColOfRow)
	{
		for(int i=0;i<row;i++)
		{
			if(fabs(row-i) == fabs(col-ColOfRow[i]) || ColOfRow[i]==col)
				return false;
		}	
		return true;
	}
	
	void recSolve(int row, int n, vector<int> &ColOfRow)
	{
		if(n==row)
		{
			res++;
			return;
		}
		for( int col=0;col<n;++col)
		{
			if(possible(row, col, ColOfRow))
			{
				ColOfRow[row] = col;
				recSolve(row+1, n, ColOfRow);
			}
		}
	}
	
    int totalNQueens(int n) {
        	vector<int> ColOfRow(n, -1);
			recSolve(0, n, ColOfRow);
			return res;
    }
};

int main()
{
	Solution sol;
	cout<<sol.totalNQueens(10);
	return 0;
}
