PLATFORM = macos_universal2
TWOUP    = /Library/gurobi1001/$(PLATFORM)/lib
INC      = $(TWOUP)/../include/
CC       = gcc
CARGS    = -m64 -g
CLIB     = -L$(TWOUP)/../lib -lgurobi100	

trp: trp.c
	$(CC) $(CARGS) -o $@ $< -I$(INC) $(CLIB) -lm
	./trp

clean:
	rm -rf *.o trp *.log *.dSYM *.lp;