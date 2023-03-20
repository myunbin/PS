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

vector<int> f;
void init(vector<int> &b) {
    int m=sz(b);
    f.resize(m,0);
    for (int i=1,j=0; i<m; i++) {
        while (j>0 && b[i]!=b[j]) j=f[j-1];
        if (b[i]==b[j]) f[i]=(++j);
    }
}

bool ok(vector<int> &a, vector<int> &b) {
    int n=sz(a), m=sz(b);
    for (int i=0,j=0; i<n; i++) {
        while (j>0 && a[i]!=b[j]) j=f[j-1];
        if (a[i]==b[j]) {
            if (j==m-1) {
                return 1;
            }
            else j++;
        }
    }
    return 0;
}

int main() {
    fio();
    int n;
    cin>>n;
    vector<vector<int>> a;
    for (int i=0; i<n; i++) {
        int k; cin>>k;
        vector<int> t(k),r(k-1);
        for (int &x:t) cin>>x;
        for (int i=1; i<k; i++) r[i-1]=t[i]-t[i-1];
        a.pb(r); 
    }
    int l;
    cin>>l;
    vector<int> t(l), b(l-1);
    for (int &x:t) cin>>x;
    for (int i=1; i<l; i++) b[i-1]=t[i]-t[i-1];

    init(b);
    
    vector<int> ans;
    for (int i=0; i<n; i++) {
        if (ok(a[i], b)) ans.pb(i+1);
    }

    if (ans.empty()) cout<<-1;
    else {
        for (int x:ans) cout<<x<<sp;
    }
    return 0;
}