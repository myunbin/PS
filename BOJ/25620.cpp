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
    int n,q;
    cin>>n>>q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i=0; i<n; i++) {
        ll x; cin>>x;
        pq.push(x);
    }

    int ze=0;
    while (q--) {
        ll x,y;
        cin>>x>>y;
        if (y==1) continue;
        if (y==0) {
            while (!pq.empty() && pq.top()<=x) {
                ze++;
                pq.pop();   
            }
            continue;
        }

        vector<ll> out;
        while (!pq.empty() && pq.top()<=x) {
            out.pb(pq.top()*y);
            pq.pop();
        }
        while (!out.empty()) {
            pq.push(out.back());
            out.pop_back();
        }
    }

    while (ze--) cout<<0<<sp;
    while (!pq.empty()) {
        cout<<pq.top()<<sp;
        pq.pop();
    }
    return 0;
}