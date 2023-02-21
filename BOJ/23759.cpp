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
const int MAX = 505050; // PLZ CHK!

int main() {
    fio();
    int n,k;
    cin>>n>>k;
    vector<string> a(n);
    for (string &s:a) cin>>s;

    vector<int> g[MAX];
    int ind[MAX]={0};

    for (int j=0; j<k; j++) {
        vector<int> bk['z'-'a'+1];
        for (int i=0; i<n; i++) {
            bk[a[i][j]-'a'].pb(i);
        }
        
        for (int i=0; i<='z'-'a'; i++) {
            for (int t=0; t<sz(bk[i])-1; t++) {
                int u=bk[i][t], v=bk[i][t+1];
                g[u].pb(v);
                ind[v]++;
            }
        }
    }

    int d[MAX]={0};
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (!ind[i]) {
            q.push(i);
            d[i]=1;
        }
    }

    while (!q.empty()) {
        int cur=q.front(); q.pop();

        for (int nxt:g[cur]) {
            d[nxt]=max(d[nxt], d[cur]+1);
            if ((--ind[nxt])==0) {
                q.push(nxt);
            }
        }
    }

    cout<<(n-*max_element(d,d+n));

    return 0;
}