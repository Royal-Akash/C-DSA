class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.size();
        int countA=0, countB=0;
        
        for(int i=1;i<n-1;i++){
            if(colors[i-1]=='A' && colors[i]=='A' && colors[i+1]=='A'){
                countA++;
            }
            else if(colors[i-1]=='B' && colors[i]=='B' && colors[i+1]=='B'){
                countB++;
                
            }
        }
        return countA>countB;
    }
};