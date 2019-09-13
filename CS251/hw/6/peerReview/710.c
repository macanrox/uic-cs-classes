#include "gw.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct gw_struct{
    int popl;

    struct DISTRICTS **districts;
    struct PEOPLE *directory,*recycle;
};

typedef struct gw_districts {
    int popl;
    struct PEOPLE *top;
    struct PEOPLE *peepl;
}DISTRICTS;

typedef struct people  {
    int alive, ID, i, j;

    struct PEOPLE *next, *prev;
}PEOPLE;

GW gw_build(int nrows, int ncols, int pop, int rnd){
    GW g = malloc(sizeof(GW));
    g->popl = pop;
    int i, j;

    g->districts = malloc(nrows*sizeof(DISTRICTS));
    for (i=0; i<nrows;i++){
        g->districts[i] = malloc(ncols*sizeof(DISTRICTS));
            for(j=0;j<ncols;j++){
                g->districts[i][j] = malloc(sizeof(DISTRICTS));
                g->districts[i][j].popl = 0;
                g->districts[i][j]->top = NULL;
                g->districts[i][j]->peepl = NULL;
            }
    }
    g->districts = districts;

    g->directory = (PEOPLE *)malloc(pop*sizeof(PEOPLE));


    if (rnd == 1){
        int irand, jrand;
        for (i=0;i<pop;i++){
            srand(time(NULL));
            irand = rand() % nrows;
            jrand = rand() % ncols;
            PEOPLE member = g->districts[irand][jrand].peepl;
            districts[irand][jrand].top = member;
            member->next = NULL;
            member->prev = NULL;
            member->ID = i;
            member->i = irand;
            member->j = jrand;
            member->alive = 1;
        }
    }
    if (rnd == 0){
            for (i=0;i<pop;i++){
            srand(time(NULL));
            irand = rand() % nrows;
            jrand = rand() % ncols;
            PEOPLE *member = *g->districts[0][0].peepl;
            districts[0][0].top = member;
            member->next = NULL;
            member->prev = NULL;
            member->ID = i;
            member->i = 0;
            member->j = 0;
            member->alive = 1;
        }
    }
    return g;
}

int *gw_members(GW g, int i, int j, int *n){
    if (g->districts[i][j].popl == 0){
        print ("district empty, or non existent");
        return NULL;
    }
    int k;
    int n[popl];
    for (k=0;k<g->districts[i][j].popl; k++){
        n[j]=g->districts[i][j]->peepl->ID;
        g->districts[i][j]->peepl->peepl = g->districts[i][j]->peepl->next;
    }
    return n;
}

int gw_district_pop(GW g, int i, int j){
    return g->districts[i][j]->popl;
}

int gw_total_pop(GW g){
    return g->popl;
}

int gw_move(GW g, int x, int i, int j){
    if(!g->directory[x]->alive){
        printf("No such person is currently alive");
        return 0;
    }
    else
        g->districts[i][j]->top->next = g->directory[x];
        g->directory[x]->prev->next = g->directory[x]->next;
        g->directory[x]->next->prev = g->directory[x]->prev;
        g->directory[x]->prev = g->districts[i][j]->top;
        g->districts[i][j]->top = g->directory[x];
    return 1;
}

int gw_find(GW g, int x, int *r, int *c){
    if(!g->directory[x]->alive){
        printf("No such person is currently alive");
        return 0;
    }
    else
        r = g->directory[x]->i;
        c = g->directory[x]->j;
        return 1;
}

int GW_kill(GW g, int x){
    if(!g->directory[x]->alive){
        printf("No such person is currently alive");
        return 0;
    }
    else
        g->recycle->next = g->directory[x];
        g->directory[x]->prev->next = g->directory[x]->next;
        g->directory[x]->next->prev = g->directory[x]->prev;
        g->directory[x]->prev = g->recycle;
        g->recycle = g->directory[x];
        return 1;
}

int gw_create(GW g, int i, int j){
    if(g->districts[i][j]==NULL) return -1;
    g->popl += 1;
    g->districts[i][j]->popl += 1;
    if (g->recycle->next != NULL){
        int x;
        x = g->recycle->ID;
        g->recycle->prev->next = g->recycle->next;
        g->recycle->next->prev = g->recycle->prev;
        g->directory[x]->next = NULL;
        g->directory[x]->prev = g->districts[i][j]->top;
        g->districts[i][j]->top->next = g->directory[x];
        g->directory[x] = g->districts[i][j]->top;
    }
    return g->directory[x]->ID;
}

void gw_free(GW g){
    free (g);
    return;
}
