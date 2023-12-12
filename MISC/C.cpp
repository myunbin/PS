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
const int MAX = 101010; // PLZ CHK!

void solve() {
    int N,M,T;
    cin>>N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];
    cin>>M>>T;

    if (N>20) {
        cout<<0<<endl;
        return;
    }

    vector<int> B(N);
    for (int i=0; i<M; i++) B[i]=1;

    int ans=0;
    do {    
        int cur=0;
        for (int i=0; i<N; i++) {
            if (B[i]) cur|=(1<<i);
        }

        for (int i=0; i<T; i++) {
            int nxt=cur;
            for (int j=0; j<N; j++) {
                if (cur&(1<<j)) continue;
                if (A[j]==1 && ((j>0 && (cur&(1<<(j-1)))) || (j<N-1 && (cur&(1<<(j+1)))))) nxt|=(1<<j);
                if (A[j]==2 && (j>0 && (cur&(1<<(j-1)))) && (j<N-1 && (cur&(1<<(j+1))))) nxt|=(1<<j);
            }
            cur=nxt;
        }

        ans=max(ans, __builtin_popcount(cur));
    } while (prev_permutation(all(B)));
    
    cout<<ans<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }

    return 0;
}