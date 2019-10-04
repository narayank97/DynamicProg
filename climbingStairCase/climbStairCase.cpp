#include <iostream>

using namespace std;

int main(){
    int stairsAmount = 1000;
    int cacheSize = stairsAmount + 1;

    int cache[cacheSize];

    memset(cache,0,sizeof cache);

    // BASE CASES:
    cache[0] = 1; // 1 way to climb 0 stairs
    cache[1] = 1; // 1 way to climb 1 stairs

    // MEMOIZATION: EZ MODE
    for(int i = 2; i < cacheSize; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }

    cout << "It takes: "<< cache[stairsAmount] << " unique ways to climb, " << 
    stairsAmount<< " stairs." <<endl;

    return 0;
}