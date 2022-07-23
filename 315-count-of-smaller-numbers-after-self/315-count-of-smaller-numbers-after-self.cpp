class Solution {
public:
  
    void merge(vector<int>&count, vector<pair<int, int>>&v, int l, int mid, int r){
        int n1=mid-l+1;
        int n2=r-mid;
        
        vector<pair<int, int>>a(n1);
        vector<pair<int, int>>b(n2);
        
        for(int i=0; i<n1; i++){
            a[i]=v[l+i];
        }
        
        for(int j=0; j<n2; j++){
            b[j]=v[mid+1+j];
        }
        
        int i=0; 
        int j=0;
        int k=l;
        
         while(i<n1 && j<n2){ 
             if(a[i].first>b[j].first){
                 count[a[i].second]+=n2-j; //because it' in desc so all element of n2 will be less than ith element of n1
                 v[k]=a[i];
                 i++;
                 k++;
                 
             }else{
                 v[k]=b[j];
                 j++;
                 k++;
             }
         }
        
        while(i<n1){
            v[k]=a[i];
            i++;
            k++;
        }
        
        while(j<n2){
            v[k]=b[j];
            j++;
            k++;
        }
    }
    
    void mergesort(vector<int>&count, vector<pair<int, int>>&v, int l, int r){
         if(l<r){
             int mid=l-(l-r)/2;
             
             mergesort(count, v, l, mid);
             mergesort(count, v, mid+1, r);
             
             merge(count, v, l, mid, r);
         }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>>v(n);
        
        for(int i=0; i<n; i++){
            v[i].first=nums[i];
            v[i].second=i;
        }
        vector<int>count(n,0);
        
        mergesort(count, v, 0, n-1);
        
        return count;
    }
};