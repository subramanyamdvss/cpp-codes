#include <bits/stdc++.h>
using namespace std;

typedef  long long lli;
typedef vector< long long int > vi;
typedef  double d;
typedef  pair<lli,pair<lli,lli> >  pipii;
#define bg begin()
#define rbg rbegin()
#define ren rend()
#define en end()
#define f first
#define s second
#define For(ii,aa,bb) for(lli ii=aa;ii<=bb;++ii)
#define Rof(ii,aa,bb) for(lli ii=aa;ii>=bb;--ii)
#define pb push_back
#define minf(a,b,c) min(min(a,b),c)
#define maxf(a,b,c) max(max(a,b),c)
#define mp make_pair
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;

void printm(char *a,lli i,char *b,lli j,lli mov[][100],stack<char>& st){
    if(i==-1||j==-1 ) return;
    if(mov[i][j]==0){
        st.push(a[i]);
        printm(a,i-1,b,j-1,mov,st);
    }
    if(mov[i][j]==1){
        printm(a,i-1,b,j,mov,st);
    }
    if(mov[i][j]==2){
        printm(a,i,b,j-1,mov,st);
    }
}

void lcs(char *a,lli m,char* b,lli n){
    lli s[m][n];
    char str[m][n][100];
    lli mov[100][100];
    
    For(i,0,m-1){
        For(j,0,n-1){
            if(i==0||j==0){
                if(a[i]==b[j]){
                    s[i][j]=1;
                    mov[i][j]=0;
                } 
                else if(i==0&&j!=0) s[i][j]=s[i][j-1],mov[i][j]=2;
                else if(j==0&&i!=0) s[i][j]=s[i-1][j],mov[i][j]=1;
                else if(i==0&&j==0) s[i][j]=0,mov[i][j]=3;
                continue;
            }
            if(a[i]==b[j]){
                mov[i][j]=0;
                
                s[i][j]=s[i-1][j-1]+1;
            } 

            else{
                if(s[i-1][j]>s[i][j-1]) mov[i][j]=1;
                else mov[i][j]=2;
                s[i][j]=max(s[i-1][j],s[i][j-1]);
            }
        }
    }
    cout<<s[m-1][n-1]<<endl;
    stack<char> st;
    printm(a,m-1,b,n-1,mov,st);
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    lli m,n;
    cin>>m>>n;
    char a[m],b[n];
    cin>>a;
    cin>>b;
    lcs(a,m,b,n);
}

