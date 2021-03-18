a4q3: main.o cell.o grid.o subject.o textdisplay.o
	g++ -Werror=vla -std=c++11 main.o cell.o grid.o subject.o textdisplay.o -o a4q3
	

main.o: main.cpp
	g++ -Werror=vla -std=c++11 -c main.cpp

cell.o: cell.cpp
	g++ -Werror=vla -std=c++11 -c cell.cpp

grid.o: grid.cpp
	g++ -Werror=vla -std=c++11 -c grid.cpp

subject.o: subject.cpp
	g++ -Werror=vla -std=c++11 -c subject.cpp

textdisplay.o: textdisplay.cpp
	g++ -Werror=vla -std=c++11 -c textdisplay.cpp

clean:
	rm *.o a4q3