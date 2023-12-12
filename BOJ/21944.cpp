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
const int MAX = 111; // PLZ CHK!

int N,M;
pii P[101010];
set<pii> G[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        int p,l,g;
        cin>>p>>l>>g;
        G[g].insert({l,p});
        P[p]={l,g};
    }

    cin>>M;
    while (M--) {
        string s; cin>>s;

        if (s=="recommend") {
            int g,x; cin>>g>>x;
            if (x==1) {
                cout<<G[g].rbegin()->S<<endl;
            }
            else {
                cout<<G[g].begin()->S<<endl;
            }
        }
        else if (s=="recommend2") {
            int x; cin>>x;
            if (x==1) {
                int l=-1, mx=-1;
                for (int g=1; g<MAX; g++) {
                    if (G[g].empty()) continue;
                    if (l<G[g].rbegin()->F) {
                        l=G[g].rbegin()->F;
                        mx=G[g].rbegin()->S;
                    }
                    else if (l==G[g].rbegin()->F) {
                        mx=max(mx, G[g].rbegin()->S);
                    }
                }
                cout<<mx<<endl;
            }
            else {
                int l=INF, mn=INF;
                for (int g=1; g<MAX; g++) {
                    if (G[g].empty()) continue;
                    if (l>G[g].begin()->F) {
                        l=G[g].begin()->F;
                        mn=G[g].begin()->S;
                    }
                    else if (l==G[g].begin()->F) {
                        mn=min(mn, G[g].begin()->S);
                    }
                }
                cout<<mn<<endl;
            }
        }
        else if (s=="recommend3") {
            int x,l; cin>>x>>l;
            if (x==1) {
                int d=INF, mn=INF;
                for (int g=1; g<MAX; g++) {
                    if (G[g].empty()) continue;
                    auto it=G[g].lb(make_pair(l,-1));
                    if (it==G[g].end()) continue;
                    
                    if (d>it->F-l) {
                        d=it->F-l;
                        mn=it->S;
                    }
                    else if (d==it->F-l) {
                        mn=min(mn, it->S);
                    }
                }
                cout<<(d==INF?-1:mn)<<endl;
            }
            else {
                int d=INF, mx=-1;
                for (int g=1; g<MAX; g++) {
                    if (G[g].empty()) continue;
                    auto it=G[g].lb(make_pair(l,-1));
                    if (it==G[g].begin()) continue;
                    it--; 
                    
                    if (d>l-it->F) {
                        d=l-it->F;
                        mx=it->S;
                    }
                    else if (d==l-it->F) {
                        mx=max(mx, it->S);
                    }
                }
                cout<<(d==INF?-1:mx)<<endl;
            }
        }
        else if (s=="add") {
            int p,l,g; cin>>p>>l>>g;
            G[g].insert({l,p});
            P[p]={l,g};
        }
        else {
            int p; cin>>p;
            auto [l,g]=P[p];

            G[g].erase({l,p});
            P[p]={0,0};
        }
    }
    return 0;
}