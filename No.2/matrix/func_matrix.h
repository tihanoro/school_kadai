#include<stdio.h>
#include<stdlib.h>

double **arrayget(int row,int column);
void scan_matrix(double **p,int row,int column);
void multi_matrix(double **a,double **b,double **z,int L,int M ,int N);
void print_matrix(double **p,int row,int column);
void arrayfree(double **p,int column);
