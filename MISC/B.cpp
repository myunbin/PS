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
    int N; string S;
    cin>>N>>S;
    reverse(all(S)); S+='x'; reverse(all(S));

    ll ans=0;
    vector<int> d(N+1,0);
    vector<pair<char,int>> st;
    
    for (int i=1; i<=N; i++) {
        if (S[i]=='(' || S[i]=='{') st.pb({S[i],i});
        else if (S[i]==')') {
            if (!st.empty() && st.back().F=='(') {
                auto [c,j]=st.back(); st.pop_back();
                d[i]=d[j-1]+1;
                ans+=d[i];
            }
            else {
                st.clear();
            }
        }
        else {
            if (!st.empty() && st.back().F=='{') {
                auto [c,j]=st.back(); st.pop_back();
                d[i]=d[j-1]+1;
                ans+=d[i];
            }
            else {
                st.clear();
            }
        }
    }

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