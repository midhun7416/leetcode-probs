#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
	struct compare
	{
		bool operator()(int a, int b)
		{
			return a>b;
		}
	};
	public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		priority_queue<int>  MXH;
		priority_queue<int, vector<int> , compare> MNH;
		int i=0,j=0, sa=0, sb=0;
		while(i<m and j<n)
		{
			int X= min(A[i], B[j]);
			A[i] > B[j] ? j++ : i++;
			if(sa==0)
			{
				MXH.push(X);
				sa++;
				continue;
			} else if(sb==0)
			{
				sb++;
				if(X>MXH.top())
				{
					MNH.push(X);
					continue;
				} else {
					MNH.push(MXH.top());
					MXH.pop();
					MXH.push(X);
					continue;
				}
			}
			if(X<MNH.top())
			{
				MXH.push(X);
				sa++;
			} else {
				MNH.push(X);
				sb++;
			}
			if(sa>sb+1)
			{
				MNH.push(MXH.top());
				MXH.pop();
				sb++;
			} else if(sa+1<sb){
				MXH.push(MNH.top());
				MNH.pop();
				sa++;
			}
		}
		while(i<m)
		{
			int X=A[i];i++;
			if(sa==0)
			{
				MXH.push(X);
				sa++;
				continue;
			} else if(sb==0)
			{
				sb++;
				if(X>MXH.top())
				{
					MNH.push(X);
					continue;
				} else {
					MNH.push(MXH.top());
					MXH.pop();
					MXH.push(X);
					continue;
				}
			}
			if(X<MNH.top())
			{
				MXH.push(X);
				sa++;
			} else {
				MNH.push(X);
				sb++;
			}
			if(sa>sb+1)
			{
				MNH.push(MXH.top());
				MXH.pop();
				sb++;
				sa--;
			} else if(sa+1<sb){
				MXH.push(MNH.top());
				MNH.pop();
				sa++;
				sb--;
			}
		}
		while(j<n)
		{
			int X=B[j];j++;
			if(sa==0)
			{
				MXH.push(X);
				sa++;
				continue;
			} else if(sb==0)
			{
				sb++;
				if(X>MXH.top())
				{
					MNH.push(X);
					continue;
				} else {
					MNH.push(MXH.top());
					MXH.pop();
					MXH.push(X);
					continue;
				}
			}
			if(X<MNH.top())
			{
				MXH.push(X);
				sa++;
			} else {
				MNH.push(X);
				sb++;
			}
			if(sa>sb+1)
			{
				MNH.push(MXH.top());
				MXH.pop();
				sb++;
				sa--;
			} else if(sa+1<sb){
				MXH.push(MNH.top());
				MNH.pop();
				sa++;
				sb--;
			}
		}
		//cout<<sa<<sb<<" ";
		if(sa==sb)
		{
			return(double)(MXH.top()+MNH.top())/2.0;
		} else if(sa>sb){
			return (double)MXH.top();
		} else if(sa<sb){
			return (double)MNH.top();
		} else
			return -1;
	}
};

int main()
{
	Solution sol;
	int A[] = {};
	int B[]= {1,2,3,4};
	//1 2 3 4 5 6 8
	cout<<sol.findMedianSortedArrays(A, 0, B, 4);
	return 0;
}

