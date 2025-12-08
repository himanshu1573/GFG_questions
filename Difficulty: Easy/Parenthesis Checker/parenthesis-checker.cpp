class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        map<char,char>mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(!st.empty()){
              char t=st.top(); 
              if(mp[t]==x){
                st.pop();
                continue;
            }
            }
             st.push(x);
        }
         return st.empty();
        
    }
};