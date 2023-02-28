PLATFORM = macos_universal2
TWOUP    = /Library/gurobi1001/$(PLATFORM)/lib
INC      = $(TWOUP)/../include/
CC       = gcc
CARGS    = -m64 -g
CLIB     = -L$(TWOUP)/../lib -lgurobi100
OBJS	= trp.o tsp_file.o util.o
SOURCE	= trp.c tsp_file.c util.c
HEADER	= tsp_file.h util.h
OUT	= trp

trp: $(OBJS)
	$(CC) $(CARGS) $(OBJS) -o $(OUT) -I$(INC) $(CLIB) -lm
	./$(OUT)

berlin52: $(OBJS)
	$(CC) $(CARGS) $(OBJS) -o $(OUT) -I$(INC) $(CLIB) -lm
	./$(OUT) berlin52.txt

eil101: $(OBJS)
	$(CC) $(CARGS) $(OBJS) -o $(OUT) -I$(INC) $(CLIB) -lm
	./$(OUT) eil101.txt

clean:
	rm -rf *.o $(OUT) *.log *.dSYM *.lp;