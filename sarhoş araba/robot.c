#include<16f877.h>
#define sag  pin_b0
#define orta pin_b1
#define sol  pin_b2
#fuses nowdt,xt
#use delay(clock=4000000)

int16 pwm1=0,pwm2=0;
int8 x;
void main()
{
    output_low(pin_c2);
    output_low(pin_c1);
    setup_timer_2(T2_DIV_BY_4,249,1);
    setup_ccp1(ccp_pwm);
    setup_ccp2(ccp_pwm);
    x = 0;
}


