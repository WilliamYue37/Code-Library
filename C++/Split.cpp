vector<string> split(string s, string delimiter) {
    vector<string> ret;
    auto start = 0;
    auto end = s.find(delimiter);
    while (end != string::npos) {
        ret.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    ret.push_back(s.substr(start, end));
    return ret;
}
