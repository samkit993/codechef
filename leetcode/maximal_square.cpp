#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int min(int a, int b, int c){
	b = (a < b)? a : b;
	c = (b < c)? b : c;
	return c;
}
int maximalSquare(vector<vector<char> >& matrix){
	if(matrix.size() == 0)
		return 0;
	int nrows = matrix.size(), ncols = matrix[0].size();
	printf("nrows:%d ncols:%d\n", nrows,ncols);
	vector<vector<int> > ans_mat(nrows);
	for(int i=0;i<nrows;i++){
		ans_mat[i].resize(ncols);
	}
	for(int i=nrows-1;i>=0;i--){
		for(int j=ncols-1;j>=0;j--){
			if(matrix[i][j] == '0'){
				ans_mat[i][j] = 0;
			}else{
				if(i == nrows-1 || j == ncols-1){
					ans_mat[i][j] = 1;
				}else{
					ans_mat[i][j] = 1 + min(ans_mat[i][j+1], ans_mat[i+1][j], ans_mat[i+1][j+1]);
				}
			}
		}
	}
	int max = 0;
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncols;j++){
			printf("%d",ans_mat[i][j]);
			if(ans_mat[i][j] > max){
				max = ans_mat[i][j];
			}
		}
		cout << endl;
	}
	return max*max;
}
int main(){
	vector<vector<char> > matrix;
	for(int i=0;i<2;i++){
		vector<char> temp;
		for(int j=0;j<2;j++){
			temp.push_back('1');	
		}
		matrix.push_back(temp);
	}
	cout << maximalSquare(matrix);
	return 0;
}

