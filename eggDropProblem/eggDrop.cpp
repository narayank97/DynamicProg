#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int eggs = 2;
    int totalFloors = 23;

    int dpEggsSize = eggs +1;
    int dpTotalFloors = totalFloors + 1;

    int dpTable[dpEggsSize][dpTotalFloors];
    
    memset(dpTable,0,sizeof(dpTable));

    // Initialize base case 1 where if one egg
    for(int i = 0; i < dpTotalFloors; i++){
        dpTable[1][i] = i;
    }

    // Initialize base case 2 where no matter how many eggs and if you have one floor
    // then if the egg doesnt break it would take only 1 drop.

    // If it does break it is covered by the memset already
    for(int i = 1; i < dpTotalFloors; i++){
        dpTable[i][1] = 1;
    }
    // -------------------------- Start Here ----------------------------------

    for(int i = 2; i < dpEggsSize; i++){
        for(int currentFloor = 2; currentFloor < dpTotalFloors; currentFloor++){
            
            int finalAmount = 0;
            int min = 100000000;
            

            for(int k = 1; k <= currentFloor; k++){
                int max = 0;
                int simulatedNonBreak = i;
                int simulatedBreak = i-1;
                
                int simulatedFloorNonBreak = currentFloor - k; // move up
                int simulatedFloorBreak = k - 1; // move down

                if(dpTable[simulatedNonBreak][simulatedFloorNonBreak]
                   > dpTable[simulatedBreak][simulatedFloorBreak]){
                       max = dpTable[simulatedNonBreak][simulatedFloorNonBreak];
                       
                }
                if(dpTable[simulatedNonBreak][simulatedFloorNonBreak]
                   <= dpTable[simulatedBreak][simulatedFloorBreak]){

                    max = dpTable[simulatedBreak][simulatedFloorBreak];
        
                }
                if(max < min){
                    min = max;
                }
            }

            finalAmount = 1 + min;
            
            dpTable[i][currentFloor] = finalAmount;
        
        }
    }



    // -------------------------- End Here  ------------------------------------
    for(int i = 0; i < dpEggsSize; i++){
        for(int j = 0; j < dpTotalFloors; j++){
            cout << dpTable[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}