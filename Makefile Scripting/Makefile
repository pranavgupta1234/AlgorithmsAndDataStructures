#v1
#routine : main.cpp factorial.cpp hello.cpp
#	g++ -o routine main.cpp factorial.cpp hello.cpp 

#v2
#routine : main.o factorial.o hello.o
#	g++ -o routine main.o factorial.o hello.o

#v3
# routine : main.o factorial.o hello.o
# 	g++ -o routine main.o factorial.o hello.o

#automatic recipie deduction
# main.o : main.cpp											

# factorial.o : factorial.cpp

# hello.o : hello.cpp


#v4
# routine : main.o factorial.o hello.o
# 	g++ -o routine main.o factorial.o hello.o

# main.o : main.cpp
# 	g++ -c main.cpp

# factorial.o : factorial.cpp
# 	g++ -c factorial.cpp

# hello.o : hello.cpp
# 	g++ -c hello.cpp

# refresh : 
# 	rm *.o

#v5
source = main.cpp factorial.cpp hello.cpp

routine : $(source)
	g++ -o routine $(source)

clean :
	rm -f *.o

#call make clean to clean the binaries
#-f flag is used to handle the case when no binaries are present in that case it just ignores 