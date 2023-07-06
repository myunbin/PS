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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int v[22], t[111], d[MAX];

int main() {
    fio();
    int n,b;
    cin>>n>>b;
    for (int i=1; i<=b; i++) cin>>v[i];
    for (int i=1; i<=n; i++) cin>>t[i];

    fill(d,d+MAX,INF);
    d[0]=0;
    
    for (int i=1; i<MAX; i++) {
        for (int j=1; j<=b; j++) {
            if (i-v[j]>=0) d[i]=min(d[i], d[i-v[j]]+1);
        }
    }

    int p=1;
    while (p<=n && t[p]==0) p++;

    if (d[t[p]]==INF) {
        cout<<-1;
        return 0;
    }

    int ans=d[t[p]];
    for (int i=p+1; i<=n; i++) {
        if (t[i-1]-1<=t[i]) {
            if (d[t[i]+1-t[i-1]]==INF) {
                cout<<-1;
                return 0;
            }
            ans+=d[t[i]+1-t[i-1]];
        }
        else {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}