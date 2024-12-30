#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void displayBits(unsigned www)
{
    unsigned c; /* counter */

    /* declare displayMask and left shift 31 bits */
    unsigned displayMask = 1 << 31;

    printf("%7u = ", www);

    /* loop through bits */
    for (c = 1; c <= 32; c++) {
        putchar(www & displayMask ? '1' : '0');
        www <<= 1; /* shift value left by 1 */

        if (c % 8 == 0) { /* output a space after 8 bits */
            putchar(' ');
        } /* end if */

    } /* end for */

    putchar('\n');
} /* end function displayBits */

int hammingDistance(unsigned int a, unsigned int b)
{
    unsigned int x = 1;
    int sum = 0;
    unsigned int xorResult = a ^ b;
    while (xorResult)
    {
        if ((xorResult & x) == 1) {
            sum++;
            
        }
        xorResult = xorResult >> 1;
    }
    return sum;
}

unsigned int invertbit(unsigned int value)
{
    unsigned int y = ~0;
    unsigned int x = value^y;
    return x;
}

unsigned int swapbits(unsigned int value, int index1, int index2) 
{
    int mask1 = 1<<index1, mask2 = 1<<index2, mask=(mask1|mask2);
    return value ^ mask;
} 
unsigned int manipulatebits(unsigned int value, int index1, int index2, int index3) 
{
    unsigned int val,x = 1;
    val = value | (x << index1);
    val = val & (~(x << index2));
    val = val ^ (x << index3);
    return val;
}

int main()
{

    unsigned int value;
    printf("Enter number for EX.1\n");
    scanf("%d", &value);
    printf("Invertbit is: %d\n", invertbit(value));
    displayBits(invertbit(value));


    unsigned int a, b;
    printf("Enter 2 numbers for EX.2\n Enter first number:\n");
    scanf("%d", &a);
    printf("Enter second number:\n");
    scanf("%d", &b);
    printf("Hamming Distance: %d\n", hammingDistance(a, b));
    displayBits(hammingDistance(a, b));

    
    int index1, index2;
    printf("Enter one value and 2 index you whant to swich for EX.3\n ");
    scanf("%d", &value);
    scanf("%d", &index1);
    scanf("%d", &index2);
    printf("The swapbits is: %d\n", swapbits(value, index1, index2));
    displayBits(swapbits(value, index1, index2));
    int index3;
    printf("Enter one value and 3 index.\n First: Turn on bit-\n Second:Turnoff bit-\n Third: Toggle the bit- for EX.3\n ");
    scanf("%d", &value);
    scanf("%d", &index1);
    scanf("%d", &index2);
    scanf("%d", &index3);
    printf("The manipulatebits is: %d\n", manipulatebits(value, index1, index2, index3));
    displayBits(manipulatebits(value, index1, index2, index3));
    return 0;
}