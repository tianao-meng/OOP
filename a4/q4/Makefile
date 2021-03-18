a4q4: allcaps.o count.o decorator.o doublewords.o dropfirst.o echo.o main.o textprocess.o
	g++ -Werror=vla -std=c++11 -g  allcaps.o count.o decorator.o doublewords.o dropfirst.o 	echo.o main.o textprocess.o -o a4q4
	

allcaps.o: allcaps.cpp
	g++ -Werror=vla -std=c++11 -g -c allcaps.cpp

count.o: count.cpp
	g++ -Werror=vla -std=c++11 -g -c count.cpp

decorator.o: decorator.cpp
	g++ -Werror=vla -std=c++11 -g -c decorator.cpp

dropfirst.o: dropfirst.cpp
	g++ -Werror=vla -std=c++11 -g -c dropfirst.cpp

echo.o: echo.cpp
	g++ -Werror=vla -std=c++11 -g -c echo.cpp

main.o: main.cpp
	g++ -Werror=vla -std=c++11 -g -c main.cpp

textprocess.o: textprocess.cpp
	g++ -Werror=vla -std=c++11 -g -c textprocess.cpp

clean:
	rm *.o a4q4