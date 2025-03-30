#include <stdio.h>
#include <assert.h>

double thuong(int a, int b) {
    assert( b != 0 && "Mau bang 0");
    return (double) a/b;
}

int main() {
    printf("Thuong: %f\n", thuong(6, 0)); 
    return 0;
}