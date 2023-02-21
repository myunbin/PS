#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007;
const ll LMOD = 987654321; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1010101;
const int MAXR = 2e5 + 10;


int main() {
	fio();
	vector<bool> p(MAXN, 1);
	ll n; cin >> n;
	ll ans = 1;
	for (ll i = 2; i <= n; i++) {
		if (!p[i]) continue;
		ll t = i;
		while (t <= n) {
			ans *= i;
			ans %= LMOD;
			t *= i;	
		}
		for (ll j = i*i; j <= n; j += i) p[j] = 0;
	}
	
	cout << ans%LMOD << endl;
	return 0;
}
