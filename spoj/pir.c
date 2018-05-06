#include <stdio.h>
#include <math.h>
double sqr(double n);
int main()
{
	int t,i;
	double u,v,w,U,V,W;
	double vol;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&V,&W,&u,&U,&w,&v);
		vol=sqrt(4*sqr(u)*sqr(v)*sqr(w)-sqr(u)*sqr(sqr(v)+sqr(w)-sqr(U))-sqr(v)*sqr(sqr(w)+sqr(u)-sqr(V))-sqr(w)*sqr(sqr(u)+sqr(v)-sqr(W))+(sqr(v)+sqr(w)-sqr(U))*(sqr(w)+sqr(u)-sqr(V))*(sqr(u)+sqr(v)-sqr(W)))/12;
		printf("%.4lf\n",vol);
	}
	return 0;
}
double sqr(double n)
{
	return n*n;
}
