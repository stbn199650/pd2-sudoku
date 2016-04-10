lab2:func.o main.o
	g++ -o lab2 func.o main.o

func.o:func.cpp lab2.h
	g++ -c func.cpp

main.o:main.cpp lab2.h
	g++ -c main.cpp

clean:
	rm main.o func.o
