void calculateSpan(int price[], int n, int S[])
{
    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        S[i] = 1;
        for (int j = i - 1; (j >= 0) &&
        (price[i] >= price[j]); j--)
        S[i]++;
    }
}


