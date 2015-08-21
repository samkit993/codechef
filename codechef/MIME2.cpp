#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    map<string,string> assoc;
    string temp1,temp2;
    for(int i=0;i<n;i++){
        cin >> temp1 >> temp2;
        assoc.insert(pair<string,string>(temp1,temp2));
    }
    //map<string,string>::iterator p;
    //for(p=assoc.begin();p!=assoc.end();p++){
        //cout << p->first << " : " << p->second << endl;
    //}
    for(int i=0;i<q;i++){
        string line;
        cin >> line;
        int j=line.size()-1;
        while(j>=0 && line[j]!='.'){
            j--;
        }
        ++j;
        string extension;
        string ans;
        if(j<0){
            ans = "unknown";
        }else{
            for(;j<line.size();j++)
                extension += line[j];
            //cout << extension << endl;
            if(assoc.find(extension)==assoc.end())
                ans = "unknown";
            else{
                ans = assoc[extension];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
