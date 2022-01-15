const char hashTable[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

void printWordsUtil(int number[],int curr_digit,string output,int n,vector <string> &res) 
{
    int i; 
    if (curr_digit == n) 
    { 
        res.push_back(output);
        return ; 
    } 
    
    for (i=0; i<strlen(hashTable[number[curr_digit]]); i++) 
    { 
        output.push_back(hashTable[number[curr_digit]][i]); 
        printWordsUtil(number, curr_digit+1, output, n, res); 
        if (number[curr_digit] == 0 || number[curr_digit] == 1) 
            return; 
        output.pop_back();
    } 
} 

vector<string> possibleWords(int a[], int N)
{
    vector <string> res;
    string result;
    printWordsUtil(a, 0, result, N, res);
    
    return res;
}
