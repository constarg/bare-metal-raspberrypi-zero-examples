# Bare Metal Raspberry PI Zero

The projects you will find here are about bare metal software development on a raspberry pi zero. They are small examples, which I make to learn myself how to write software for embedded systems.

# Installation requirements
The following packages must be installed.<br>
```
sudo apt-get install build-essential binutils-arm-none-eabi gcc-arm-none-eabi
```

# Download & Build

First download the program from GitHub and go to the bare-metal-raspberrypi-zero-examples folder.

```
% git clone https://github.com/EmbeddedCat/bare-metal-raspberrypi-zero-examples.git
% cd bare-metal-raspberrypi-zero-examples/
```

Each example has it's own Makefile. To compile the code and produce the binary file
for the raspberry pi zero, you must execute inside the folder of the specific example 
the folloing command in the terminal.

```
% make
```

# How to run it in raspberry pi
First of all, you need an SD card. This card should be in FAT format. Then you should copy 2 files inside your card. One file is called bootcode.bin and the second start.elf. After that, you can copy the file created by the Makefile, which will be called kernel.img and then you can put the card in your raspberry pi.<br>
The two necessary files,start.elf and bootcode.bin, can be found in the repository below<br>
`https://github.com/raspberrypi/firmware/tree/master/boot`
