#include<iostream>  
#include<string.h> 
using namespace std;  
  
//  function to sort the given char array[] in alphabetical order  
void count_sort(char* array)  
{    
    char output[strlen(array)];  
  
    //An arrayay to store count of inidividul characters and initialize count arrayay as 0  
    int count[255 + 1];  
    memset(count, 0, sizeof(count));  
  
    // Store count of each character  
    for(int i = 0; array[i]; i++)  
        ++count[array[i]];  
  
    // update count[i] so that count[i] now contains actual position of this character in output arrayay  
    for (int i = 1; i <= 255; i++)  
        count[i] += count[i-1];  
  
    // Build the output character arrayay  
    for (int i = 0; array[i]; i++)  
    {  
        output[count[array[i]]-1] = array[i];  
        --count[array[i]];  
    }  
     
    // Copy the output arrayay to array to have sorted characters  
    for (int i = 0; array[i]; i++)  
        array[i] = output[i];  
}  
  
int main()  
{  
    char array[] = "countsortalgorithm"; 
    //calling the count_sort function inside main function

    count_sort(array);

    //output the sorted arrayay
    cout<< "Sorted character arrayay is:" << array <<endl;  

    return 0;  
}  