/*
 * =====================================================================================
 *
 *       Filename:  101.c
 *
 *    Description:  For Online Judge Volume I problem 101
 *                  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37
 *
 *        Version:  1.0
 *        Created:  03/16/2013 16:51:08
 *         Status:  Accepted
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edison Wang (edison), jawwang1129@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int blocks[25][25];

void init_blocks(int max){
    int i,j;
    for ( i=0;i<max;i++) {
        blocks[i][0]=i;
		for(j=1;j<max;j++){
			blocks[i][j]=-1;
		}
    }
}

void output_blocks(int max){
    int i,j;
    for (i=0;i<max;i++) {
        printf("%d:", i);
        for (j=0;j<max;j++) {
            if (blocks[i][j]!=-1){
                printf(" %d",blocks[i][j]);
            }
        }
        printf("\n");
    }
}

void findblocks(int* blockfrom, int* blockto,int from, int to,int max){
	int i,j;
	for(i=0;i<max;i++){
		if(blocks[i][0]==-1){
			continue;   
		}
		for(j=0;j<max;j++){
			if(blocks[i][j] == from){
				blockfrom[0]=i;
				blockfrom[1]=j;
			}
			if(blocks[i][j]== to){
				blockto[0]=i;
				blockto[1]=j;
			}
		}
	}

}

void action(char* first, char* second,int from, int to, int max){
	int i,blockfrom[2],blockto[2];
	findblocks(blockfrom,blockto,from,to,max);
	if (strcmp(first,"move") == 0){
		int count =1;
		while(blocks[blockfrom[0]][blockfrom[1]+count] != -1){
			blocks[blocks[blockfrom[0]][blockfrom[1]+count]][0]=blocks[blockfrom[0]][blockfrom[1]+count];
			blocks[blockfrom[0]][blockfrom[1]+count]=-1;
			count ++;
		}
	}
	if(strcmp(second,"onto")== 0){
		int count =1;
		while(blocks[blockto[0]][blockto[1]+count] != -1){
		blocks[blocks[blockto[0]][blockto[1]+count]][0]=blocks[blockto[0]][blockto[1]+count];
		blocks[blockto[0]][blockto[1]+count]=-1;
		count++;
		}
		count = 0;
		while(blocks[blockfrom[0]][blockfrom[1]+count] != -1){
			blocks[blockto[0]][blockto[1]+count+1]=blocks[blockfrom[0]][blockfrom[1]+count];
			blocks[blockfrom[0]][blockfrom[1]+count] = -1;
			count++;
		}
	}
	if(strcmp(second,"over") == 0){
		int end=1,count;
		while(blocks[blockto[0]][blockto[1]+end] != -1){
			end++;
		}
		count = 0;
		while(blocks[blockfrom[0]][blockfrom[1]+count] != -1){
			blocks[blockto[0]][blockto[1]+count+end]=blocks[blockfrom[0]][blockfrom[1]+count];
			blocks[blockfrom[0]][blockfrom[1]+count] = -1;
			count++;
		}


	}
}

int checkvalid(from,to,max){
	int i,j,flag=0;
	if(from == to){
		return 0;
	}
	for(i=0;i<max;i++){
		flag = 0;
		for(j=0;j<max;j++){
			if(blocks[i][j]== -1){
				break;
			}
			if (((blocks[i][j]==from)||(blocks[i][j]==to))&&(flag == 1)){
				return 0;
			}else if ((blocks[i][j]==from)||(blocks[i][j]==to)){
				flag = 1;
			}
		}
	}
	return 1;
}

int main(){
	char command[20],first[5],second[5];
	char *temp,*buf;
	int max,from,to;
	void (*func)(int, int, int);
	scanf("%d", &max);
	getchar();
	init_blocks(max);
	while(1){
		fgets(command,20,stdin);
		buf = command;
		if (strcmp(buf,"quit\n") == 0){
			break;
		}
		sscanf(buf,"%s %d %s %d", first, &from, second, &to);
		if(!checkvalid(from,to,max)){
			continue;
		}
		action(first, second, from, to, max);
	}
	output_blocks(max);
	return 0;
}

