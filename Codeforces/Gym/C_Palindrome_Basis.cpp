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
const int MAX = 40404; // PLZ CHK!

vector<int> pal;

void init() {
    for (int i=1; i<MAX; i++) {
        vector<int> a;
        int t=i;
        while (t) {
            a.pb(t%10);
            t/=10;
        }
        bool ok=1;
        for (int j=0; j<sz(a)/2; j++) {
            if (a[j]!=a[sz(a)-1-j]) {
                ok=0;
                break;
            }
        }

        if (ok) pal.pb(i);
    }
}

ll d[MAX];

void init2() {
    d[0]=1;
    for (int i=0; i<sz(pal); i++) {
        for (int j=1; j<MAX; j++) {
            if (j-pal[i]<0) continue;
            d[j]=(d[j]+d[j-pal[i]])%MOD;
        }
    }    
}
void solve() {
    int n;
    cin>>n;
    cout<<d[n]<<endl;
}
int main() {
    fio();
    init();
    // cout<<sz(pal);
    // for (int i=0; i<100; i++) cout<<pal[i]<<endl;
    init2();
    int t; 
    cin>>t;
    while (t--) solve();
    return 0;
}