# include <bits/stdc++.h>
using namespace std;
 
// Function checks if passed strings are rotation of each other.
bool areRotations(string str1, string str2)
{
   // Check if sizes of two strings are same.
   if (str1.length() != str2.length())
        return false;
 
   string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}
 
// Driver Code
int main()
{
   string str1 = "AACD", str2 = "ACDA";
   if (areRotations(str1, str2))
     printf("Strings are rotations of each other");
   else
      printf("Strings are not rotations of each other");
   return 0;
}
