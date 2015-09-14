#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

double Pi = 3.141592653;
typedef double (*f_t)(double x, double phase);


double D2R(double x[3])
{
    return Pi*(x[0] + x[1]/60.0 + x[2]/(60.0 * 60.0))/180.0;
}

double f_1(double x, double phase)
{
    return cos(x)*cos(phase - x) - 0.4327;
}

double f_2(double x, double phase)
{
    return cos(x)*cos(phase + x) - 0.4327;
}

double f_1_1(double x, double phase)
{
    return cos(x)*cos(phase - x) - 0.6524;
}

double f_2_1(double x, double phase)
{
    return cos(x)*cos(phase + x) - 0.6524;
}

double df(double x, double phase)
{
    return (cos(x)*sin(phase - x));
}

double do_solve(double x0, double x1, f_t f,double phase, double error)
{
    double x_1 = 0.0;

	if (fabs(f(x1,phase)) <= error){
		return x1;
	}
	
	x_1 = x1 - (x1 - x0)*(f(x1,phase) / (f(x1,phase) - f(x0,phase)));
    return do_solve(x1,x_1,f,phase,error);
}


int main(void)
{
	double x[3] = {11.0, 43.0,1.0};
	double phase = 0.0;
	double error = 0.000001;
	double ans = 0.0; 

	phase = D2R(x);
//	printf("phase = %lf\n\n\n",phase);
    printf("\n\nfigure : cos(delta)*cos(phi) = 0.4327\n");
	printf("where : delta + phi = 11°43‘1’‘ = %lf\n\n",phase);
    ans = do_solve(0.0, Pi/2.0, f_1, phase, error);
    printf("ans:\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, phase - ans,cos(ans)*cos(phase-ans));

	
	ans = do_solve(Pi/2.0, Pi, f_1, phase, error);
	printf("ans1:\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, phase - ans,cos(ans)*cos(phase-ans));


	printf("where : delta - phi = 11°43‘1’ = %lf\n\n",phase);
	ans = do_solve(0.0, Pi/2.0, f_2, phase, error);
	printf("ans:\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\\nn",
			ans, ans + phase, cos(ans)*cos(phase+ans));
	
	
	ans = do_solve(Pi/2.0, Pi, f_2, phase, error);
	printf("ans1\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, ans + phase, cos(ans)*cos(ans+phase));

	
	x[0] = 49.0;
	x[1] = 15.0;
	x[2] = 35.0;
	
	phase = D2R(x);
//	printf("phase = %lf\n\n\n",phase);
    printf("\n\nfigure : cos(delta)*cos(phi) = 0.6524\n");
	printf("where : delta + phi = 49°15‘35 = %lf’‘\n\n",phase);
    ans = do_solve(0.0, Pi/2.0, f_1_1, phase, error);
    printf("ans:\n    phi = %lf\n    delta = %lf\n\n",ans, phase - ans);

	
	ans = do_solve(Pi/2.0, Pi, f_1_1, phase, error);
	printf("ans1:\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, phase - ans,cos(ans)*cos(phase-ans));

	
	printf("where : delta - phi = 49°15‘35'' = %lf\n\n",phase);
	ans = do_solve(0.0, Pi/2.0, f_2_1, phase, error);
	printf("ans:\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, ans + phase,cos(ans)*cos(ans+phase));

	
	ans = do_solve(Pi/2.0, Pi, f_2_1, phase, error);
	printf("ans1\n    phi = %lf\n    delta = %lf\ncos(phi)*cos(delta) = %lf\n\n",
			ans, ans + phase,cos(ans)*cos(ans+phase));

}
