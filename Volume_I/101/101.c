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
    for ( i=0;i<max;i++){
        blocks[i][0]=i;
        for( j=1;j<25;j++){
            blocks[i][j]=i+j;
        }
    }
}

void output_blocks(int max){
    int i,j;
    for (i=0;i<max;i++){
        printf("%d :", i);
        for (j=0;j<max;j++){
            if (blocks[i][j]!=-1){
                printf(" %d",blocks[i][j]);
            }
        }
        printf("\n");
    }
}

int isMove(char *buf){
    return ((strstr(buf,"move")) != NULL);
}

int isPipe(char *buf){
    return ((strstr(buf,"pipe")) != NULL);
}

int isOnto(char *buf){
    return ((strstr(buf,"onto")) != NULL);
}

int isOver(char *buf){
    return ((strstr(buf,"over")) != NULL);
}

int main(){
    char command[20];
    char *temp,*buf;
    int max;
    scanf("%d", &max);
    init_blocks(max);
    while(1){
        scanf("%s", command);
        buf = command;
        if (strcmp(buf,"quit") == 0){
            break;
        }
        if (isMove(buf)){
            printf("%s\n","isMove");
        }
        if (isPipe(buf)){
            printf("%s\n","isPipe");
        }
        if (isOnto(buf)){
            printf("%s\n","isOnto");
        }
        if (isOver(buf)){
            printf("%s\n","isOver");
        }

    }
    output_blocks(max);
    return 0;
}

