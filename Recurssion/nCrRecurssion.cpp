#include <iostream>
 int fact (int n){
     if (n==0)
         return 1;
     else{
         return fact(n-1)*n;
         }   
 }
 
 double C (int n , int r){
     double t0,t1,t2;
     t0 = fact(n);
     t1 = fact(r);
     t2 = fact(n-r);
     return t0/(t1*t2);
 }
 int main(){
     std:: cout<< "Enter n" << std::endl;
     int n;
     std:: cin >> n;
     std:: cout<< "Enter r" << std::endl;
     int r;
     std:: cin >> r;
     std:: cout<< "nCr = "<< C(n,r) << std::endl;
     
     return 0;
 }