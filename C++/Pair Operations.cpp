pair<int, int> operator+(const pair<int, int>& l, const pair<int, int>& r) {
	return {l.first + r.first, l.second + r.second};
}

pair<int, int> operator+=(pair<int, int>& l, const pi& r) {
	return l = l + r;
}
