bool check(vector<int> &degree) {
    sort(degree.begin(), degree.end(), greater<int>());
    vector<int> freq(MAXNUM + 1); //MAXNUM is the largest degree value
    long long sum = 0;
    for (int i = 0; i < degree.size(); ++i) {
		++freq[degree[i]];
		sum += degree[i];
    }
    long long left = 0, right = 0; int less = 0;
    for (int k = 1, i = 0; k <= degree.size() && i < degree.size(); ++k, ++i) {
        left += degree[i];
        --freq[degree[i]];
        right -= min(degree[i], k - 1);
        if (degree[i] < k - 1) --less;
        less += freq[k - 1];
        right += degree.size() - k - less;
        if (left > (long long)k * (k - 1) + right) return false;
    }
    return true;
}
