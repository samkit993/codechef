#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define FOR(start, end) "for(int i=start;i<end;++i)"
#define REVFOR(end, start) "for(int i=end-1;i>=start;--i)"

#define DEBUG 0	
using namespace std;

unsigned long long ipow(int base, int power){
	unsigned long long ans = 1;
 	while( power != 0){	
		if( power & 1 == 1)
			ans *= base;
		base *= base; 
		power >>= 1;
	}
	return ans;
}


