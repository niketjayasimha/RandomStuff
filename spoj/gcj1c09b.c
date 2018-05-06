#include <stdio.h>
#include <math.h>

double distance(double x, double y, double z, double vx, double vy, double vz, double t)
{
	double dist = sqrt(((x + vx * t) * (x + vx * t)) + ((y + vy * t) * (y + vy * t)) + ((z + vz * t) * (z + vz * t)));
	return dist;
}

int main()
{
	double x, y, z, vx, vy, vz;
	int t, n;
	double cmx, cmy, cmz, vcmx, vcmy, vcmz;
	int i, cases = 1;
	double sx, sy, sz, svx, svy, svz, time, dist;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sx = sy = sz = svx = svy = svz = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &z, &vx, &vy, &vz);
			sx += x; sy += y; sz += z;
			svx += vx; svy += vy; svz += vz;
		}

		cmx = sx / n; cmy = sy / n; cmz = sz / n;
		vcmx = svx / n; vcmy = svy / n; vcmz = svz / n;

		if(vcmx == 0 && vcmy == 0 && vcmz == 0)
			time = 0;
		else
			time = 0 - ((vcmx * cmx + vcmy * cmy + vcmz * cmz) / (vcmx * vcmx + vcmy * vcmy + vcmz * vcmz));

		if(time < 0)
			time = 0;

		dist = distance(cmx, cmy, cmz, vcmx, vcmy, vcmz, time);
		
		printf("Case #%d: %.8lf %.8lf\n", cases++, dist, time);
	}
	return 0;
}
