#################
#   VARIABLES   #
#################

# Inner Variables
CC = g++
CFLAGS = -g

# User Defined Variables
TARGET = 3_en_raya			# <- Sólo cambiar esto
SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))


###############
#   TARGETS   #
###############


all: clean $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


.PHONY: info clean

clean:
	$(RM) *.o
	$(RM) $(TARGET)

info: 
	$(info SRCs = $(SOURCES))
	$(info OBJs = $(OBJS))
