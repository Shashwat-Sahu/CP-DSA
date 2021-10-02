#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define f(i,j,k) for(int i=j;i<k;i++)
#define test_case ll t; scanf("%lld",&t); while(t--)
#define printl(a,n) for(i=0;i<n;i++) printf("%lld ",a[i])
#define vect(a) vector<ll,ll> a
#define vectPair(a) vector<pair<ll,ll>> a
//Start here
int n;
check(int **sudoku,int i,int j,int num){
    f(x,0,n){
        if(sudoku[x][j]==num||sudoku[i][x]==num) return 0;
    }
    i=(i/3)*3;
    j=(j/3)*3;
    f(x,i,i+3){
        f(y,j,j+3){
            if(sudoku[x][y]==num) return 0;
        }
    }
    return 1;

}

int findNext(int **sudoku,int *i,int *j){
    for(int y=(*j);y<n;y++){
        if(sudoku[(*i)][y]==-1){
            (*j)=y;
            return 1;
        }
    }
    int x=(*i)+1;
    for(;x<n;x++){
        for(int y=0;y<n;y++){
            if(sudoku[x][y]==-1){
                (*i)=x;
                (*j)=y;
                return 1;
            }
        }
    }
    return 0;
}

int solve(int **sudoku,int x,int y){
    int poss=findNext(sudoku,&x,&y);
    if(poss==0) return 1;
    
    f(i,1,10){
        if(check(sudoku,x,y,i)){
            sudoku[x][y]=i;
            if(solve(sudoku,x,y)==0){
                sudoku[x][y]=-1;
            }else return 1;
        }
    }
    return 0;


}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i,j,k;
    n=9;
    int** sudoku=new int*[n];
    for(int i=0;i<n;i++){
        sudoku[i]=new int[n];
        f(j,0,n) cin>>sudoku[i][j];
    }
    int x=0,y=0;
    solve(sudoku,x,y);
    
    f(i,0,n){
        f(j,0,n) cout<<sudoku[i][j]<<" ";
        cout<<endl;
    }

    
    
    return 0;
}