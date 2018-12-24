obj-m += lnxkrnlmod.o lnxkrnlmod2.o lnxkrnlmod_dev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	-rmmod lnxkrnlmod2
	-rmmod lnxkrnlmod
	modinfo lnxkrnlmod.ko
	insmod lnxkrnlmod.ko
	insmod lnxkrnlmod2.ko
	@dmesg | tail | grep lnxkrnlmod | tail -n3
	@lsmod | head -n1
	@lsmod | grep lnxkrnlmod
	rmmod lnxkrnlmod2
	rmmod lnxkrnlmod
