EXECUTABLE = game
SOURCES = space.cpp
SOURCES += player.cpp
SOURCES += control_room.cpp
SOURCES += game.cpp
SOURCES += pal.cpp
SOURCES += airlock1.cpp
SOURCES += deck.cpp
SOURCES += object.cpp
SOURCES += airlock2.cpp
SOURCES += menu.cpp
SOURCES += robot.cpp
SOURCES += outside.cpp
#HEADERS = $(SOURCES:.cpp=.hpp)
MAIN_METHOD_FILE = main_game.cpp
SOURCES += $(MAIN_METHOD_FILE)
OBJECTS = $(SOURCES:.cpp=.o)
#SOURCES += $(HEADERS)

#comment out unless using precompiled headers
#REMOVE_HEADERS = *.gch

#comment out unless program creates .txts you need to remove
#REMOVE_TXTS = 
#REMOVE_TXTS += *.txt

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -c -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	
$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES)
	
clean:
	rm *o $(REMOVE_HEADERS) $(REMOVE_TXTS) $(EXECUTABLE)
	
text_clean:
	rm *.txt