#include <kipr/wombat.h>
#include <math.h>

void set_servos(int s0_pos)
{
    //int s1_pos = round(((27*s0_pos)/28)-54);
    int s1_pos = (s0_pos - 500);
    set_servo_position(0, s0_pos);
    set_servo_position(1, s1_pos);
}

int main()
{
    int claw_open = 1500;
    int claw_closed = 950;
    int claw_servo = 2;
    int base_servo = 0;
    int wrist_servo = 1;
    int r1pos = 1685;
    int r2pos = 1700;
    int r3pos = 1925;
    int carrying_pos = 1000;
    
    set_servos(r2pos);
    enable_servos();
    set_servo_position(claw_servo, claw_open);
    msleep(2000);
    while (analog(4)<1600)
    {
        mav(0, 250);
   		mav(1, 250);
        printf("sensor reads %d\n",analog(4));
        msleep(100);
    }
    ao();
    set_servo_position(claw_servo, claw_closed);
    msleep(2000);
    set_servos(carrying_pos);
    msleep(2000);
    mav(0, -400);
    mav(1, -400);
    msleep(10000);
    ao();
    while (analog(3)<3000)
    {
    mav(0, -400);
    mav(1, -400);
    msleep(200);
    }
    ao();
    disable_servos();
    return 0;
}