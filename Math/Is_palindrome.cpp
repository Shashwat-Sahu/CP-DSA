//C++ program for palindrome numbers
#include<iostream>
using namespace std;
//Function to check whether a number is palindrome or not
int is_palindrome(int num)
{
   int  reverse = 0, remainder, temp;
   temp = num; 

   while( temp != 0)
   {
      remainder = temp % 10;
      reverse = reverse * 10 + remainder;
      temp = temp / 10;
   }

   if (num == reverse) 
      return true;
   else
      return false;
   return 0;
}
//Driver code
int main()
{
    int num = 1122332211;
    if (is_palindrome(num) == true)
        cout << "Yes,the number is Palindrome!";
    else
        cout << "No,the number is not Palindrome!";
    return 0;
}