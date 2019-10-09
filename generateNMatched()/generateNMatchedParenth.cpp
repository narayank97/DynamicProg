#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateNMatchedParen(int leftParenCount, int rightParenCount, string stringInProg, vector<string> *result);

int main(){
    int left = 5;
    int right = 5;
    string myString = "";
    vector<string> myStringVec;

    generateNMatchedParen(left,right,myString,&myStringVec);

    for(int i = 0; i < myStringVec.size(); i++){
        cout << myStringVec[i] << "\t";
    }

    return 0;
}

void generateNMatchedParen(int leftParenCount, int rightParenCount, string stringInProg, vector<string> *result){
    if(leftParenCount == 0 && rightParenCount == 0){
        result->push_back(stringInProg);
        return;
    }
    if(leftParenCount > 0){
        generateNMatchedParen(leftParenCount-1,rightParenCount,stringInProg+"(",result);
    }
    if(rightParenCount > leftParenCount){
        generateNMatchedParen(leftParenCount,rightParenCount-1,stringInProg+")",result);
    }
}