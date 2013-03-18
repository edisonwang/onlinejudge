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
 *         Status:  Unfinished
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
        printf("%d :", i);
        for (j=0;j<max;j++) {
            if (blocks[i][j]!=-1){
                printf(" %d",blocks[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    char command[20],first[5],second[5];
    char *temp,*buf;
    int max,from,to;
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
        if (strcmp(first,"move")==0){
            printf("%s\n","isMove");
        }
        if (strcmp(first,"pipe")==0){
            printf("%s\n","isPipe");
        }
        if (strcmp(second,"onto")==0){
            printf("%s\n","isOnto");
        }
        if (strcmp(second,"over")==0){
            printf("%s\n","isOver");
    	}
	}
    output_blocks(max);
    return 0;
}

