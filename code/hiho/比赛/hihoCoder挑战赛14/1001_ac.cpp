#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)

using namespace std;
#define  N   123456


int c[N], kind[N];
int n;


int main() {
	cin >> n;
    int mx = 1100, mn = -10;

    REP(i, n) {
    	string s;
    	cin >> s;
    	cin >> s;
    	cin >> c[i];

    	if (s == "<")
    		kind[i] = 0;
    	else if (s == "<=")
    		kind[i] = 1;
    	else if (s == "=")
    		kind[i] = 2;
    	else if (s == ">")
    		kind[i] = 3;
    	else
    		kind[i] = 4;
    	mx = max(mx, c[i] + 10);
    	mn = min(mn, c[i] - 10);
    }

    int ans = 0;
    for (double x = mn; x <= mx; x += 0.5) {
    	int tmp = 0;
    	REP(i, n) {
    		if (kind[i] == 0 && x < c[i])
    			tmp++;

    		if (kind[i] == 1 && x <= c[i])
    			tmp++;

    		if (kind[i] == 2 && x == c[i])
    			tmp++;

    		if (kind[i] == 3 && x > c[i])
    			tmp++;

    		if (kind[i] == 4 && x >= c[i])
    			tmp++;
    	}
    	ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}

