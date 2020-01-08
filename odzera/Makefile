

OBJS=main.o bibl.o

main: $(OBJS)
	cc $^ -Wall -o main


%.o: %.c 
	cc $< -c 

play: main
	./main dane

clean:
	rm -f main.o bibl.o alfabetaa.o main
