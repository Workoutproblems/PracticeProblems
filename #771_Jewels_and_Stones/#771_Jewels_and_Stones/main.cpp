/*
 You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
 
 The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
 
 Example 1:
 Input: J = "aA", S = "aAAbbbb"
 Output: 3
 
 Example 2:
 Input: J = "z", S = "ZZ"
 Output: 0
 */

#include <iostream>
#include <set>
using namespace std;


void numJewelsInStones(string J, string S){
    
    //  Build, ea. char has a unique key.
    //  https://www.youtube.com/watch?v=nj_ks4TPU1s
    set<char> setJ(J.begin(), J.end());
    
    int set = 0;
    //  iterate over string to be searched.
    //  count() : returns number of occurences of current 's'.
    for(char s : S)
        if(setJ.count(s))
            set++;
    
    cout << set << endl;
}
int main(){

    string J = "aA";
    string S = "aAAbbbb";
    
    numJewelsInStones(J, S);
    
    return 0;
}
