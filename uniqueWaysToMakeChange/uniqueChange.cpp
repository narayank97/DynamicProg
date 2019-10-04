#include <iostream>

using namespace std;

int main(){
    int amount = 5;
    int coins[3] = {1,2,5};

    int coinsSize = 3+1;
    int amountSize = amount + 1;

    int dpTable[coinsSize][amountSize];

    memset(dpTable,0,sizeof dpTable);

    // ------------------------ STARTS HERE ----------------------------------------

    // cant make change with no coins
    for(int i = 0; i < amountSize; i++){
        dpTable[0][i] = 0;
    }

    //
    for(int i = 0; i < coinsSize; i++){
        dpTable[i][0] = 1;
    }

    for(int i = 1; i < coinsSize; i++){
        for(int j = 1; j < amountSize; j++){
            if((j-coins[i-1]) < 0){
                dpTable[i][j] = dpTable[i-1][j];
                continue;
            }
            
            dpTable[i][j] = dpTable[i-1][j] + dpTable[i][j-coins[i-1]];
        }
    }
    cout << dpTable[coinsSize-1][amountSize-1] << endl;
    // -------------------------- ENDS HERE ----------------------------------------
    return 0;
}