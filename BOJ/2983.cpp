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

int main() {
    fio();
    int n,k; cin>>n>>k;
    string s; cin>>s;

    vector<pii> pl(n);
    map<int, set<int>> AD,BC;
    pii cur;

    for (auto &[x,y]:pl) {
        cin>>x>>y;
        AD[x-y].insert(x);
        BC[x+y].insert(x);
    }

    cur=pl[0];
    for (int i=0; i<k; i++) {
        // cout<<cur.F<<sp<<cur.S<<endl;
        char dir=s[i];
        pii nxt;

        int vad=cur.F-cur.S, vbc=cur.F+cur.S;
        if (dir=='A') {
            if (AD[vad].empty()) {
                continue;
            }

            auto it=AD[vad].ub(cur.F);
            if (it==AD[vad].end()) {
                continue;
            }

            nxt={*it, *it-vad};
        }
        if (dir=='B') {
            if (BC[vbc].empty()) {
                continue;
            }

            auto it=BC[vbc].ub(cur.F);
            if (it==BC[vbc].end()) {
                continue;
            }

            nxt={*it, vbc-*it};
        }
        if (dir=='C') {
            if (BC[vbc].empty()) {
                continue;
            }

            auto it=BC[vbc].lb(cur.F);
            if (it==BC[vbc].begin()) {
                continue;
            }

            --it;
            nxt={*it, vbc-*it};
        }
        if (dir=='D') {
            if (AD[vad].empty()) {
                continue;
            }

            auto it=AD[vad].lb(cur.F);
            if (it==AD[vad].begin()) {
                continue;
            }

            --it;
            nxt={*it, *it-vad};
        }
        
        AD[vad].erase(cur.F);
        BC[vbc].erase(cur.F);
        cur=nxt;
    }
    cout<<cur.F<<sp<<cur.S<<endl;
    return 0;
}