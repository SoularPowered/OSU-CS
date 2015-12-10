#########################################################
# File: Makefile
# Author: Shawn Hillyer
#########################################################

CXX = g++

# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS
SRC1 = Barbarian.cpp
SRC2 = BlueMen.cpp
SRC3 = Combat.cpp
SRC4 = Creature.cpp
SRC5 = Die.cpp
SRC6 = Goblin.cpp
SRC7 = ReptilePeople.cpp
SRC8 = TheShadow.cpp
SRC9 = Client.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9}

# HEADERS
HEADER1 = Barbarian.hpp
HEADER2 = BlueMen.hpp
HEADER3 = Combat.hpp
HEADER4 = Creature.hpp
HEADER5 = Die.hpp
HEADER6 = Goblin.hpp
HEADER7 = ReptilePeople.hpp
HEADER8 = TheShadow.hpp
HEADER9 = Client.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8} ${HEADER9}

# EXECUTABLES
PROG1 = simulate
PROG2 =
PROG3 =
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = shawn_hillyer_assignment3.pdf
DOCS = ${DOC1}

# COMPRESSED FILE
ZIP = cs162_assignment3_hillyers.zip

#####################
### BUILD SECTION ###
#####################

# make default
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# make all
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# make zip
zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOCS} makefile

# make clean
clean:
	rm -f ${PROGS} *.o *~
