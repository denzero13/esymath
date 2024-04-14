#include <libcalc.h>
#include <math.h>

int square_root(int num) {
     if (num < 0) {
         return 0;
     }

     return sqrt(num);
}
