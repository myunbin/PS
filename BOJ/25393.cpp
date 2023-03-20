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
    int n;
    cin>>n;
    vector<pii> v(n);
    set<pii> s;
    map<int,int> st,ed;
    for (int i=0; i<n; i++) {
        cin>>v[i].F>>v[i].S;
        s.insert(v[i]);
        if (st.find(v[i].F)==st.end()) st[v[i].F]=-1;
        st[v[i].F]=max(st[v[i].F], v[i].S);
        
        if (ed.find(v[i].S)==ed.end()) ed[v[i].S]=INF;
        ed[v[i].S]=min(ed[v[i].S], v[i].F);
    }
    
    int q;
    cin>>q;
    while (q--) {
        int x,y;
        cin>>x>>y;
        if (s.find({x,y})!=s.end()) {
            cout<<1<<endl;
            continue;
        }

        if (st.find(x)!=st.end() && ed.find(y)!=ed.end()) {
            int ex=st[x], sy=ed[y];
            if (sy<=x && y<=ex) {
                cout<<2<<endl;
                continue;
            }
        }
        cout<<-1<<endl;
    }

    return 0;
}