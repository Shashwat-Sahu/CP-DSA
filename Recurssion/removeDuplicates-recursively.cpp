void removeConsecutiveDuplicates(char *input) {
	if(input[0]=='\0')
        return;
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1])
    
    {
        int i=2;
        for(;input[i]!='\0';i++)
        {
            input[i-1]=input[i];
        }
        input[i-1]=input[i];
        return;
    }
	return;
}
#include <iostream>
using namespace std;

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}