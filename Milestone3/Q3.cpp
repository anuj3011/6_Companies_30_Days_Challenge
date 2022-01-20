void rotate(int n,int a[][n])
{
    for (int i = 0; i < n/2; ++i)
    {
        for(int j=i; j<n-i-1; j++)
        {
            // swap in anti-clockwise direction
            int temp = a[i][j];
            a[i][j] = a[j][n-1-i];        // right to top
            a[j][n-1-i] = a[n-1-i][n-1-j];// bottom to right
            a[n-1-i][n-1-j] = a[n-1-j][i];// left to bottom
            a[n-1-j][i] = temp;                // top to left
        }
    }
}