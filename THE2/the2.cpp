#include "the2.h"

// do not add extra libraries here
/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    size      : number of elements in the array
*/
void counting_sort(std::string*& arr, int size, int digit, int k, int& c, bool ascending) {
    int* count = new int[k];
    std::string* result = new std::string[size];
    for(int i = 0; i < k; i++) count[i] = 0;
    for(int j = 0; j < size; j++){
        c++;
        if (digit  >= arr[j].size()) {
            count[0] += 1;
            
        }
        else{
            if(ascending){
                count[arr[j][digit] - 'A' + 1] +=1;
            }
            else{
                count['Z' - arr[j][digit] + 1] += 1;
            }
            
        }
    }
    for(int i = 1; i < k; i++){
        c++;
        count[i] = count[i] + count[i-1];
    }
    for(int j = size-1; j >= 0; j--){
        c++;
        if (arr[j].size() <= digit) {
            result[count[0] - 1] = arr[j];
            count[0] -= 1;
        }
        else{
            if(ascending){
                result[count[arr[j][digit] - 'A' + 1] - 1] = arr[j];
                count[arr[j][digit] - 'A' + 1] -= 1;
            }
            else{
                result[count['Z' - arr[j][digit] + 1] - 1] = arr[j];
                count['Z' - arr[j][digit] + 1] -= 1;
            }
            
        }
    }
    for(int i = 0; i < size; i++){
        c++;
        arr[i] = result[i];
    }
    delete[] result;
    delete[] count;
}
int radix_string_sort(std::string* arr, int size, bool ascending){
    int k = 27;
    int max_digit = 0;
    int iteration_count = 0;
    if (arr == nullptr || size <= 0) {
        return 0; // Nothing to sort
    }
    for(int i = 0; i < size; i++){
        if(max_digit < arr[i].length()){
            max_digit = arr[i].length();   
        }   
    }
    for(int i = max_digit - 1; i >= 0; i--){
        counting_sort(arr,size,i,k,iteration_count,ascending);
    }
    
    return iteration_count;
}
    

