#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};

bool compare(Interval a, Interval b){
	if (a.start == b.start)
		return a.end > b.end;
	else
		return a.start < b.start;
}

vector<Interval> merge(vector<Interval> & intervals){
	 if(intervals.size() == 0 || intervals.size() == 1)
			return intervals;
	sort(intervals.begin(), intervals.end(), compare);
	int currStart = intervals[0].start, currEnd = intervals[0].end;
	vector<Interval> ans;
	printf("currStart:%d currEnd:%d interval[i].start:%d interval[i].end:%d\n",currStart, currEnd, intervals[0].start, intervals[0].end);
	for(int i=1;i<intervals.size();++i){
		printf("currStart:%d currEnd:%d interval[i].start:%d interval[i].end:%d\n",currStart, currEnd, intervals[i].start, intervals[i].end);
		if(currEnd >= intervals[i].start){
			currEnd = intervals[i].end;
			if(currStart > intervals[i].start)
				currStart = intervals[i].start; 
		}else{
			Interval temp(currStart, currEnd);
			ans.push_back(temp);
			currStart = intervals[i].start;
			currEnd = intervals[i].end;
		}
	}
	Interval temp(currStart, currEnd);
	ans.push_back(temp);
	return ans;
}
int main(){
	Interval b(0,5);
	Interval a(1,4);
	Interval c(8,10);
	Interval d(15,18);
	vector<Interval> ivals,ans;
	ivals.push_back(a);
	ivals.push_back(b);
	ivals.push_back(c);
	ivals.push_back(d);
	ans = merge(ivals);
	for(int i=0;i<ans.size();++i){
		printf("start:%d end:%d\n",ans[i].start, ans[i].end);
	}
	return 0;
}
