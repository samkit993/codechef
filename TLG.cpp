#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int rounds;
    scanf("%d",&rounds);
    int lead, leading;
    int temp1,temp2;
    int player1=0, player2=0;
    int maxLead = 0,winner;
    for(int i=0;i<rounds;++i){
        scanf("%d %d",&temp1,&temp2);
        player1 += temp1;
        player2 += temp2;
        if(player1 > player2){
            leading = 1;
            lead = player1 - player2;
        }else{
            leading = 2;
            lead = player2 - player1;
        }
        //cout << leading << " " << lead << endl;
        if(lead > maxLead){
            maxLead = lead;
            winner = leading;
        }

    }
    printf("%d %d\n",winner,maxLead);
    return 0;
}
