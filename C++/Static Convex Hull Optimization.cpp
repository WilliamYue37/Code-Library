struct Sol {
	ll m;
	ll b;

	ll compute(ll x) {
		return m * x + b;
	}

	ll intersect(Sol r) {
		return (ld)(this->b - r.b)/(r.m - this->m);
	}
};

class CHT {
public: 
	Sol hull[MAX_N]; //deque
	int p1, p2; //front and back pointers, respectively 

	void insert(Sol part) {
		while (p2 - p1 >= 2 && hull[p2 - 2].intersect(hull[p2 - 1]) >= hull[p2 - 2].intersect(part)) --p2;
		hull[p2++] = part;
	}

	//static queries
	ll query(ll x) {
		while (p1 + 1 < p2 && hull[p1].compute(x) >= hull[p1 + 1].compute(x)) ++p1;
		return hull[p1].compute(x);
	}

	//dynamic queries
	/*ll query(ll x) {
		int lo = p1, hi = p2 - 2;
		if (p1 + 1 == p2) return hull[p1].compute(x);
		if (x < hull[p2 - 1].intersect(hull[p2 - 2])) return hull[p2 - 1].compute(x);
		while (hi - lo > 1) {
			int m = (lo + hi) / 2;
			if (x >= hull[m].intersect(hull[m + 1])) hi = m;
			else lo = m;
		}
		return hull[hi].compute(x);
	}*/
};
