class Solution {
    int findPeak(MountainArray& mountainArr){
        int lo = 0, hi = mountainArr.length(),m;
        MountainArray &v = mountainArr;
        while(lo<=hi){
            m = (lo + hi)/2;

            if(m+1 > v.length()-1 || m-1 < 0){
                    if(m+1>v.length()-1)
                        hi--;
                    if(m-1<0)
                        lo++;
                    continue;
                }
            int m1 = mountainArr.get(m-1), m2 = mountainArr.get(m) ,m3 = mountainArr.get(m+1);
            
            if(m1 < m2 and m2 > m3){
                break;
            }else if(m1<m2 and m2<m3){
                lo = m+1;
            }else{
                hi = m-1;
            }
        }
        
        return m;
    }
    
    int bSearch(MountainArray &mA, int target, int lo, int hi,bool (*compare)(int , int)){
        int m;
        while(lo<=hi){
            m = (lo + hi)/2;
            if(mA.get(m) == target){
                return m;
            }else if(compare(mA.get(m),target)){
                lo = m + 1;
            }else{
                hi = m - 1; 
            }
        }
        
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);

        cout<<mountainArr.get(peak)<<endl;
        int idx1 = bSearch(mountainArr,target,0,peak,[](int a,int b)->bool{
            return a < b;
        });
        int idx2 = bSearch(mountainArr,target,peak,mountainArr.length()-1,[](int a,int b)->bool{
            return a > b;
        });
        cout<<idx1<<" "<<idx2<<endl;
        if(idx1!=-1)
            return idx1;
        else if(idx2!=-1) return idx2;
        else return -1;
    }
};