#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
//#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 10;
const int MAXR = 2e5 + 10;

int ccw(pll a, pll b, pll c) {
	ll pa = 1LL*a.f*b.s + 1LL*b.f*c.s + 1LL*c.f*a.s;
	ll pb = 1LL*a.s*b.f + 1LL*b.s*c.f + 1LL*c.s*a.f;
	if (pa == pb) return 0;
	else return pa > pb ? 1 : -1;
}

ll dist(pll a, pll b) {
	ll dx = 1LL*(a.f-b.f), dy = 1LL*(a.s-b.s);
	return dx*dx + dy*dy;
	// can calculate sqrt here
}

double ans=1e12;

void rotating_calipus(vector<pll> &pt) {
	sort(all(pt));
	vector<pll> up, lo;
	for (auto &p : pt) {
		while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.pop_back();
		while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.pop_back();
		up.emplace_back(p), lo.emplace_back(p);
    }

    reverse(all(up));
    for (int i=1; i<up.size()-1; i++) lo.pb(up[i]);

    
    int sl=lo.size();
    for (int i=0; i<sl; i++) {
        pll v1={lo[(i+1)%sl].first-lo[i].first, lo[(i+1)%sl].second-lo[i].second};
        double mx=0.0;
        for (int j=0; j<sl; j++) {
            if (j==i || j==(i+1)%sl) continue;
            pll v2={lo[j].first-lo[i].first, lo[j].second-lo[i].second};
            double d1=sqrt(1.0*v1.first*v1.first+1.0*v1.second*v1.second);
            double d2=sqrt(1.0*v2.first*v2.first+1.0*v2.second*v2.second);
            double th=acos(1.0*(v1.first*v2.first+v1.second*v2.second)/d1/d2);
            double l=sin(th)*d2;
            mx=max(mx,l);
        }
        ans=min(ans,mx);
    }
    cout<<fixed;
    cout.precision(10);
    
    cout<<ans;
}

void solve() {
	int n; cin >> n;
	vector<pll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
	rotating_calipus(a);
}

int main() {
	fio();
	
	int t=1;
	while (t--) solve();
	return 0;
}