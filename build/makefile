#Compiler
CC = g++

#Compiler flags
CFLAGS = -g -std=c++11

make:	../src/main.cpp ../include/Node.cpp ../include/AvlTree.cpp
	$(CC) -std=c++14 ../src/main.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o AVL
run:	AVL	
	./AVL
unittest:	../test/UnitTest0.cpp ../test/UnitTest1.cpp ../test/UnitTest2.cpp ../test/UnitTest3.cpp ../test/UnitTest4.cpp ../test/UnitTest5.cpp ../test/UnitTest6.cpp  
	$(CC) $(CFLAGS) ../test/UnitTest0.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest0
	$(CC) $(CFLAGS) ../test/UnitTest1.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest1
	$(CC) $(CFLAGS) ../test/UnitTest2.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest2
	$(CC) $(CFLAGS) ../test/UnitTest3.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest3
	$(CC) $(CFLAGS) ../test/UnitTest4.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest4
	$(CC) $(CFLAGS) ../test/UnitTest5.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest5
	$(CC) $(CFLAGS) ../test/UnitTest6.cpp ../include/Node.cpp ../include/AvlTree.cpp -o UnitTest6
run_unittest:	UnitTest0 UnitTest1 UnitTest2 UnitTest3 UnitTest4 UnitTest5 UnitTest6
	./UnitTest0
	./UnitTest1
	./UnitTest2
	./UnitTest3
	./UnitTest4
	./UnitTest5
	./UnitTest6

clean:
	rm AVL 	UnitTest0 UnitTest1 UnitTest2 UnitTest3 UnitTest4 UnitTest5 UnitTest6  
