#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 5 && j == 6)
            {
                printf("i=%d, j=%d\n", i, j);
                break;
            }
        }
        if (i == 5) // Check if the outer loop should also break
        {
            break;
        }
    }
    printf("End of the program");
}
