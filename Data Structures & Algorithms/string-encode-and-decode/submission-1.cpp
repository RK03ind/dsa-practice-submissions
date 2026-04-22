class Solution {
   public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& str : strs) {
            result += to_string(str.size()) + '#' + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int count = 0;
        string str;
        bool flag = true;

        for (char c : s) {
            if (flag) {
                if (c == '#') {
                    count = stoi(str);
                    str = "";
                    flag = false;
                } else {
                    str += c;
                }
            } else {
                // if length is 0 → immediately finish, do NOT consume char
                if (count == 0) {
                    result.push_back(str);
                    str = "";
                    flag = true;

                    // IMPORTANT: re-process this same character
                    // because it belongs to next number
                    if (c == '#') {
                        count = stoi(str);
                        str = "";
                        flag = false;
                    } else {
                        str += c;
                    }
                } else {
                    str += c;
                    count--;
                }
            }
        }

        // edge case: last string
        if (!flag) {
            result.push_back(str);
        }

        return result;
    }
};
