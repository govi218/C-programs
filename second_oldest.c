#include <stdio.h>
int main() {
    int ages[6];
    ages[0] = 14;
    ages[1] = 17;
    ages[2] = 11;
    ages[3] = 9;
    ages[4] = 16;
    ages[5] = 12;
    int oldest[2];
    oldest[0] = 0;
    oldest[1] = 0;
    for(int i = 0; i < 6; i++) {
        if(ages[i] > oldest[0]) {
            oldest[1] = oldest[0];
            oldest[0] = ages[i];
        }
    }
    printf("%d", oldest[1]);
    return 0;
}
