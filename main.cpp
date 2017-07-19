/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anirudh
 *
 * Created on 14 July, 2017, 6:17 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <limits.h>
using namespace std;

int search_max(float *pw,int n){
    float max = INT_MIN;int k;
    for (int i=1;i<=n;i++){
        if (pw[i]>max) {
            max=pw[i];
            k = i;
        } 
    }
    pw[k]=NULL;  
    return k;
}

void knapsack(){
    int n; float m; scanf("%d\n%f",&n,&m);
    float *profit = (float *)malloc((n+1)*sizeof(float));
    float *weight = (float *)malloc((n+1)*sizeof(float));
    float *pw =    (float *)malloc((n+1)*sizeof(float));
    float *solution = (float *)malloc((n+1)*sizeof(float));
    for (int i=1;i<=n;i++){
        scanf("%f",&profit[i]);
        scanf("%f",&weight[i]);
        pw[i]=(profit[i]/weight[i]);
        solution[i]=0;
    }
    float max_profit=0.f;static int i;int p;
    for (i=1;i<=n;i++){
        p = search_max(pw,n);
        if (weight[p]>m)break;
        solution[p]=1;
        max_profit=max_profit+profit[p];
        m=m-weight[p];
      }
    if (i<=n){ 
        solution[p]=(m/weight[p]);
        max_profit=max_profit+(solution[p]*profit[p]);
    }
    for (int j=1;j<=n;j++) printf("%f\t",solution[j]);
    printf("\n%f",max_profit);
    free(profit);
    free(weight);
    free(pw);
    free(solution);
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    knapsack();
    return 0;
}

