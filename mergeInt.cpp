#include <iostream>
#include<cmath>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for an interval.
 */
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

class Solution {
public:
	struct compare
	{
		bool operator()(const Interval &i1, const Interval &i2)
		{
			if(i1.start == i2.start)
				return i1.end<i2.end;
			return i1.start<i2.start;
		}
	};
    vector<Interval> merge(vector<Interval> &intervals) {
    	if(intervals.size()<=1)
    		return intervals;
        sort(intervals.begin(),intervals.end(), compare());
        for(int i=0;i<intervals.size();i++)
		{
			cout<<intervals[i].start<<intervals[i].end<<endl;
		}
        vector<Interval> res;
        Interval curr(intervals[0].start, intervals[0].end);
        for(int i=1;i<intervals.size();i++)
        {
        	if(intervals[i].start > curr.end)
        	{
        		if(i==intervals.size()-1) {
        			res.push_back(curr);
        			res.push_back(intervals[i]);
        		}
        		else {
        			res.push_back(curr);
        			curr.start = intervals[i].start;
        			curr.end = intervals[i].end;
        		}
        	} else {
        		curr.end = max(curr.end, intervals[i].end);
        		if(i==intervals.size()-1)
        			res.push_back(curr);
        	}
        }
        return res;
    }
};

int main()
{
	Solution sol;
	vector<Interval> intervals;
	intervals.push_back(Interval(2,3));
	intervals.push_back(Interval(4,5));
	intervals.push_back(Interval(6,7));
	intervals.push_back(Interval(8,9));
	intervals.push_back(Interval(1,10));
	vector<Interval> vec = sol.merge(intervals);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].start<<vec[i].end<<endl;
	}
	return 0;
}
