#include <stdio.h>
#include <math.h>

int a[100000];

int one_hot[32];
int main(){

     // init one_hot
     for(int i=0;i<32;i++){
        one_hot[i] = pow(2, 30-i);
    }

//    for(int i=0;i<22;i++){
//        printf("%d!\n", one_hot[i]);
//    }

    // read data
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }




    int big_buf =0;
    int sum =0;

    for(int i=0;i<32;i++){
        int buf =0;
        for(int j=0;j<n;j++){
           if(a[j] & one_hot[i]) buf+=1;
        }
        if(buf>=n/2) big_buf += pow(2, 30-i);
    //    else printf("0");
//        printf("%d",buf);
    }


//    printf("big_buf: %d\n", big_buf);
    //printf("%d", one_hot[20] & a[0]);

    for(int j=0;j<n;j++){
//       printf("%d\n",a[j]);
       sum += a[j] ^ big_buf;
    }
    printf("%d\n",sum);


}


