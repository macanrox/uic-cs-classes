#include "gw.h"
#include <stdlib.h>
#include <stdio.h>

struct gw_struct{
    int** world;
    int population;
    int x;
    int y;
    struct gw_struct *prev;
    struct gw_struct *next;
};



GW gw_build(int nrows, int ncols, int pop, int rnd){

    int i;

    struct gw_struct * newGrid = malloc(sizeof(struct gw_struct));
    newGrid->world = (int**)malloc(nrows * sizeof(int*));
    for (i = 0; i< ncols; i++){
        newGrid->world[i] = (int*)malloc(ncols * sizeof(int));
    }
    newGrid->x = nrows;
    newGrid->y = ncols;
    return newGrid;
}

int * gw_members(GW g, int i, int j, int *n){


    int a;
    int b;
    if(g->next == NULL){
        return -1;
    }
    else{
        for (a = 0; a < i; a++){
            for ( b = 0; b < j; b++){
                if(g->world[i][j] == 1 || 0){
                    n++;
                }
            }
        }
    }
    return *n;
}

int gw_district_pop(GW g, int i, int j){
    int a,b, count;

    for (a = 0; a < i; a++){
        for (b = 0; b < i; b++){
            count++;
        }
    }

    return count;
}

int gw_total_pop(GW g){

    int a,b,count;

    if (g->next == NULL){
        return 0;
    }

    while(g->next){
            for (a = 0; a < g->x; a++){
                for (b = 0; b < g->y; b++){
                    count++;
                }
            }
    }

    return count;
}

int gw_move(GW g, int x, int i, int j){

    if (x == 1){

        return 1;
    }
    else return 0;

}

int gw_find(GW g, int x, int *r, int *c){
    int i, j;
    for(i = 0; i< g->x; i++){
        for (j = 0; j< g->y; j++){
            if (x == g->world[i][j]){
                r = i;
                c = j;
                return 1;
            }
        }
    }

}

int gw_kill(GW g, int x){
    int i, j;
    for(i = 0; i< g->x; i++){
        for (j = 0; j< g->y; j++){
            if (x == g->world[i][j]){
                g->world[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;

}

int gw_create(GW g, int i, int j){

    if (g->world[i][j] == NULL){
        return 0;
    }

    g->world[i][j] = 1;


}

void gw_free(GW g){
    struct gw_struct * current = g;
    while( current != NULL ) {
    GW* next = current->next;
    free( current );
    current = next;
}
}
