FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJECTS = main.o utest_file.o math_ops.o utils.o 
SOURCE_DIR  = .\Source\\
HEADERS_DIR = .\Headers
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(FLAGS) $^ -o $@
 
main.o: $(SOURCE_DIR)main.cpp
	g++ $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

utest_file.o: $(SOURCE_DIR)utest_file.cpp
	g++ $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

math_ops.o: $(SOURCE_DIR)math_ops.cpp
	g++ $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

utils.o: $(SOURCE_DIR)utils.cpp
	g++ $(FLAGS) -I$(HEADERS_DIR) -c $< -o $@

clean:
	del -f *.o $(TARGET)