struct SuffixTree {
	string s; 
	int node, pos;

	struct state { // edge to state is s[fpos, fpos + len)
		int fpos, len, link = -1; map<char, int> to;
		state(int fpos, int len) : fpos(fpos), len(len) {}
	}; vector<state> st;

	int makeNode(int pos, int len) { 
		st.push_back(state(pos, len));
		return sz(st) - 1; 
	}

	void travEdge() {
		while (pos > 1 && pos > st[st[node].to[s[sz(s) - pos]]].len) {
			node = st[node].to[s[sz(s) - pos]];
			pos -= st[node].len;
		}
	}

	void extend(char c) {
		s += c; ++pos; int last = 0;
		while (pos) {
			travEdge();
			char edge = s[sz(s) - pos];
			int& v = st[node].to[edge];
			char t = s[st[v].fpos + pos - 1];
			if (v == 0) {
				v = makeNode(sz(s) - pos, INF);
				st[last].link = node; last = 0;
			}
			else if (t == c) {
				st[last].link = node;
				return;
			} 
			else {
				int u = makeNode(st[v].fpos, pos - 1);
				st[u].to[c] = makeNode(sz(s) - 1, INF);
				st[u].to[t] = v;
				st[v].fpos += pos - 1; st[v].len -= pos - 1;
				v = u; st[last].link = u; last = u;
			}
			if (node == 0) --pos;
			else node = st[node].link;
		}
	}

	void init(string str) {
		makeNode(-1, 0); node = pos = 0;
		for (char c: str) extend(c);
		extend('\$'); s.pop_back(); // terminal char
	}

	int maxPre(string x) { // max prefix of x which is substring
		int node = 0, ind = 0;
		while (true) {
			if (ind == sz(x) || !st[node].to.count(x[ind])) return ind;
			node = st[node].to[x[ind]];
			for (int i = 0; i < st[node].len; ++i) {
				if (ind == sz(x) || x[ind] != s[st[node].fpos + i]) return ind;
				++ind;
			}
		}
	}

	vector<int> sa; // generate suffix array
	void genSa(int x = 0, int len = 0) {
		if (!sz(st[x].to)) { // terminal node
			sa.push_back(st[x].fpos - len);
			if (sa.back() >= sz(s)) sa.pop_back();
		} else {
			len += st[x].len;
			for (auto& p: st[x].to) genSa(p.ss, len);
		}
	}
};
