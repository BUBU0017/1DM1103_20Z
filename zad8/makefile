all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ilestud: all
	./mydb baza.csv count_students

test-ileprzed: all
	./mydb baza.csv count_courses

test-memory: all
	valgrind --leak-check=full ./mydb baza.csv list students 

test-dodajucznia: all
	./mydb baza.csv add_student Zdzisiek Trzeci 55555 krol@bog.pl

test-dodajprzed: all
	./mydb baza.csv add_course 1DH8878 Dakar 2020Z
	
test-dodajuczniadoprzed: all
	./mydb baza.csv add_student_to_course 1DH8878 55555 5.0 Najs

test-sortuj-stud-malejaco: all
	./mydb baza.csv sortuj_malejaco

test-sortuj-stud-rosnaco: all
	./mydb baza.csv sortuj_rosnaco

test-sort-przed-po-kodzie: all
	./mydb baza.csv sortuj_po_kodzie

test-sort-przed-po-nazwie: all
	./mydb baza.csv sortuj_po_nazwie

test-filtruj_przedmiot: all
	./mydb baza.csv filtruj_przedmiot 1DX1121

test-filtruj_ucznia: all
	./mydb baza.csv filtruj_ucznia 22222

