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
SRC1 = FileFilter.cpp
SRC2 = ToUpperFilter.cpp
SRC3 = IntCryptionFilter.cpp
SRC4 = Client.cpp
SRC5 = CopyFilter.cpp
SRC6 = FileConverter.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6}

# HEADERS
HEADER1 = FileFilter.hpp
HEADER2 = ToUpperFilter.hpp
HEADER3 = IntCryptionFilter.hpp
HEADER4 = Client.hpp
HEADER5 = CopyFilter.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5}

# EXECUTABLES
PROG1 = filefilter
PROG2 =
PROG3 =
PROGS = ${PROG1} ${PROG2} ${PROG3}

# DOCUMENTS
DOC1 = shawn_hillyer_lab5.pdf
DOCS = ${DOC1}

# COMPRESSED FILE
ZIP = cs162_lab5_hillyers.zip

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
