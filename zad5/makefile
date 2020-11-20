DEPS=main.o studenci.o dziekanat.o

main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

test:
	./main studenci.txt przedmioty

test2:
	./main studenci.txt student