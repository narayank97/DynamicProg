#include <iostream>

using namespace std;

int main(){
    int a = 1;
    int b = 2;

    int sizeOfNums = 3;
    int nums[3] = {1,2,3};

    int cache[sizeOfNums+1];
    memset(cache,0,sizeof cache);

    for(int i = 1; i <= sizeOfNums; i++){
        cache[i] = cache[i-1] + nums[i-1];
    }

    for(int i = 0; i <= sizeOfNums; i++){
        cout << cache[i] << endl;
    }

    int answer = cache[b+1] - cache[a];
    cout << answer << endl;

    return 0;
}