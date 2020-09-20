#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pi;

int main() {
	ifstream file1("");
	ifstream file2("");
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int line = 1;
	string s;
	while (file1 >> s) {
		string s2; file2 >> s2;
		if (s != s2) cout << line << '\n';
		++line;
	}

	return 0;
}
