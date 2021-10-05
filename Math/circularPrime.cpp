/*    problrm statement
print total number circular primes below n;

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

 */

#include <bits/stdc++.h>

using namespace std;
int rev (int c,int n)   /*  it take a number and rotate its digit by one and return that number for eg 123 -> 231 */
{
    int arr[n];
    int cc=c;
    for(int i=0;i<n;i++)    
    {
        arr[i]=c%10;
       // cout<<arr[i]<<" ";
        c/=10;
    }
    //cout<<endl;
    int a=arr[0];
     for(int i=0;i+1<n;i++)    
    {
        arr[i]=arr[i+1];
        
    }
    arr[n-1]=a;


    int p=0;
    int kx=0;
     for(int i=0;i<n;i++)    
    {
        int pp=ceil(arr[i]*pow(10,p));
       // cout<<pp<<" ";
        kx+= pp;
      //  cout<<kx<<endl;
        p++;
       
    }
    
    return kx;
    
}
/* Driver code */
int main()
{
  int n=1000000;

    /* take input from user */
    int nn=n;
    n*=10;
    vector<int> arr;
  arr.push_back(0);
   unordered_map<int, int> map;
  for(int i=1;i<=n;i++)   /*  fill the array from 1 to n */
  {
      arr.push_back(i);
  }
   for(int i=2;i<=n;i++)   /* sieve code that mark all non prime number as 1  and store all prime numbers in a hash map*/
  {
      
      if(arr[i]!=1)
      {
           map.insert(make_pair(arr[i],1));
          for(int j=i+i;j<=n;j+=i)
          {
              arr[j]=1;
          }
      }
     
  }

 int count=0;
   for(int i=1;i<=nn;i++)
  {
     if(arr[i]!=1)     /* if the number is prime*/
     {
       
         int flag2=0;
         int c=arr[i];
         int k=0;
          while(c)      /* number of digits in that number =k*/
          {
              k++;
              c/=10;
          }
          
          int kk=k;
          c=arr[i];
          int cc=c;
          if(k>1)
          {int arr1[kk-1];
          int p=0;
          while(k>1)
          {
             c= rev(c,kk);    /* function that rotate the digits of number by 1*/
      
             
             if (map.find(c) == map.end())   /* if the new number is not a prime number then it is not a circular prime*/
             {
                 
                 flag2=1;
                 break;
             }
            
             k--;
          }
          
          }
          if(flag2==0)     /* if all its rotations are prime then count++ that number */
          {
            count++;
        
          }
         
         
          
       }
       
        
  }
  cout<<count;
   return 0;
}
