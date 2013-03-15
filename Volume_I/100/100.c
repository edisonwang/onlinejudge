/* 100 - The 3n + 1 problem */
#include <stdio.h>

int main (){
	unsigned  i,j,a,n,count,max,large,small;
	while (2 == scanf("%d %d", &i ,&j)){
		large = i > j ? i : j;
		small = i >= j ? j : i;
	    max = 0;
		for (a=small;a<=large;a++){
			count = 0;
			n = a;
			while (n != 1 ){
				count ++;
				if ( (n%2) == 1){
					n = (3*n) +1;
				}else{
					n = n/2;
				}		
			}
			count++;
			if (count > max)
				max = count;
		}
		printf ("%d %d %d\n", i, j, max);
	}
	return 0;
}

