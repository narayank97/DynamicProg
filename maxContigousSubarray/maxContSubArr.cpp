#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int myVec[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int max = 0;
    int prev = myVec[0];

    // start from second element because max subarray with 1 element is itself
    for(int i = 1; i < 9; i++){
        int usedPrev = myVec[i]+prev;
        int best = std::max(usedPrev, myVec[i]);
        prev = best;
        
        if(max < best){
            max = best;
        }
    }
    cout << max << endl;
    return 0;
}