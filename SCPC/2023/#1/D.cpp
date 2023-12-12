#include <bits/stdc++.h>
using namespace std;
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
const int MAX = 252525; // PLZ CHK!

string A,B;
int N,M;

int go(int i, vector<int> &d) {
    if (i>=N) return 0;
    int &ret=d[i];
    if (ret!=-1) return ret;

    ret=INF;
    int x=i,y=0;
    while (x<N && y<M && A[x]==B[y]) {
        ret=min(ret, 1+go(x+1,d));
        x++,y++;
    }
    return ret;
}

int kmp() {
    vector<int> f(M+10);
    for (int i=1, j=0; i<M; i++) {
        while (j>0 && B[i]!=B[j]) j=f[j-1];
        if (B[i]==B[j]) f[i]=(++j);
    }

    vector<int> ans(N+10);
    for (int i=0,j=0; i<N; i++) {
        while (j>0 && A[i]!=B[j]) j=f[j-1];
        if (A[i]==B[j]) {
            ans[i]=max(ans[i], j+1);
            if (j==M-1) {
                j=f[j];
            }
            else j++;
        }
    }
    
    for (int i=0; i<N; i++) cout<<ans[i]<<sp; cout<<endl;

    return 0;
}

void solve() {
    A.clear(), B.clear();

    cin>>A>>B;
    N=sz(A),M=sz(B);
    if (N>10000 || M>10000) {
        cout<<0<<endl;
        return;
    }

    for (int i=0; i<M; i++) A+='X', N++;
    cout<<A<<sp<<B<<endl;

    kmp();

    // vector<int> d(N+10,-1);
    // int ans=go(0,d);
    // cout<<(ans==INF?-1:ans)<<endl;
}

int main() {
    fio();
    int t; cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}