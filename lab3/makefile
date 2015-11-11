#########################################################
# File: Makefile
# Author: Shawn Hillyer
# Description: Modified makefile to test the integration
# of another student's LoadedDie class using inheritance
# as a modified class.
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
SRC1 = Die.cpp
SRC2 = LoadedDie.cpp
SRC3 = DiceWar.cpp
SRC4 = Client.cpp
SRC5 = DiceSimulator.cpp
SRC6 = implement.cpp
SRC7 = DiceWarGame.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

# HEADERS
HEADER1 = Die.hpp
HEADER2 = LoadedDie.hpp
HEADER3 = DiceWar.hpp
HEADER4 = Client.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4}

# EXECUTABLES
PROG1 = DiceWar
PROG2 = original
PROG3 = DiceSimulator
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = shawn_hillyer_lab3.pdf
DOC2 = readme.txt
DOCS = ${DOC1} ${DOC2}

# COMPRESSED FILE
ZIP = cs162_lab3_hillyers.ZIP

#####################
### BUILD SECTION ###
#####################

# make default -- makes the DiceWarGame program
default:
	${CXX} ${SRCS} ${SRC7} ${HEADERS} -o ${PROG1}

# make all
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# make original
original:
	${CXX} ${SRC1} ${SRC2} ${SRC6} ${HEADER1} ${HEADER2} -o ${PROG2}

# make mysim
mysim:
	${CXX} ${SRC1} ${SRC2} ${SRC5} ${HEADER1} ${HEADER2} -o ${PROG3}

# make zip
zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOCS} makefile

# make clean
clean:
	rm -f ${PROGS} *.o *~
