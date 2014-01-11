# this is for hello world

OBJ_NAME := scclass

ifneq ($(KERNELRELEASE),)
obj-m := $(OBJ_NAME).o
else
#KDIR := /home/cjok/arm6410/linux-2.6.32.36
#KDIR := /home/cjok/arm6410/linux-2.6.36.4
KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .scbus*
endif
