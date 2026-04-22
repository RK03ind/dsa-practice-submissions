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
    string str;
    int count = 0;
    bool reading_count = true;

    for (char c : s) {
        if (!reading_count && count == 0) {
            result.push_back(str);
            str = "";
            reading_count = true;
        }

        if (reading_count) {
            if (c == '#') {
                count = stoi(str);
                str = "";
                reading_count = false;
            } else {
                str += c;
            }
        } else {
            str += c;
            count--;
        }
    }

    if (!reading_count) result.push_back(str);
    return result;
}
};
