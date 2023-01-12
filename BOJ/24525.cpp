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

int main() {
    fio();
    string s;
    cin>>s;
    int n=sz(s);

    reverse(all(s)); s+='x'; reverse(all(s));
    

    int p[MAX]={0}, ps[MAX]={0}, pk[MAX]={0};
    map<int,vector<int>> idx;
    idx[0].pb(0);

    bool isk=0, iss=0;
    for (int i=1; i<=n; i++) {
        p[i]=p[i-1];
        ps[i]=ps[i-1];
        pk[i]=pk[i-1];
        if (s[i]=='K') p[i]+=1, pk[i]+=1;
        if (s[i]=='S') p[i]-=2, ps[i]+=1;

        idx[p[i]].pb(i);
    }

    int ans=-1;
    for (auto [x,v]:idx) {
        if (sz(v)>=2) {
            bool ok1=(ps[v.back()]-ps[max(0,v[0]-1)]>0);
            bool ok2=(pk[v.back()]-pk[max(0,v[0]-1)]>0);
            if (ok1 && ok2) ans=max(ans, v.back()-v[0]);
        }
    }

    cout<<ans;
    return 0;
}