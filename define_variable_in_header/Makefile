CFLAGS=-g -Werror
TOP_PATH = $(shell pwd)
CC=gcc
INC := $(TOP_PATH)/include
SRC := $(TOP_PATH)src
SRCS := $(TOP_PATH)/src/*.c
VPATH :=$(INC) $(SRC)
GPATH := $(TOP_PATH)/out

PROG=demoIncludeVar
all: $(PROG)

demoIncludeVar: $(SRCS)
	@echo $(TOP_PATH)
	@$(CC) $(CFLAGS) -I$(INC) -o $(GPATH)/demoIncludeVar  $(SRCS)
	@echo "Target FIle ==> $(GPATH)/demoIncludeVar"

#%.o: %.c 
#	@echo $(TOP_PATH)
#	@$(CC) $(CFLAGS) -o $@ $<

.PHONEY:
run:
	$(TOP_PATH)/out/demoIncludeVar
clean:
	@echo $(TOP_PATH)
	rm -f *.o *~ $(GPATH)/demoIncludeVar
