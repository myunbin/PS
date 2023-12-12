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

int N,M,K,T[MAX];
char A[MAX];
vector<int> G[MAX];

int main() {
    fio();
    for (int i=0; i<MAX; i++) A[i]='?';

    cin>>N>>M>>K;
    
    bool con=0;
    for (int i=1; i<=N; i++) cin>>T[i];
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
        if (min(u,v)==1 && max(u,v)==N) con=1;
    }

    if (N==2 && K==1) {
        cout<<"impossible";
        return 0;
    }
    if (K==0||K==N) {
        for (int i=1; i<=N; i++) cout<<(K==0?'S':'N');
        return 0;
    }

    int nd=K, sw=N-K;
    if (con) {
        if (K>=N-K) {
            A[1]=A[N]='N'; 
            nd-=2;
            for (int i=1; i<=N; i++) {
                if (A[i]!='?') continue;
                if (nd) {
                    A[i]='N';
                    nd--;
                }
                else A[i]='S';
            }
        }
        else {
            A[1]=A[N]='S';
            sw-=2;
            for (int i=1; i<=N; i++) {
                if (A[i]!='?') continue;
                if (nd) {
                    A[i]='N';
                    nd--;
                }
                else A[i]='S';
            }
        }

        for (int i=1; i<=N; i++) cout<<A[i];
        return 0;
    }

    
    A[1]='N'; nd--;
    for (int i=0; i<min(nd,sz(G[1])); i++) {
        int j=G[1][i];
        A[j]='N';
    }
    nd-=min(nd,sz(G[1]));

    for (int i=1; i<=N; i++) {
        if (A[i]!='?') continue;
        if (nd) {
            A[i]='N';
            nd--;
        }
        else A[i]='S';
    }
    

    for (int i=1; i<=N; i++) cout<<A[i];
    return 0;
}