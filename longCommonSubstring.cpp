#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = /*"aab";//*/"GXTXAYB"; //7
    string s2 = /*"azb";//*/"AGGTAB"; //6
    int m = s1.length();
    int n = s2.length();
    int dpTable[m][n];

    int commonChar = 0;

    memset(dpTable, 0, sizeof (dpTable));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << dpTable[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    // cout << dpTable[2][2] << endl;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s1[i] == s2[j]){
                if(i == 0 || j == 0){
                    dpTable[i][j]++;
                    //dpTable[i][j] = 555;
                }
                else{
                    dpTable[i][j] = 1 + dpTable[i-1][j-1];
                    //dpTable[i][j] = 444;
                }
            }
            else{
                if(i == 0 && j != 0){
                    dpTable[i][j] = max(0,dpTable[i][j-1]);
                    //dpTable[i][j] = 333;

                }
                if(j == 0 && i != 0){
                    dpTable[i][j] = max(dpTable[i-1][j],0);
                   // dpTable[i][j] = 222;
                }
                if(i == 0 && j == 0){
                    //dpTable[i][j] = 111;
                    continue;
                }
                if(i != 0 && j != 0){
                    dpTable[i][j] = max(dpTable[i-1][j],dpTable[i][j-1]);
                    //dpTable[i][j] = 888;
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << dpTable[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Answer is : " << dpTable[m-1][n-1] << endl;

    return 0;
}
// testing git