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
SRC1 = Die.cpp
SRC2 = LoadedDie.cpp
SRC3 = DiceSimulator.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

# HEADERS
HEADER1 = Die.hpp
HEADER2 = LoadedDie.hpp
HEADER3 =
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

# EXECUTABLES
PROG1 = DiceSimulator
PROG2 =
PROG3 =
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = shawn_hillyer_lab1.pdf
DOCS = ${DOC1}

# COMPRESSED FILE
TAR = cs162_lab1_hillyers.tar.bz2

#####################
### BUILD SECTION ###
#####################

# make default
default:
	${CXX} ${SRCS} ${HEADERS} -o ${PROG1}

# make all
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# make tar
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# make clean
clean:
	rm -f ${PROGS} *.o *~
