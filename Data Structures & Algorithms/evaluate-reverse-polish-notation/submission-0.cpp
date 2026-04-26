class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string &i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                if (i == "+") st.push(second + first);
                else if (i == "-") st.push(second - first);
                else if (i == "*") st.push(second * first);
                else if (i == "/") st.push(second / first);
            } else {
                st.push(stoi(i));
            }
        }

        return st.top();
    }
};