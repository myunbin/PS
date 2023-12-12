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
    int N;
    cin>>N;
    pii A[10];
    for (int i=0; i<N; i++) {
        cin>>A[i].F>>A[i].S;
        if (A[i].F>A[i].S) swap(A[i].F,A[i].S);
    }
    sort(A,A+N);
    set<pii> t;

    int cnt=0;
    for (int i=0; i<N; i++) {
        auto [a,b]=A[i];
        for (int j=i+1; j<N; j++) {
            auto [c,d]=A[j];
            if (a<c && c<b && b<d) {
                cnt++;
                t.insert(A[i]), t.insert(A[j]);
            }
        }
    }
    
    // cout<<cnt<<endl;
    if (cnt==0) cout<<0;
    else if (cnt==1) cout<<1;
    else if (cnt==2) cout<<1;
    else if (cnt==3) cout<<1;
    else {
        if (N<10) cout<<2;
        else cout<<-1;
    }
    return 0;
}