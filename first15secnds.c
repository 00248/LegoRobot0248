#include <kipr/wombat.h>
#include <math.h>

void set_servos(int s0_pos)
{
    int s1_pos = (s0_pos - 500);
    set_servo_position(0, s0_pos);
    set_servo_position(1, s1_pos);
}

int main()
{
    int claw_open = 1500;
    int claw_closed = 800;
    int claw_servo = 2;
    int base_servo = 0;
    int wrist_servo = 1;
    int r1pos = 1685;
    int r2pos = 1845
    int r3pos = 1925;
    int carrying_pos = 600;
    
    set_servos(r1pos);
    enable_servos();
    set_servo_position(claw_servo, claw_closed);
    msleep(500);
    set_servos(carrying_pos);
    msleep(1000);
    mav(0, -500);
    mav(1, -500);
    msleep(2000);
    ao();
    disable_servos();
    return 0;
}