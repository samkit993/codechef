#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

map<string,int> users;

int main(){
    int tCases;
    scanf("%d",&tCases);
    for(int t=0;t<tCases;t++){
        users.clear();
        int n;
        string str;
        string temp;
        cin >> n;
        cin.ignore();
        while(n > 0){
            temp.clear();
            getline(cin,str);
            //cout << str << endl;
            n--;
            for(int i=0;str[i]!=' ';i++){
                temp += str[i];
            }
            //cout << temp << endl;
            if(str[str.size()-1]=='+'){
                users[temp] = 1;
            }else if(str[str.size()-1]=='-'){
                users[temp] = -1;
            }
        }
        //cout << users.size();
        map<string,int>::iterator it;
        int sum = 0;
        for(it=users.begin();it!=users.end();it++){
            //cout << it->first << " : " << it->second << endl;
            sum += it->second;
        }
        cout << sum << endl;
    }
    return 0;
}
