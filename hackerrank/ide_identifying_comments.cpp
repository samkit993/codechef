#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	string temp;
	bool multiline = false, multifound = false;
	while(getline(cin,temp)){
		string comment;
		bool singleline=false;
		int i,multistart = 0;
		for(i=1;i<temp.size();++i){
			if(temp[i-1] == '/' && temp[i] == '*'){
				multiline = true;
				multistart = i-1;
				i++;
			}
			if(multiline == true  && temp[i-1] == '*' && temp[i] == '/'){
				cout << temp.substr(multistart,i+1) << endl;
				//cout << "Multiline set false" << endl;
				multiline = false;
				break;
			}
			if(temp[i-1] == '/' && temp[i] == '/'){
				//cout << "Singleline set true" << endl;
				//printf("Temp %d %d : %c %c \n" ,i-1,i,temp[i-1] ,temp[i]);
				singleline = true;
				cout << temp.substr(i-1,temp.size()) << endl;
				break;
			}
		}
		if(i == temp.size() && multiline == true){
			cout << temp << endl;
		}
	}
	return 0;
}

