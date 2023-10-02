class Solution {
public:
    bool winnerOfGame(string c) {
        int cA=0;
        int cB=0;
        for(int i=1;i<c.length()-1;i++)
        {
            if(c[i]=='A' and c[i-1]=='A' and c[i+1]=='A')
            {
                cA+=1;
               // c.erase(i,1);
            }
            if(c[i]=='B' and c[i-1]=='B' and c[i+1]=='B')
            {
                cB+=1;
               // c.erase(i,1);
            }
        }
        if(cA==0) return false;
        else if(cB>=cA) return false;
        else return true;
    }
};