/*
 You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
 
 The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
 
 Example 1:
 Input: J = "aA", S = "aAAbbbb"
 Output: 3
 
 Example 2:
 Input: J = "z", S = "ZZ"
 Output: 0
 
 NOTES:
 cout_if(...);
 returns the number of occurrences of value from range that satisfies condition
 int counter = count_if (InputIterator first, InputIterator last, UnaryPredicate pred);
 
 Unary predicate
 [&](char a){
 return(c==a);
 }
 */

#include <iostream>
using namespace std;


int numJewelsInStones(string J, string S)
{
    int count = 0;
    
    for_each(J.begin(), J.end(), [&](char c){
        int counter = count_if(S.begin(), S.end(), [&](char a){
            cout << "a: " << a << ", c: " << c <<  endl; return(c == a);
        });

        count+=counter;
    });
    return count;
}

int main(){
    

    string J = "aA";
    string S = "aAAbbbb";
    cout << numJewelsInStones(J,S) << endl;
    

    

}
