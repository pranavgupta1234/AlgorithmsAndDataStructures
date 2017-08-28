#directives are like if else 

CC = g++

output : main.cpp factorial.cpp hello.cpp
ifeq ($(CC), g++)
	@echo Compile kar raha hoon bhai ! ruk toh :p 
	g++ -o output main.cpp factorial.cpp hello.cpp 
else
	@echo Does not match
endif

clean :
	-rm -f *.o


#other directives include ifneq , ifdef (takes single val to evaluate as bool) endif ends the conditional directive and is must