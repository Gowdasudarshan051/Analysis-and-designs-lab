#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main()
{
    int a = 161;
    int b = 28;

    int result = gcd(a, b);
    printf("%d", result);

    return 0;
}
