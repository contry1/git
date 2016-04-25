#include <message.h>
#include <charger.h>
#include <pio.h>                /* Peripheral Input/Output */
#include <print.h>              /* debug PRINT */
 
#include "ex6.h"
 
#define DELAY 5000
#define NO_OF_PATTERNS  (2)
 
uint8 patterns[] = { BLUE_GREEN_RED_ALT};
uint8 count;
 
static void led_controller1( Task t, MessageId id, Message payload )
{
    PRINT(("Pattern No. %d\n", count ));
     
    ledsPlay( patterns[count] );
 
    count++;
    count %= NO_OF_PATTERNS;
     
    MessageSendLater( t, 0, 0, DELAY );
}
 
static TaskData led_controller1_task = { led_controller1 };
 
int main(void)
{

     
    MessageSend( &led_controller1_task, 0 , 0 );
    MessageLoop();
     
    return 0;
}
