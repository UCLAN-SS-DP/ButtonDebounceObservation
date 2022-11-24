#include "mbed.h"
#include "platform/mbed_thread.h"

bool ButtonDebounce();
bool flag = 0;
Ticker Five_ms;
Timer t;
DigitalIn Button(USER_BUTTON);    //PC_13
Serial Comp(USBTX,USBRX);


void DebounceCheck(void)
{
    static uint16_t State = 0; // Current debounce status
    State=(State<<1) | Button.read() ;//| 0xe000;
    if(State==0xf000) {
        flag = 1;
        Five_ms.detach();
        
    }

}

int main()
{
    int count = 0;
    while(1) {

        if(Button!=1) {
            flag=0;
            Five_ms.attach_us(&DebounceCheck, 4);
            if(flag==1) {
                count++;
                printf("Number of pressings so far: %d \r\n",count);
            }
        }
    }

}
