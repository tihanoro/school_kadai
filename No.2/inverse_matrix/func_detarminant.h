#include<stdio.h>
#include<stdlib.h>
double dat(double **a, int n);
double laplace(double **a, int n, int row, int colmn);
double min_dat(double **a, int n, int row, int colmn);
double **min_matrix(double **a, int n, int row, int colmn);
double **arrayget(int row,int column);
void scan_matrix(double **p,int row,int column);
void print_matrix(double **p,int row,int column);
void arrayfree(double **p,int column);
