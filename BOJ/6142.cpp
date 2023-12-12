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

int N,M;
pll A[MAX],B[MAX];
multiset<ll> MS;

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<N; i++) cin>>A[i].F>>A[i].S;
    for (int i=0; i<M; i++) cin>>B[i].F>>B[i].S;
    
    sort(A,A+N,[](pll a, pll b){
        return a.S>b.S;
    });
    sort(B,B+M,[](pll a, pll b){
        return a.S>b.S;
    });

    ll ans=0;
    for (int i=0,j=0; i<N; i++) {
        while (j<M && B[j].S>=A[i].S) MS.insert(B[j].F),j++;
        auto it=MS.lb(A[i].F);
        if (it==MS.end()) {
            cout<<-1;
            return 0;
        }
        ans+=*it;
        MS.erase(it);
    }

    cout<<ans;
    
    return 0;
}