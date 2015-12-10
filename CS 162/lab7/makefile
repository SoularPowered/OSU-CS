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
SRC2 = Menu.cpp
SRC3 = SearchSort.cpp
SRC4 =
SRC5 =
SRC6 =
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6}

# HEADERS
HEADER1 = Client.hpp
HEADER2 = Menu.hpp
HEADER3 = SearchSort.hpp
HEADER4 =
HEADER5 =
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5}

# EXECUTABLES
PROG1 = sorting
PROG2 =
PROG3 =
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = random_early.txt
DOC2 = random_middle.txt
DOC3 = random_end.txt
DOC4 = sorted_values.txt
DOC5 = main.menu
DOCS = ${DOC1} ${DOC2} ${DOC3} ${DOC4} ${DOC5}

# COMPRESSED FILE
ZIP = cs162_lab7_hillyers.zip

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
