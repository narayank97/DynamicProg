#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class item{
    public:
        int value;
        int weight;

        item(){
            value = 0;
            weight = 0;
        }

        item(int v, int w){
            value = v;
            weight = w;
        }
};



int main(){
    vector<item> myItems;
    
    item item1(60,5);
    myItems.push_back(item1);
    item item2(50,3);
    myItems.push_back(item2);
    item item3(70,4);
    myItems.push_back(item3);
    item item4(30,2);
    myItems.push_back(item4);

    int maxWeight = 5;

    int dpTable[4][6];

    memset(dpTable,0,sizeof dpTable);

    int numItems = 4;

    for(int i = 0; i <= maxWeight; i++){
        if(i >= item1.weight){
            dpTable[0][i] = item1.value;
        }
    }

    for(int i = 1; i < numItems; i++){
        for(int j = 0; j <= maxWeight; j++){
            
            int currentItemValue = myItems[i].value;
            int currentItemWeight = myItems[i].weight;
            //if we can choose the item we have to compare with it and without it
            if(j >= currentItemWeight){
                int wihtout = dpTable[i-1][j];
                int with = currentItemValue + dpTable[i][j-currentItemWeight];
                dpTable[i][j] = max(with,wihtout);
            }
            // if we cant choose the item then ....
            else{
                dpTable[i][j] = dpTable[i-1][j];
            }

        }
    }

    for(int i = 0; i < numItems; i++){
        for(int j = 0; j <= maxWeight; j++){
            cout << dpTable[i][j] << "\t";
        }
        cout << endl;
    }

    
    
    return 0;
}