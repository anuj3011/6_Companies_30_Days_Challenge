string colName (long long int n)
    {
    	string res = "";
        int temp;
    	while (n){
    	    n--;
    		temp = n % 26;
    		res += ('A' + temp);
    		n /= 26;
    	}
    	reverse (res.begin (), res.end ());
    	return res;
    }