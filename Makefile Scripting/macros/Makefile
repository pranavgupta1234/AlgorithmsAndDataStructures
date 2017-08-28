#defining a macro
#CFLAGS = bla bla bla 

#CXX is macro for g++

#special macros
#$@ is the name of the file to be made
#$? is the names of changed dependents

output : main.cpp hello.cpp factorial.cpp
	$(CXX) $? -o $@

install :
	@echo You are root ! be careful !

# People have come to expect certain targets in Makefiles. You should always browse first. However, is reasonable to expect that the targets all (or just make), install, and clean is found.

# make all − It compiles everything so that you can do local testing before installing applications.

# make install − It installs applications at right places. But watch out that things are installed in the right place for your system.

# make clean − It clean applications up, gets rid of the executables, any temporary files, object files, etc.
