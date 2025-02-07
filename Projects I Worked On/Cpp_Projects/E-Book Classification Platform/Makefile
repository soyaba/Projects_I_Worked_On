CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++17

program.exe: program.o Plataforma.o Classificacio.o LlibreE.o Data.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Plataforma.hpp Classificacio.hpp BinaryTree.hpp PriorityQueue.hpp LlibreE.hpp

Plataforma.o: Plataforma.cpp Classificacio.hpp BinaryTree.hpp PriorityQueue.hpp

Classificacio.o: Classificacio.cpp Classificacio.hpp BinaryTree.hpp LlibreE.hpp

LlibreE.o: LlibreE.cpp LlibreE.hpp Data.hpp

Data.o: Data.cpp Data.hpp

.PHONY: clean
clean:
	rm -vf program.o Plataforma.o Classificacio.o LlibreE.o Data.o program.exe

.PHONY: test
test:
	./program.exe < sample1.inp | diff - sample1.cor
