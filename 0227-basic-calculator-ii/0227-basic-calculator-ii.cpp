class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        stack<int> st;
        int currentNumber = 0;
        char operation = '+';
        
        for(int i = 0; i < n; i++) {
            
            char currentChar = s[i];
            if(isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            
            if(!isdigit(currentChar) && !iswspace(currentChar)  || i == n - 1) {
                if(operation == '-') {
                    st.push(-currentNumber);
                }
                else if(operation == '+') {
                    st.push(currentNumber);
                } else if(operation == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currentNumber);
                } else if(operation == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};