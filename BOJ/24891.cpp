#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int n,l;
vector<string> s;

bool ok(vector<int> &idx) {
    vector<string> v;
    for (int x:idx) v.pb(s[x]);

    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            if (v[i][j]!=v[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    fio();
    cin>>l>>n;
    s.resize(n);
    vector<int> pr(n,0);
    for (int i=0; i<l; i++) pr[i]=1;
    for (string &x:s) cin>>x;

    sort(all(s));
    vector<vector<int>> ans;
    do {
        vector<int> idx;
        for (int i=0; i<n; i++) if (pr[i]) idx.pb(i);
        do {
            if (ok(idx)) ans.pb(idx);
        } while (next_permutation(all(idx)));

    } while (prev_permutation(all(pr)));

    if (ans.empty()) cout<<"NONE";
    else {
        sort(all(ans));
        for (int x:ans[0]) {
            cout<<s[x]<<endl;
        }
    }
    return 0;
}