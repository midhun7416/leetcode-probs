#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
int main()
{
	Solution sol;
	int A[] = {1,2,0};
	cout<<sol.firstMissingPositive(A, 0);
	return 0;
}
