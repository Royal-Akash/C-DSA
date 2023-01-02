class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int count=0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                count++;
            }
        }
        
        if(count==1 && isupper(word[0])) return true;
        else if(count==word.size() || count==0) return true;
        else return false;
        
    }
};

// cout<<'g'-'A'<<endl;
        // for(int i=0;i<word.size();i++){
        //     int count = word[i]-'A';
        //     if(count>=0 && count<26){
        //         continue;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;