int* spirallyTraverse(int r, int c, int matrix[][c])
{   
    int row = 0;
    int col = 0;
    int *output = malloc(sizeof(int) * (r * c));
    int pos = 0;
        
    while(row<r && col<c){
       for(int i=col; i<c; i++)
           output[pos++] = matrix[row][i];
       row++;
       for(int i=row; i<r; i++)
           output[pos++] = matrix[i][c-1];
       c--;
        if(row<r)
        {
            for(int i=c-1; i>=col; --i)
                output[pos++] = matrix[r-1][i];
            r--;
        }
        if(col<c)
        {
            for(int i=r-1; i>=row; --i)
                output[pos++] = matrix[i][col];
            col++;    
        }   
       
    }
    return output;
}