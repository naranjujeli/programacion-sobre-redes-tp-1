all:
	g++ -c *.cpp -I include
	g++ *.o -o tp_1_carrera_de_caballos

clean:
	rm *.o
	rm tp_1_carrera_de_caballos