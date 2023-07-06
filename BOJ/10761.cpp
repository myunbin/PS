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

int n;
ll a[30][7], ans=0;

void go(vector<int> &m) {
    if (sz(m)==7) {
        int B=m[0],E=m[1],S=m[2],I=m[3],G=m[4],O=m[5],M=m[6];
        if (((B+E+S+S+I+E)*(G+O+E+S)*(M+O+O))%7==0) {
            ans+=a['B'-'A'][B]*a['E'-'A'][E]*a['S'-'A'][S]*a['I'-'A'][I]*a['G'-'A'][G]*a['O'-'A'][O]*a['M'-'A'][M];
        }
        return;
    }

    for (int i=0; i<7; i++) {
        m.pb(i);
        go(m);
        m.pop_back();
    }
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) {
        char c; int x;
        cin>>c>>x;
        x+=7*7*7*7*7*7;
        a[c-'A'][x%7]++;   
    }

    vector<int> m;
    go(m);

    cout<<ans;
    return 0;
}