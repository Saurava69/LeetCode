class StockSpanner {
public:
    vector<int>stock;
    stack<int>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        int ans=1;
        for(int i=stock.size()-2;i>=0;i--){
            if(stock[i]<=price) ans++;
            else break;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */