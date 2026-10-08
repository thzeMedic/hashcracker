CXX = g++
CXXFLAGS = -Wall -Wextra
LDLIBS = -lcrypto

main: hashcracker.cpp
	$(CXX) $(CXXFLAGS) ./*.cpp -o hashcracker $(LDLIBS)

clean:
	rm -f hashcracker