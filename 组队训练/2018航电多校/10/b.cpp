#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

ll n, m;

void solve() {
	cin >> n >> m;
	int ans = 0;
	rep(i, 1, n+1) ans = add(ans, kpow(m, __gcd((ll)i, n)));
	if(n & 1) {
		int res = kpow(m, (n + 1) / 2);
		ans = add(ans, mul(res, n));
		ans = mul(ans, kpow(2 * n, P - 2));
	} else {
		int r1 = kpow(m, n>>1);
		int r2 = kpow(m, n/2+2);
		int res = add(r1, r2);
		ans = add(ans, mul(res, n));
		ans = mul(ans, kpow(3 * n, P - 2));
	}
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
