class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        
        stack<char> k;
        for(int i=0;i<n;i++){
            //closing brackets at front of the string
            if((s[i]==')' || s[i]==']' || s[i]=='}') && k.empty())
                return false;
            
            //pushing the open brackets into stack
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                k.push(s[i]);
            //popping the respective open bracket for the closing bracket i.e brackets are matched 
            else if((k.top()=='(' && s[i]==')') || (k.top()=='[' && s[i]==']') || (k.top()=='{' && s[i]=='}'))
                k.pop();
            //non-matching pairs of brackets
            else
                return false;
        }
        
        //all the barckets are balanced
        if(k.empty())
            return true;
        return false;
    }
};