all: gtk.c helper
	gcc-10 gtk.c helper.o -o gtk `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

helper: helper.c
	gcc-10 helper.c -c

clean: 
	rm gtk helper.o
