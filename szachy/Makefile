

OBJS=main.o bibl.o

main: $(OBJS)
	cc $^ -Wall -o main


%.o: %.c 
	cc $< -c 

test: main
	./main dane

clean:
	rm -f bibl.o main.o main
