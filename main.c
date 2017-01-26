#include <stdio.h>
#include <stdlib.h>

float absv(float r, float i, int n);

char chr(float r, float i, int n);

int main(void)
{
    FILE *fp = fopen("mset.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }
    for (float im = -1; im <= 1; im += .06250)
    {
        for (float re = -2; re <= 1; re += .03125)
        {
            if (absv(re, im, 1) < 2)
            {
                fprintf(fp, "%c", chr(re, im, 1));
            }
            else
            {
                fprintf(fp, "%c", 126);
            }
        }
        fprintf(fp, "\n");
    }
    system("PAUSE");
    return 0;
}

// absolute value of the nth complex number
float absv(float re, float im, int n)
{
    float zr = re, zi = im;
    for (int i = 0; i < n; i++)
    {
        float nzr = zr * zr - zi * zi;
        zi = zr * zi * 2;
        zr = nzr;
        zr += re;
        zi += im;
    }
    return sqrt(zi * zi + zr * zr);
}

// decide which char to print
char chr(float re, float im, int n)
{
    if (n < 256)
    {
        if (absv(re, im, n+1) < 4)
        {
            return chr(re, im, n+1);
        }
        else
        {
            return 126 - n;
        }
    }
    else
    {
        return 32;
    }
}
