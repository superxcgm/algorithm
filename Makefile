all:
	g++ -std=c++17 STL.common.cc -o common

.PHONY: clean

clean:
	rm -f common
