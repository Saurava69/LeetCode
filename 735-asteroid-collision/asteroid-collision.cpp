class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.size()==0){
                st.push_back(arr[i]);
            }else{
                if(arr[i]<0){
                    while(st.size()>0 and (st.back()>0 and st.back()<abs(arr[i]))){
                        st.pop_back();
                    }
                    if(st.size()>0 and st.back()==abs(arr[i])){
                        st.pop_back();
                        continue;
                    }
                    if(st.size() == 0 or st.back()<0) st.push_back(arr[i]);
                    else continue;
                }else{
                    st.push_back(arr[i]);
                }
            }
        }
        return st;
    }
};