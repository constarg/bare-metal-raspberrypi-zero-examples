

cc_flags=-nostartfiles -mfloat-abi=hard -mfpu=vfp -march=armv6zk -mcpu=arm1176jzf-s 

all:
	arm-none-eabi-gcc ${cc_flags} led-blink.c -o led-blink.elf
	arm-none-eabi-objcopy led-blink.elf -O binary kernel.img
