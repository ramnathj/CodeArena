/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long int Lint;

int main()
{
    Lint n, i, j, sum, maxSum, val;
    
    scanf("%lld", &n );
    Lint* A = new Lint[ n ];
    for( i = 0;i < n;i++ ) {
        scanf("%lld", &A[ i ] );
    }
    
    maxSum = 0;
    for( i = 1;i <= n;i++ ) {
        for( j = i + 1;j <= n;j++ ) {
            val = min( j - i, n - j + i );
            sum = A[ i - 1 ] + A[ j - 1 ] + val;
            maxSum = max( maxSum, sum );
        }
    }
    
    printf("%lld\n", maxSum );
    delete A;
}
