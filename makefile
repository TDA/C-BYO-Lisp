# ledit needed for using readline and history
CFLAGS=-std=c99 -Wall -g -ledit
run:
	#gcc-4.9 ${CFLAGS} $(1).c -o $(1).out
	cc ${CFLAGS} $(1).c -o $(1)
	-./$(1)

val:
	gcc-4.9 ${CFLAGS} $(1).c -o $(1).out
	valgrind ./$(1).out --track-origins=yes

clean:
	rm -rf $(1).out*
	rm -rf $(1).dSYM*

git:
	make clean "$(1)"
	gg.sh "$(2)"
