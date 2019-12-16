test:main.o fileoperate.o menu.o
	gcc main.o fileoperate.o menu.o -o test
main.o:main.c
	gcc main.c -c
fileoperate.o:fileoperate.c
	gcc fileoperate.c -c
menu.o:menu.c
	gcc menu.c -c
clean:
	rm -f *.o
