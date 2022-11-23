#include "mbed.h"
#include "platform/mbed_thread.h"

DigitalIn Button(USER_BUTTON);    //PC_13
Serial Comp(USBTX,USBRX);

int main()
{
    int count = 0;
    while(1) {

        if(Button ==1) {
		printf("|");
	} else{
		printf("0");
	}
    }

}
