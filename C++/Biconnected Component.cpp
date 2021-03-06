vector<int> adjList[MAXSIZE]; //adjacency list for the grid
set<int> BCCs[MAXSIZE]; //the BCCs of each node in the grid
int counter, rootChildren, counterBCC; //counter = counter for DFSLowLink, rootChildren = # of children for root node, counterBCC = id for BCCs
int pre[MAXSIZE], low[MAXSIZE], parent[MAXSIZE]; //pre, low, and parent vectors for DFSLowLink
stack<Edge*> st; //stack for edges during DFSLowLink

//DFSLowLink to find data structures
void DFSLowLink(int u) {
	pre[u] = low[u] = counter++;
	for (int i = 0; i < (int)adjList[u].size(); ++i) {
		Edge* e = &adjList[u][i]; int v = e->v;
		if (pre[v] == -1) {
			parent[v] = u;
			st.push(e);
			if (pre[u] == 0) ++rootChildren;
			DFSLowLink(v);
			if ((pre[u] == 0 && rootChildren > 1) || (pre[u] != 0 && pre[u] <= low[v])) {
				while (st.top()->u != u || st.top()->v != v) {
					Edge* e = st.top(); st.pop();
					BCCs[e->u].insert(counterBCC);
					BCCs[e->v].insert(counterBCC);						
				}
				Edge* e = st.top(); st.pop();
				BCCs[e->u].insert(counterBCC);
				BCCs[e->v].insert(counterBCC);
				++counterBCC;
			}
			low[u] = min(low[u], low[v]);
		}
		else if (parent[u] != v) {
            if (pre[v] < low[u]) {
            	low[u] = pre[v];
            	st.push(e);
            }
		}
	}
}

//check if two nodes are in the same BCC
bool sameBCC(int u, int v) {
	for (int i : BCCs[u]) {
		if (BCCs[v].count(i) == 1) return true;
	}
	return false;
}
