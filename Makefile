CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3
INCLUDES = strategy.h confront.h ecosystem.h evo.cpp
EXECS    = evo

${EXECS}: evo.o strategy.o confront.o ecosystem.o
	${CXX} ${CXXFLAGS} -o ${EXECS} evo.o strategy.o confront.o ecosystem.o


%.o:%.cpp $(INCLUDES) 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf ${EXECS} *.o *.dSYM
