make:	../src/main.cpp ../include/Node.cpp ../include/AvlTree.cpp
	g++ -std=c++14 ../src/main.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o AVL
run:	AVL	
	./AVL
unittest:	../test/UnitTest0.cpp ../test/UnitTest1.cpp ../test/UnitTest2.cpp ../test/UnitTest3.cpp ../test/UnitTest4.cpp ../test/UnitTest5.cpp ../test/UnitTest6.cpp  
	g++ -std=c++14 ../test/UnitTest0.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest0
	g++ -std=c++14 ../test/UnitTest1.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest1
	g++ -std=c++14 ../test/UnitTest2.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest2
	g++ -std=c++14 ../test/UnitTest3.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest3
	g++ -std=c++14 ../test/UnitTest4.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest4
	g++ -std=c++14 ../test/UnitTest5.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest5
	g++ -std=c++14 ../test/UnitTest6.cpp ../include/Node.cpp ../include/AvlTree.cpp -g -o UnitTest6
run_unittest:	UnitTest0 UnitTest1 UnitTest2 UnitTest3 UnitTest4
	./UnitTest0
	./UnitTest1
	./UnitTest2
	./UnitTest3
	./UnitTest4
	./UnitTest5
	./UnitTest6
