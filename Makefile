FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJECTS = main.o utest_file.o math_ops.o utils.o 

all: prog1

prog1: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o prog1
 
main.o: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

utest_file.o: utest_file.cpp
	g++ $(FLAGS) -c utest_file.cpp -o utest_file.o

math_ops.o: math_ops.cpp
	g++ $(FLAGS) -c math_ops.cpp -o math_ops.o

utils.o: utils.cpp
	g++ $(FLAGS) -c utils.cpp -o utils.o

clean:
	del -f *.o prog1