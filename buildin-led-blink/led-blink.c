/**
 * @file led-bink.c
 * @device RaspberryPI zero W 1.1v
 * @CPU BMC2835
 * @author EmbeddedCat
 *
 * RaspberryPI zero - builtin led blink
 * example.
 */

// For better reading
// reg32 type represent a register of 32 - bits.
typedef unsigned int reg32;

// base address for the GPIO.
#define GPIO_BASE 0x20200000UL

// The address for the select function register.
#define GPIO_FSEL4_REG (GPIO_BASE + (sizeof(reg32) * 0x4U))
// The address for the set register.
#define GPIO_SET1_REG  (GPIO_BASE + (sizeof(reg32) * 0x8U))
// The address for the clear register.
#define GPIO_CLR1_REG  (GPIO_BASE + (sizeof(reg32) * 0xBU))

#define LED_SEL (1U << 0x15U) // Set led to output mode. 
#define LED_OP  (1U << 0xFU) // The bit that must be "on" to turn off or on the led. 


#define INIT_LED()                          \
    *((volatile reg32 *)                    \
            GPIO_FSEL4_REG) &= ~LED_SEL;    \
    *((volatile reg32 *)                    \
            GPIO_FSEL4_REG) |= LED_SEL    

#define TURN_LED_ON()                       \
    *((volatile reg32 *)                    \
            GPIO_CLR1_REG) = LED_OP

#define TURN_LED_OFF()                      \
    *((volatile reg32 *)                    \
            GPIO_SET1_REG) = LED_OP 


int main(void)
{
    INIT_LED();

    volatile int i;

    while(1)
    {
        for(i = 0; i < 500000; i++);
        TURN_LED_ON();
        for(i = 0; i < 500000; i++);
        TURN_LED_OFF();
    }
}

