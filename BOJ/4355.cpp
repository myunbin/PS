#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007;
const ll LMOD = 1000000007; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
//const int MAXN = 101010;
const int MAXR = 2e5 + 10;

// time complexity : O(sqrt(N))
// returns result of phi(n)
const ll MAXN = 1010101;
vector<ll> prm;
void siv() {
    bool chk[MAXN] = {0};
    for (ll i = 2; i < MAXN; i++) {
        if (chk[i]) continue;
        prm.pb(i);
        for (ll j = i*i; j < MAXN; j += i) {
            chk[j] = 1;
        }
    }
}

ll phi(ll n) {
    ll t = n, ans = n;
    for (ll x : prm) {
        if (t <= 1) break;
        if (!(t%x)) ans /= x, ans *= (x-1);
        while (t>0 && !(t%x)) t /= x;
    }
    if (t > 1) ans /= t, ans *= (t-1);

    return ans;
}

int main() {
    fio();
    siv();
    while (true) {
        ll x;
        cin >> x;
        if (x == 0) return 0;
        cout << (x==1?0:phi(x)) << endl;
    }
    return 0;
}
