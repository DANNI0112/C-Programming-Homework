#include <stdio.h>
int main(){
	int AQI;
	scanf("%d",&AQI);
	if (AQI<=50&&AQI>0)
	    {
		printf("Excellent");
	}
	else if(AQI<=100&&AQI>0)
	    {
		printf("Good");
	}
	else if(AQI<=150&&AQI>0)
	    {
		printf("Lightly polluted");
	}
	else if(AQI<=200&&AQI>0)
	    {
		printf("Moderately polluted");
	}
	else if(AQI<=300&&AQI>0)
	    {
		printf("Heavily polluted");
	}
	else if(AQI<=500&&AQI>0)
	    {
		printf("Severely polluted");
	}
	else
	    {
		printf("Invalid input");
	}
	return 0;
}
