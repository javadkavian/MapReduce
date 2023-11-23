CC     = g++
CFLAGS =

PATH_SRC = ./src
PATH_INC = $(PATH_SRC)/include
PATH_OBJ = ./obj
PATH_LOG = ./log

OUT_MAIN = main
OUT_BUILDING = building_proc
#----------------------------------------------
vpath %.cpp $(PATH_SRC)
vpath %.hpp $(PATH_INC)

OBJS_MAIN = main.o log.o named_pipe.o gather_data.o

OBJS_BUILDING = building_proc.o building.o

#-----------------------------------------------

all: $(PATH_OBJ) $(PATH_LOG) $(OUT_MAIN) $(OUT_BUILDING)

$(OUT_MAIN): $(addprefix $(PATH_OBJ)/, $(OBJS_MAIN))
	$(CC) $(CFLAGS) -o $@ $^

$(OUT_BUILDING): $(addprefix $(PATH_OBJ)/, $(OBJS_BUILDING))
	$(CC) $(CFLAGS) -o $@ $^

$(PATH_OBJ)/main.o: main.cpp globals.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/log.o: log.cpp log.hpp globals.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/building.o: building.cpp building.hpp globals.hpp log.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/named_pipe.o: named_pipe.cpp named_pipe.hpp globals.hpp log.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/gather_data.o: gather_data.cpp gather_data.hpp globals.hpp named_pipe.hpp log.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ)/building_proc.o: building_proc.cpp building.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(PATH_OBJ): ; mkdir -p $@
$(PATH_LOG): ; mkdir -p $@

.PHONY: all clean

clean:
	rm -rf $(PATH_OBJ) $(PATH_LOG) $(OUT_MAIN) > /dev/null 2>&1