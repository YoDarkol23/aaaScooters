all:
	g++ scooter.cpp main.cpp -o samokat
	./samokat
clean:
	rm -f samokat
