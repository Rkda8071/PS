#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

//Direct Sampling
int try_N = 5000, count = 0;

int main() {
   srand((unsigned)time(NULL));
   float x, y;
   for (int j = 1; j <= 5; j++) {
      for (int i = 1; i <= try_N; i++) {
         x = rand() / RAND_MAX;
         x *= pow(-1, rand());
         y = rand() / RAND_MAX;
         y *= pow(-1, rand());
         
         if (x * x + y * y <= 1) count++;
      }
      printf("%.3f\n", (float)count / try_N);
   }
}

//x*x+y*y가 1 미만이면 성립