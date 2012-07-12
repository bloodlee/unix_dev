# Build the source code

CFLAG = 

CC = g++

TARGETS = my_ls

%: %.cpp
	@echo "Build $@..."
	@${CC} $^ -o $@

all: ${TARGETS}

clean:
	@echo "Remove..."
	@rm ${TARGETS}
	@echo "Done"