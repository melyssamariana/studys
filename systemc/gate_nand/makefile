EXEC = sim

SRC = $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
HEA= $(wildcard *.h)

CC=g++

# Definir caminho do SystemC (ajustar conforme necessário)
# Para CentOS:
SYSTEMC=/usr/local/bin/Siemens_EDA/Catapult_Synthesis_2022.2_1-1019737/Mgc_home
# Para Ubuntu:
# SYSTEMC=/usr/local/systemc

# Flags de compilação e linkagem para CentOS
LDFLAGS= -L$(SYSTEMC)/lib -L$(SYSTEMC)/shared/lib -Wl,-rpath=$(SYSTEMC)/lib:$(SYSTEMC)/shared/lib -lsystemc -lm
CXXFLAGS= -W -Wall -pedantic -g -std=c++17 -I$(SYSTEMC)/shared/include -DDEBUG_SYSTEMC

# Alternativa para Ubuntu:
# LDFLAGS= -L$(SYSTEMC)/lib-linux64 -Wl,-rpath=$(SYSTEMC)/lib-linux64 -lsystemc -lm
# CXXFLAGS= -W -Wall -pedantic -g -std=c++17 -I$(SYSTEMC)/include -DDEBUG_SYSTEMC

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

tar: $(HEA) $(SRC)
	tar -cvf $(EXEC).tar Makefile $^
