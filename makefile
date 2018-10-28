objects = main.o display.o render.o e_math.o
exe_name = TRENCH3D
include_dir = include
lib_dir = lib
libs = SDL2

$(exe_name) : $(objects)
	g++ -Wall $(objects) -o $(exe_name) -I $(include_dir) -L $(lib_dir) \
	-l $(libs)

$(objects) : defs.h e_math.h
main.o : main.cpp display.h
	g++ -c main.cpp
display.o : display.cpp display.h 
	g++ -c display.cpp
render.o : render.cpp render.h 
	g++ -c render.cpp
e_math.o : e_math.cpp e_math.h
	g++ -c e_math.cpp

.PHONY : clean \
	 reset
clean : 
	-rm $(objects) 

reset: 
	-rm $(objects) $(exe_name)
