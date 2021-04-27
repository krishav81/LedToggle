/*
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Setting the Direction of Ports
    DDRB|=(1<<PB1);
    DDRD&=~(1<<PD0);
    DDRD&=~(1<<PD4);

    // Setting PORTD pins
    PORTD|=(1<<PD0);
    PORTD|=(1<<PD4);


    while(1)
    {
        if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD4)))
        {
            PORTB|=(1<<PB1);
            _delay_ms(1000);
        }
        else
        {
            PORTB&=~(1<<PB1);
            _delay_ms(1000);
        }
    }
    return 0;
}
