class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool positive = s[i]=='+';
        bool negative = s[i]=='-';
        if(positive || negative) i++;
        double num=0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            num=num*10+(s[i]-'0');
            i++;
        }
        if(negative==true) num=-num;
        if(num>INT_MAX) num=INT_MAX;
        if(num<INT_MIN) num=INT_MIN;
        
        return (int)num;
    }
};