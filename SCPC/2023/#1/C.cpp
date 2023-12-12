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

bool isb(vector<int> &a) {
    for (int x:a) {
        if (x>1) return 0;
    }
    return 1;
}

int kmp(vector<int> &s, vector<int> &t) {
    int n=sz(s), m=sz(t);
    vector<int> f(m);
    for (int i=1, j=0; i<m; i++) {
        while (j>0 && t[i]!=t[j]) j=f[j-1];
        if (t[i]==t[j]) f[i]=(++j);
    }

    vector<int> ans;
    for (int i=0,j=0; i<n; i++) {
        while (j>0 && s[i]!=t[j]) j=f[j-1];
        if (s[i]==t[j]) {
            if (j==m-1) {
                if (i-m+1!=0) return i-m+1;
                j=f[j];
            }
            else j++;
        }
    }
    return -1;
}

void solve() {
    int N; 
    cin>>N;

    bool z=0;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin>>A[i];
        if (A[i]==0) z=1;
    }

    if (!z) {
        cout<<1<<endl;
        return;
    }

    if (isb(A)) {
        reverse(all(A));
        vector<int> B=A;
        for (int i=0; i<N; i++) B.pb(B[i]);
        cout<<kmp(B,A)<<endl;
    }
    else if (N<=1000) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) cout<<A[j]<<sp; cout<<endl;

            vector<int> B=A;
            for (int j=0; j<N; j++) {
                if (A[(j-1+N)%N]>0) B[j]++;
                if (A[j]>0) B[j]--;
            }

            // bool ok=1;
            // for (int j=0; j<N; j++) {
            //     if (A[j]!=B[j]) {
            //         ok=0;
            //         break;
            //     }
            // }

            // if (ok) {
            //     cout<<1<<endl;
            //     return;
            // }

            // if (isb(B)) {
            //     reverse(all(B));
            //     vector<int> C=B;
            //     for (int j=0; j<N; j++) C.pb(C[j]);
            //     cout<<kmp(C,B)<<endl;
            //     return;
            // }

            A=B;
        }
    }
    else {
        ll sum=0;
        for (int i=0; i<N; i++) sum+=A[i];
        if (sum>=N) cout<<1<<endl;
        else cout<<N<<endl;
    }
}

int main() {
    fio();
    int t=1;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}