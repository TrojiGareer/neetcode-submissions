class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int e1 = st.top();
                st.pop();
                int e2 = st.top();
                st.pop();
                int rez = 0;
                if (tokens[i] == "+") {
                    rez = e1 + e2;
                }
                if (tokens[i] == "-") {
                    rez = e2 - e1;
                }
                if (tokens[i] == "*") {
                    rez = e2 * e1;
                }
                if (tokens[i] == "/") {
                    rez = e2 / e1;
                }
                st.push(rez);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
