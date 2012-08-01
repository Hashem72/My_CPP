SRCS=foo.cpp
HDRS=foo.hpp
EXE=foo
CXX=/software/gcc-4.6.0/bin/g++
CXXFLAGS=-std=c++0x -O3  -Wl,-rpath,/software/gcc-4.6.0/lib64
$(EXE): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@


