  string nextPalin(string N) { 
        int n=N.length();
        int mid=(n/2)-1;
        int pos=-1;
        
        for(int i=mid;i>=1;i--){
            if(N[i-1]<N[i]){
                pos=i-1;
                break;
            }
        }
        if(pos==-1){
            return "-1";
        }
        
        int numPos=-1;
        for(int i=pos+1;i<=mid;i++){
            if(N[i]>N[pos]){
               
               if(numPos==-1){
                   numPos=i;
               }
               else{
                   if(N[i]<N[numPos]){
                       numPos=i;
                   }
               }
               
            }
        }
    
        swap(N[pos],N[numPos]);
        sort(N.begin()+pos+1,N.begin()+mid+1);
        int i=0;
        int j=n-1;
        while(i<=mid){
            N[j]=N[i];
            i++;
            j--;
        }
        return N;
    }