#include <stdio.h>
#define myabs(x) ((x < 0)? (-x):x)
int main() 
{
	double mw, mi, tw, ti;

	double Qi2i0;
	double Qw2w0;
	double ci, cw, em;
	double final_temp;
	double delta_m;

	ci = 2.09;
	cw = 4.19;
	em = 335;


	for(;;)
	{

		scanf("%lf %lf %lf %lf", &mw, &mi, &tw, &ti);
		if(mw == 0 && mi == 0 && tw == 0 && ti == 0)
			break;
		// E to make ice 0C
		Qi2i0 = mi * ci * (0-ti);
		// E to make water 0C
		Qw2w0 = mw *cw * tw;

		if(Qi2i0 > Qw2w0) 
		{
			Qi2i0 = Qi2i0 - Qw2w0;
			if(mw * em > Qi2i0) 
			{ // part of water become ice. final temp = 0
				final_temp = 0;
				delta_m = Qi2i0 / em;
				mw = mw - delta_m;
				mi = mi + delta_m;
			}
			else 
			{ // all water become ice 
				Qi2i0 = Qi2i0 - mw * em;
				final_temp = -1 * (Qi2i0 / (ci * (mw + mi)));
				mi = mi + mw;
				mw = 0;
			}
		}
		else 
		{ // Qi2i0 <= Qw2w0
			Qw2w0 = Qw2w0 - Qi2i0;
			if(mi * em > Qw2w0) 
			{ // part of ice will become water. final temp = 0
				final_temp = 0;
				delta_m = Qw2w0 / em;
				mw = mw + delta_m;
				mi = mi - delta_m;
			}
			else 
			{ // all ice will become water
				Qw2w0 = Qw2w0 - mi * em;
				final_temp = Qw2w0 / (cw * (mw + mi));
				mw = mi + mw;
				mi = 0;
			}
		}

		printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n", mi, mw, final_temp);
	}
	return 0;
}

