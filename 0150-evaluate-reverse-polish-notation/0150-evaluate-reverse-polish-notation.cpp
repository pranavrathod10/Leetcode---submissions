class Solution {
public:
    int func(int x,int y, string op){
        if(op == "+"){
            return x+y; 
        }
        if(op == "-"){
            return y-x; 
        }
        if(op == "*"){
            return y*x; 
        }
    
        return y/x;
        

    }
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        int n = tokens.size();
        stack<string> st;
        for(string t: tokens){
            st.push(t);
            if(st.top() == "+" || st.top() =="-" || st.top() =="*" || st.top() =="/"){
                string op = st.top();st.pop();
                int x = stoi(st.top());st.pop();
                int y = stoi(st.top());st.pop();
                string temp = to_string(func(x,y, op));
                st.push(temp);
            }
        }

        return stoi(st.top());

    }
};