#include <stdio.h>

float subtract(float in1, float in2) {
    float ret = 0.0;
    asm ("fsubr %2, %0" : "=%t"(ret) : "%0"(in1), "u"(in2));
    return ret;
}

int main()
{
    float ret = subtract(1.0, 0.5);
    printf("result: %f\n", ret);
    return 0;
}
