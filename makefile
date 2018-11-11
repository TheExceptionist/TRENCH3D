objects = main.o display.o render.o e_math.o objects.o input.o
exe_name = TRENCH3D
include_dir = include
lib_dir = lib
libs = SDL2

$(exe_name) : $(objects)
	g++ -Wall $(objects) -o $(exe_name) -I $(include_dir) -L $(lib_dir) \
	-l $(libs)

$(objects) : defs.h e_math.h
main.o : main.cpp display.h render.h objects.h input.h
	g++ -c main.cpp
display.o : display.cpp display.h 
	g++ -c display.cpp
render.o : render.cpp render.h display.h objects.h 
	g++ -c render.cpp
e_math.o : e_math.cpp e_math.h
	g++ -c e_math.cpp
objects.o : objects.cpp objects.h
	g++ -c objects.cpp
input.o : input.cpp input.h objects.h
	g++ -c input.cpp

.PHONY : clean \
	 reset
clean : 
	-rm $(objects) 

reset: 
	-rm $(objects) $(exe_name)
