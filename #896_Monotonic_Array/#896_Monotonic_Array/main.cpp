/*
 An array is monotonic if it is either monotone increasing or monotone decreasing.
 An array A is monotone increasing if for all i <= j, A[i] <= A[j].
 An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 Return true of and only if the given array A is monotonic.
 
 */

#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int> &A){
    
    auto size = A.size();
    for (int i = 0; i < size; i++) {
        if (A[i] >= A[i+1])
            return false;
    }
    return true;
};

int main() {
    
    
    std::vector<int> vec ={2,4,7,8,8,13};
    
    if (isMonotonic(vec))
        std::cout<<"Is monotonic\n";
    else
        std::cout<<"Is not monotonic\n";

    
    
    return 0;
}
