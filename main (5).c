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
    int r2pos = 1750;
    int r3pos = 1925;
    int carrying_pos = 1000;
    int rspeed = 500;
    int lspeed = 520;
    
    set_servos(r2pos);
    enable_servos();
    set_servo_position(claw_servo, claw_open);
    msleep(2000);
    while (analog(4)<1400)
    {
        mav(0, 250);
   		mav(1, 250);
        printf("sensor reads %d\n",analog(4));
        msleep(100);
    }
    ao();
    set_servo_position(claw_servo, claw_closed);
    msleep(2000);
    int i = r2pos;
    while (i>carrying_pos){
    	set_servos(i);
        i-=5;
        msleep(10);
    }
    msleep(1000);
    set_servo_position(wrist_servo, 600);
    msleep(1000);
    mav(0, (-1)*rspeed);
    mav(1, (-1)*lspeed);
    msleep(10000);
    ao();
    while (analog(3)<2800)
    {
    mav(0, (-1)*rspeed);
    mav(1, (-1)*lspeed);
    msleep(200);
    }
    ao();
    mav(0, (-1)*rspeed);
    mav(1, (-1)*lspeed);
    msleep(1000);
    ao();
    set_servos(600);
    set_servo_position(wrist_servo, 150);
    mav(0, 300);
    mav(1,-500);
    msleep(3760);
    ao();
    set_servo_position(wrist_servo, 250);
    msleep(1000);
     while (analog(4)<2050)
    {
        mav(0, 250);
   		mav(1, 250);
        printf("sensor reads %d\n",analog(4));
        msleep(100);
    }
    ao();
    set_servo_position(claw_servo, claw_open);
    msleep(2000);
    mav(0, -100);
   	mav(1, -100);
    msleep(4000);
    ao();
    disable_servos();
    return 0;
}