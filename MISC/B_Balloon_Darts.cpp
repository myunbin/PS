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
const int MAX = 10101; // PLZ CHK!

int N;
set<pll> A;

void go(int m, set<pll> &s) {
    if (sz(s)<=2*m) {
        cout<<"possible";
        exit(0);
    }

    vector<pll> t;
    int k=m+1; auto it=s.begin();
    for (int i=0; i<k; i++) t.pb(*(it++));

    for (int i=0; i<k; i++) {
        for (int j=i+1; j<k; j++) {
            ll a=(t[j].S-t[i].S), b=-(t[j].F-t[i].F), c=t[i].S*(t[j].F-t[i].F)-t[i].F*(t[j].S-t[i].S);

            vector<pll> del;
            for (auto &[x,y]:s) {
                if (a*x+b*y+c==0) del.pb({x,y});
            }

            for (auto [x,y]:del) s.erase({x,y});
            go(m-1,s);
            for (auto [x,y]:del) s.insert({x,y});
        }
    }
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) {
        ll x,y; cin>>x>>y;
        A.insert({x,y});
    }

    set<pll> s; 
    for (auto [x,y]:A) s.insert({x,y});

    go(3,s);
    cout<<"impossible";

    return 0;
}


