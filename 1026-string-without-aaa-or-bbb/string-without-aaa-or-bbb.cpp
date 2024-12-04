class Solution {
public:
    string strWithout3a3b(int a, int b) {
       string ans="";  
        int counta=0,countb=0; 
        int total=a+b;
        for(int i=0;i<total;i++)
        {
            if((b>=a && countb<2) || (counta==2 && b>0)) 
            {
                ans+='b';
                b--;    
                countb++; 
                counta=0; 
            }
            else if((a>=b && counta<2) || (countb==2 && a>0))
            {
                ans+='a';
                a--;
                counta++;
                countb=0;
            }
        }
        return ans; 
    }
};