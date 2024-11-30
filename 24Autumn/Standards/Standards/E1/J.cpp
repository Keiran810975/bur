#include <bits/stdc++.h>

using namespace std;

int t, p, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> p >> q;
        
        if (q == 1) {
        	q = p + 1;
        	p = 1;
		} else {
			int r = p / q;
	        p %= q;
	        q -= p;
	        p += q;
	        q += r * p;
		}
        
        cout << p << " " << q << "\n";
    }
    return 0;
}
