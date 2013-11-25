CC=g++
CFLAGS=-Wall -Wextra -W -ansi -O3 -std=c++11
LDFLAGS=
EXEC=mainSample minimalSample

all: $(EXEC)

mainSample: mainSample.o
	$(CC) -o $@ $^ $(LDFLAGS)

minimalSample: minimalSample.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o $(EXEC)
