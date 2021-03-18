a4q3: main.o cell.o grid.o subject.o textdisplay.o GraphicsDisplay.o window.o
	g++ -Werror=vla -std=c++11 -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 main.o cell.o grid.o subject.o textdisplay.o GraphicsDisplay.o window.o -o a4q3

window.o: window.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 window.cpp
	
GraphicsDisplay.o: GraphicsDisplay.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 GraphicsDisplay.cpp

main.o: main.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 main.cpp

cell.o: cell.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 cell.cpp

grid.o: grid.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 grid.cpp

subject.o: subject.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 subject.cpp

textdisplay.o: textdisplay.cpp
	g++ -Werror=vla -std=c++11 -c -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 textdisplay.cpp



clean:
	rm *.o a4q3