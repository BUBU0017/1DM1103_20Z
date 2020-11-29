DEPS = mymathlab.o wczytaj.o kalkulacje.o

mymathlab: $(DEPS)
	valgrind gcc $(DEPS) -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o
test:
	./mymathlab sum A.txt x.txt
