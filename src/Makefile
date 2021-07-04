OBJS = shell.o tokenizer.o history.o

all:test



test: $(OBJS)

	cc -o test $(OBJS)



$(OBJS): tokenizer.h history.h



clean:

	-rm *.o

	-rm *~

	-rm test

run:test

	./test
