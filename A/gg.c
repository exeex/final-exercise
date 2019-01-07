#include <stdio.h>
#include <string.h>

float A[100][100];
float X[100];
float X_buf[100];
int case_number, n;

int print_a(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.3f ",A[i][j]);
        }
         printf("\n");
    }
}

int print_x(){
    int i;
    for(i=0;i<n;i++){
        printf("%.3f ",X[i]);

    }
}


int a_dot_x(){
    int i,j;
    for(i=0;i<n;i++){
        float row_sum=0;
        for(j=0;j<n;j++){
            row_sum+=A[i][j] * X[j];
//            printf("%.3f ",A[i][j]);
        }
        X_buf[i] = row_sum;
//        printf("\n");
    }
    memcpy(X, X_buf, sizeof(float)*n);

}



int main(){

    scanf("%d", &n);
//    printf("%d", n);

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%f",&A[i][j]);
        }
    }

    for(i=0;i<n;i++){
        scanf("%f",&X[i]);
    }

    print_a();

    printf("\n");
    print_x();

    for(i=0;i<10;i++){

        printf("\n=========\n");
        a_dot_x();
        print_x();
    }

}