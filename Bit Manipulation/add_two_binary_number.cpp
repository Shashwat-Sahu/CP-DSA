#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int add_binary(int a,int b){
    int pre_carry=0,i=1,ans=0;
    while ((a!=0 && b!=0) || pre_carry==1 )
    {
       int x=a%10;
       int y=b%10;
       if (x+y+pre_carry==3)
       {
           pre_carry=1;
            ans+=1*i;
       }
       
        else if (x+y+pre_carry==2)
        {
            pre_carry=1;
            ans+=0*i;
        }
        else if(x+y+pre_carry==1){
            pre_carry=0;
            ans+=1*i;
        }
        else{
            pre_carry=0;
            ans+=0*i;
        }
        i*=10;
       a=a/10;
       b=b/10; 
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<add_binary(a,b);
 return 0;
}
//  1 1 0 1 0   =        26
//  1 1 1 0 0   =        28
//1 1 0 1 1 0   =        54
