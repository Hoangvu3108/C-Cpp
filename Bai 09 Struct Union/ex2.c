#include<stdio.h>
#include<stdint.h>
union Data {
    uint8_t a;
    uint16_t b;
    uint32_t c;   
};
int main()
{
    printf("Size of Union Data: %zu bytes \n",sizeof(union Data) );
    return 0;
}