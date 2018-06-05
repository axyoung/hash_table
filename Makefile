PROGRAM = main.exe
CXXFLAGS = -Wall -g

$(PROGRAM): main.o Node.o student.o hashTable.o
	g++ -o $@ $^

clean:
	rm -f $(PROGRAM) *.o

run: $(PROGRAM)
	./$(PROGRAM)

main.o: main.cpp Node.h student.h hashTable.h
Node.o: Node.h Node.cpp student.h
student.o: student.cpp Node.h student.h
hashTable.o: Node.h student.h hashTable.h
