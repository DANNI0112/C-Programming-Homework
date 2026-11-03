#include <stdio.h>//注意审题，到底几位数字
int main(){
	char id[18]={0};
	scanf("%s",id);
	int arr[18]={0};
	for(int i=0;i<18;i++){
		if(id[i]=='X'||id[i]=='x'){
			arr[i]=10;
		}
		else{
			arr[i]=id[i]-'1'+1;
		}
	}
	int sum=7*arr[0]+9*arr[1]+10*arr[2]+5*arr[3]+8*arr[4]+4*arr[5]+2*arr[6]+1*arr[7]+6*arr[8]+3*arr[9]+7*arr[10]+9*arr[11]+10*arr[12]+5*arr[13]+8*arr[14]+4*arr[15]+2*arr[16];
	int num=-1;
	if(sum%11>=2){
		num=12-(sum%11);
	}
	else{
		num=1-(sum%11);
	}
	if(num!=arr[17]){
		printf("False ID");
		return 0;
	}
	int year=arr[6]*1000+arr[7]*100+arr[8]*10+arr[9];
	if(year>2022||year<1900){
		printf("False ID");
		return 0;
	}
	int month=arr[10]*10+arr[11];
	if(month>12||month<1){
		printf("False ID");
		return 0;
	}
	int day=arr[12]*10+arr[13];
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day<1||day>31){
			printf("False ID");
		    return 0;
		}
	}
	else if(month==4||month==6||month==9||month==11){
	    if(day<1||day>30){
	    	printf("False ID");
		    return 0;
		}
	}
	else{
		if(year%100!=0&&year%4==0||year%400==0){
			if(day<1||day>29){
	        	printf("False ID");
		        return 0;
		    }
		}
		else{
			if(day<1||day>28){
	        	printf("False ID");
		        return 0;
		    }
		}
	}
	printf("True ID");
	return 0;
}
