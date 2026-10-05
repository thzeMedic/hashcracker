CXX = g++
CXXFLAGS = -Wall -Wextra
LDLIBS = -lcrypto

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main $(LDLIBS)

clean:
	rm -f main