#include <iostream>
using namespace std; 
 int power(int m,int n){
     static int p = n;
     if(p==0){
            return 1;
     }
     else {
            p--;
            return power (m,p) * m; 
     }
 }
 int power2(int m,int n){
     if(n==0){
            return 1;
     }
     else if(n%2==0) {
            
            return power2 (m*m,n/2); 
     }
     else {
         return m*power2(m*m,(n-1)/2);
     }
 }
 int main(){
     cout<< "Enter the base: " << endl;
     int A;
     cin >> A;
     cout<< "Enter the power: " << endl;
     int B;
     cin >> B;
     cout << "Answer: " << power(A,B)<<endl;
     cout << "Answer: " << power2(A,B)<<endl;
     return 0;
 }
 