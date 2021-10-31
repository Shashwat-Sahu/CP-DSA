#include <iostream>
#include<string.h>
using namespace std;



int main() 
{
	
long test [1000001];
long count [1000001];
bool prime[1000001];
memset(prime, true, sizeof(prime));
long p=2;
long i=p*p;

    for (p = 2; p * p <= 1000001; p++)
    {
        
        if (prime[p] == true) 
        {
            
            for (i = p * p; i < 1000001; i += p)
                prime[i] = false;
        }
    }
 
    for (p = 2; p < 1000001; p++)
        if (prime[p])
            {
               test[p]=1; 
            }


for(long j=2;j<1000001;j++)
{
    count[j]=test[j]+count[j-1];
}



long t;
	scanf("%ld", &t);
	while(t--)
	{
	    long x,y;
	    long test[2];
	    for(long i=0;i<2;i++)
	    {
	        scanf("%ld",&test[i]);
	    }
	    x=test[0];
	    y=test[1];
	    
	    if(y==1)
	    {
	        if(x>=3)
	        {
	            printf("Divyam\n");
	        }
	        else
	        {
	            printf("Chef\n");
	        }
	    }
	    else
	    {
	        
	        if(count[x]<=y)
	        {
	            printf("Chef\n");
	        }
	        else
	        {
	            printf("Divyam\n");
	        }
	    }
	    
	}

	return 0;
}
