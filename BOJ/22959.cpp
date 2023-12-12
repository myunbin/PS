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
const int MAX = 202020; // PLZ CHK!

struct minseg{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1,LINF);
    }

    void upd(int i, ll v) {
        tr[i+n] = v; i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = min(tr[i<<1], tr[i<<1|1]);
    }

    ll qry(int l, int r) {
        ll ret = LINF;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, tr[l++]);
            if (~r&1) ret = min(ret, tr[r--]);
        }
        return ret;
    }
};

struct sumseg{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1,0);
    }

    void upd(int i, ll v) {
        tr[i+n] = v; i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = tr[i<<1]+tr[i<<1|1];
    }

    ll qry(int l, int r) {
        ll ret = 0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret+=tr[l++];
            if (~r&1) ret+=tr[r--];
        }
        return ret;
    }
};

int N,A[MAX];
minseg MS;
sumseg SS;

int main() {
    fio();
    MS.rst(MAX),SS.rst(MAX);

    cin>>N;
    for (int i=1; i<=N; i++) {
        int x; cin>>x;
        MS.upd(i,x), SS.upd(i,x);
    }
    int Q; cin>>Q;
    while (Q--) {
        int x,i,j;
        cin>>x>>i>>j;
        if (x==1) {
            MS.upd(i,j);
            SS.upd(i,j);
        }
        else {
            int L=i,R=i;
            int le=i,ri=N;
            while (le<=ri) {
                int md=(le+ri)>>1;
                if (MS.qry(i,md)>=j) {
                    R=md;
                    le=md+1;
                }
                else ri=md-1;
            }
            le=1,ri=i;
            while (le<=ri) {
                int md=(le+ri)>>1;
                if (MS.qry(md,i)>=j) {
                    L=md;
                    ri=md-1;
                }
                else le=md+1;
            }

            cout<<SS.qry(L,R)<<endl;
        }
    }
    return 0;
}