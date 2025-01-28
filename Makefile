# Paths
SRC = src
INCLUDE = $(SRC)/Person\
		$(SRC)/Secretary\
		$(SRC)/Utilities\
		$(SRC)/Menu\
		$(SRC)/Student\
		$(SRC)/Course\
		$(SRC)/Professor\
		$(SRC)/Func\
		$(SRC)/Variables\
# Compiler
CC = g++

# Compile options.
CCFLAGS = -std=c++11 -Wall -Werror -I$(INCLUDE)
LDFLAGS =
# ^ example: -lm

# Files .o
OBJS = $(SRC)/Main/main.o $(SRC)/Person/person.o $(SRC)/Secretary/secretary.o $(SRC)/Utilities/utilities.o $(SRC)/Menu/menu.o $(SRC)/Student/student.o $(SRC)/Course/course.o $(SRC)/Professor/professor.o $(SRC)/Func/func.o

TEXT = studentsPassed.txt

EXEC = main

# Arguments
ARGS =

.PHONY: info

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC) $(TEXT)

valgrind: $(EXEC)
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGS)

run: $(EXEC)
	./$(EXEC) $(ARGS)


INFO:
	@echo "If for some reason it doesn't accept your AM or Phone Number it's because of the size."
	@echo "It must be size 10 or 13."
	@echo "To avoid this use one of the constructors."

.PHONY: INFO

ifeq ($(filter INFO,$(MAKECMDGOALS)), INFO)
run: INFO
endif

