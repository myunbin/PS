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
const int MAX = 303; // PLZ CHK!

struct fwt {
    // 1-indexed!
    vector<int> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, int v) {
        for (; i<sz(tr); i+=(i&-i)) tr[i]+=v;
    }
    int kth(int k){
        int ret=0;
        for (int i=log2(sz(tr))+1; i>=0; i--) {
            int pv=(1<<i);
            if (ret+pv<sz(tr) && tr[ret+pv]<k) {
                k-=tr[ret+pv];
                ret+=pv;
            }
        }
        return ret;   
    }
};

int N,M,K,W,A[MAX][MAX];
int main() {
    fio();
    cin>>N>>M>>K>>W;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
            A[i][j]++;
        }
    }
    
    for (int i=1; i+W-1<=N; i++) {
        fwt seg; seg.rst(1e5+10);
        for (int x=i; x<=i+W-1; x++) {
            for (int y=1; y<=W; y++) {
                seg.upd(A[x][y],1);
            }
        }
        for (int j=1; j+W-1<=M; j++) {
            cout<<seg.kth((W*W+1)/2)<<sp;
            if (j+W<=M) {
                for (int k=i; k<=i+W-1; k++) {
                    seg.upd(A[k][j],-1);
                    seg.upd(A[k][j+W],1);
                }
            }
        }
        cout<<endl;
    }

    return 0;
}