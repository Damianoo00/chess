

OBJS=main.o bibl.o

main: $(OBJS)
	cc $^ -Wall -o main



%.o: %.c 
	cc $< -c 

test: main
	./main ../../L06/dane
