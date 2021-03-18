a4q2: a4q2.o Expression.o
	g++ -Werror=vla a4q2.o Expression.o -o a4q2
	

a4q2.o: a4q2.cpp
	g++ -Werror=vla -c a4q2.cpp

Expression.o: Expression.cpp
	g++ -Werror=vla -c Expression.cpp

clean:
	rm *.o a4q2