class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
         int countF=0;
        int countT=0;
        int i=0;
        int j=0;
        int ans=0;
        while(j<answerKey.size()){
          if(answerKey[j]=='F'){
            countF++;
          }
          else{
            countT++;
          }
          while(min(countF, countT)>k){
            if(answerKey[i]=='F'){
              countF--;
            }
            else{
              countT--;
            }
            i++;
          }
          ans=max(ans, countT+countF);
          j++;
        }
       return ans; 
    }
};