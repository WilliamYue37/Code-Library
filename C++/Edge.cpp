struct Edge {
	int u, v, w;
	bool operator < (const Edge &e) const {return this->w < e.w;}
};
