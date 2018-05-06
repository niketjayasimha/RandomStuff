#include<iostream>
int f(int n){return n<2?2:f(n-1)*(4*n-2)/n;}
int main(){int t,m;std::cin>>t;while(t--){std::cin>>m;std::cout<<f(m)<<std::endl;}}
