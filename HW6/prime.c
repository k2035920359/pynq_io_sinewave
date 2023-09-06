#include <stdio.h>
#include <stdlib.h>
#include"prime.h"

int IsPrime(int num)
{
    int fct=0;
    int i;
    
    for(i=1;i<=num;i++){
        if(num%i==0){
            fct++;
        }
    }
    if(fct==2){ 
        return 1;
    }
    else{
		return 0;
    }
}


