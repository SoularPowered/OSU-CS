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
SRC1 = Client.cpp
SRC2 = Recursive.cpp
SRC3 = recursive_funcs.cpp
SRC4 =
SRC5 =
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5}

# HEADERS
HEADER1 = Client.hpp
HEADER2 = Recursive.hpp
HEADER3 =
HEADER4 =
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4}

# EXECUTABLES
PROG1 = recursion
PROG2 =
PROG3 =
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = shawn_hillyer_lab4.pdf
DOCS = ${DOC1}

# COMPRESSED FILE
ZIP = cs162_lab4_hillyers.zip

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
