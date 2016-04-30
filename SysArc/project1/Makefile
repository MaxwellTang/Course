all:proj1.out
	echo "exec:proj1.out"
proj1.out:sim.o disassembly.o proj1.o
	g++ sim.o disassembly.o proj1.o -o proj1.out 
proj1.o:proj1.cpp
	g++ -c proj1.cpp
disassemblytest.out:disassembly.o disassemblytest.o
	g++ disassembly.o disassemblytest.o -o disassemblytest.out
disassemblytest.o:disassemblytest.cpp
	g++ -c disassemblytest.cpp
disassembly.o:disassembly.cpp disassembly.h
	g++ -c disassembly.cpp 
simtest.out:sim.o simtest.o
	g++ sim.o simtest.o -o simtest.out
sim.o:sim.h sim.cpp
	g++ -c sim.cpp
simtest.o:simtest.cpp
	g++ -c simtest.cpp
.PHONY:clean
clean:
	rm *.o *.out
