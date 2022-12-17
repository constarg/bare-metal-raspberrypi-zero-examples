/**
 * RaspberryPI zero - builtin led blink
 * example.
 *
 * @Author EmbeddedCat
 */

// base address for the GPIO.
#define GPIO_BASE       0x20200000UL

// The address for the select function register.
#define GPIO_FSEL4_REG (GPIO_BASE + (sizeof(int) * 0x4))
// The address for the set register.
#define GPIO_SET1_REG  (GPIO_BASE + (sizeof(int) * 0x8))
// The address for the clear register.
#define GPIO_CLR1_REG  (GPIO_BASE + (sizeof(int) * 0xB))

#define LED_SEL (1 << 0x15) // Set led to output mode.
#define LED_OP  (1 << 0xF) // The bit that must be "on" to turn off or on the led.


#define INIT_LED()                          \
    *((volatile unsigned int *)             \
            GPIO_FSEL4_REG) &= ~LED_SEL;    \
    *((volatile unsigned int *)             \
            GPIO_FSEL4_REG) |= LED_SEL    

#define TURN_LED_ON()                       \
    *((volatile unsigned int *)             \
            GPIO_CLR1_REG) = LED_OP

#define TURN_LED_OFF()                      \
    *((volatile unsigned int *)             \
            GPIO_SET1_REG) = LED_OP 


int main(void)
{
    INIT_LED();

    volatile int i;

    /* Never exit as there is no OS to exit to! */
    while(1)
    {
        for(i = 0; i < 500000; i++);
        TURN_LED_ON();
        for(i = 0; i < 500000; i++);
        TURN_LED_OFF();
    }
}

