#include <kipr/wombat.h>
#include <math.h>

int get_s1(int s0_pos)
{
    return round(((27*s0_pos)/28)-54);
}

int main()
{
    int i = 180;
    set_servo_position(0, i);
    set_servo_position(1, get_s1(i));
    enable_servos();
    msleep(2000);
    while(i <= 1300)
    {
    	
        printf("\ns0 position:%d\n", i);
        printf("s1 position:%d\n", j);
        set_servo_position(0, i);
    	set_servo_position(1, get_s1(i));
        msleep(10);
        i += 2;
    }
    disable_servos();
    return 0;
}

