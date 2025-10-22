objects = writer.o

all: $(objects)
	$(CROSS_COMPILE)gcc $^ -o writer

writer.o:
	$(CROSS_COMPILE)gcc -c writer.c -o writer.o

clean:
	rm -f *.o writer
