
#include<stdio.h>

long long int floorSqrt(long long int x) 
{
    long long int ans=1;
    while(ans*ans<=x)
    {
        ans++;
    }
    return ans-1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}