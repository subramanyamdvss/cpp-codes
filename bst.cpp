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
/// ********* debug template bt Bidhan Roy *********

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



class Node{
public:   
    lli key;
    Node* left;
    Node* right;
    Node* parent;

};

Node* createnode(lli k){
        Node* n=(Node* ) malloc(sizeof(Node));
        n->left=NULL;
        n->right=NULL;
        n->parent=NULL;
        n->key=k;
        return n;
}

class Btree{
public:
    Node* root;
    lli num;
};

Node* search(Node* n,lli k){
    if(n==NULL) return NULL;
    else if(k==n->key) return n;
    else if(k<n->key) return search(n->left,k);
    else return search(n->right,k);
}

void parentop(Node *&a,Node *&b){
    a=b;
    b->parent=a->parent;
}

Node* insertnode(Node* n,lli k){
    if(n==NULL) return createnode(k);
    else if(k<n->key){
        Node* c=insertnode(n->left,k);
        parentop(n->left,c);
    }
    else if (k==n->key) return n;
    else{
        Node* c=insertnode(n->right,k);
        parentop(n->right,c); 
    } 
    return n;
}

void transplant(Node *&u,Node *&v){
    
    //v->left=u->left;
    //v->right=u->right;
    if(u->left==v){
        v->right=u->right;
    }
    if(u->right==v){
        v->left=u->left;
    }
    if(v->left) v->left->parent=v;
    if(v->right) v->right->parent=v;
    v->parent=u->parent;

    if(u->parent==NULL){
        v->parent=NULL;
        return;
    }
    if(u->parent->left==u){
        u->parent->left=v;
    } 
    else  u->parent->right=u;
    return;
 }   

Node* treemin(Node* n){
    if(!n->left) return n;
    else  return treemin(n->left);
}

void deletenode(Node* root,lli k){
    Node* mini=NULL;

    if(!root) cout<<"error zero tree"<<endl;
    Node* curr=search(root,k);
    //cout<<curr->right<<endl;
    if(!curr) cout<<"error no such element" <<endl;

    if(curr->right==NULL){
        
        transplant(curr,curr->left);
    } 
    else if(curr->left==NULL){
        //error("del");
        transplant(curr,curr->right);
    } 
    else {
        
        mini=treemin(curr->right);

        //if(mini->parent==curr) 
        if(mini->right==NULL){
             error("del",curr->key,mini->key,mini->left,mini->right);
             cout<<root->right->right<<endl;
             transplant(curr,mini);
             

        } 
        else{
            
            transplant(mini,mini->right);
            transplant(curr,mini);
        } 
    }
    return;

}


void inorder(Node* n){
    if(!n) return;
    else {
        inorder(n->left);
        cout<<n->key<<" ";
        inorder(n->right);
    }

}


int main(){
    Node* root=createnode(5);
    Node *p=createnode(3);
    parentop(root->left,p);
    p=createnode(6);
    parentop(root->right,p);
    p=createnode(4);
    parentop(root->left->right,p);
    //cout<<search(root,4)->key<<endl;
    deletenode(root,5);
    cout<<endl;
    error(root->parent,root->left->left,root->right->key,root->left->right->key);
    

}
















