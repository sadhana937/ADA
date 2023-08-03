#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n)
{
    int r, count = 0;
    while (n)
    {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    return count;
}

int consecInt(int m, int n)
{
    int min = m, count = 0;
    if (n < min)
        min = n;
    while (1)
    {
        count++;
        if (m % min == 0)
        {
            count++;
            if (n % min == 0)
                break;
        }
        min -= 1;
    }
    return count;
}

int modifiedEuclid(int m, int n)
{
    int temp, count = 0;
    while (n > 0)
    {
        if (n > m)
        {
            temp = m;
            m = n;
            n = temp;
        }
        m = m - n;
        count++;
    }
    return count;
}

void analysis(int ch)
{
    int m, n, i, j, k;
    FILE *fpe, *fpci, *fpme;
    fpe = fopen("gcde.txt", "a");
    fpci = fopen("gcdci.txt", "a");
    fpme = fopen("gcdme.txt", "a");

    int count, maxcount = 0, mincount = 0;
    for (i = 10; i <= 100; i += 10)
    {

        maxcount = 0, mincount = 999999;
        for (j = 2; j <= i; j++)
        {
            for (k = 2; k <= i; k++)
            {
                count = 0, m = j, n = k;
                switch (ch)
                {
                case 1:
                    count = euclid(m, n);
                    break;
                case 2:
                    count = consecInt(m, n);
                    break;
                case 3:
                    count = modifiedEuclid(m, n);
                    break;
                }
                if (count > maxcount)
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }
        switch (ch)
        {
        case 1:
            fprintf(fpe, "%d\t%d\t%d\n", i, mincount, maxcount);
            break;
        case 2:
            fprintf(fpci, "%d\t%d\t%d\n", i, mincount, maxcount);
            break;
        case 3:
            fprintf(fpme, "%d\t%d\t%d\n", i, mincount, maxcount);
            break;
        }
    }
    fclose(fpe);
    fclose(fpci);
    fclose(fpme);
}

void main()
{
    for (int ch = 1; ch <= 3; ch++)
            analysis(ch);
}
