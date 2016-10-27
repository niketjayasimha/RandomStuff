#include <stdio.h>

long long ceilb2(long long n){
	if(n%2==1) return n/2+1;
	else return n/2;
}

long long f(long long n, int p){
	if(n<3)return 0;
	if(n==3){ return 3-p;}
	else{
		if(p==0) p=1;
		else if(p==1){
			if(n%2==0) p=1;
			else p=2;
		}
		else{
			p=2;
		}
		return( f( ceilb2(n)+1,p) +1);
	}
}

int main(){
	long long t,n,i;
	int X[15];
	for(i = 0; i < 15; i++)
		X[i] = 0;
	for(i=4;i<20000;i++){
		 int y = (int)f(i, 0);
		 if(y < 15)
			X[y] = X[y] + 1;		
	}
	for(i = 0; i < 15; i++)
		printf("%lld: %d\n", i, X[i]);
	return 0;
}
