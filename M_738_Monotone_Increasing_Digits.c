#include <stdio.h>
int monotoneIncreasingDigits(int N) {
    int bit[10] = {-1};
    int res = 0;
    bit[0] = 0;
    int j = 0;
    while(N) {
        bit[j++] = N%10;
        N/=10;
    }
    --j;
    int i = 0;
    while(i < j) {
        if(bit[i] >= bit[i+1]) {
            i++;
        }
        else {
            bit[i+1] -= 1;
            int temp = i;
            while(temp >= 0) {
                bit[temp] = 9;
                temp--;
            }
        }
    }
    for(int c = 0; c <= j; c++)
        res = res * 10 + bit[j-c];
    return res;
}
int main() {
    printf("%d\n", monotoneIncreasingDigits(322));
    printf("%d\n", monotoneIncreasingDigits(1234));
    printf("%d\n", monotoneIncreasingDigits(20));
    return 0;
}
