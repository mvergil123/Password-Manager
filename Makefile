# COMMENTS BEGIN WITH A HASH

# THE NAME OF YOUR EXECUTABLE
TARGET = Password_Manager
# ALL CPP COMPILABLE IMPLEMENTATION FILES THAT MAKE UP THE PROJECT
SRC_FILES = main.cpp menu.cpp secQuestions.cpp inputManager.cpp PasswordManager.cpp Password.cpp SecurityVerification.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++ -std=c++17
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g
LIB_DIR = ./cryptopp
LDFLAGS = -L$(LIB_DIR) -lcryptopp

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm -f
endif

all: cryptopp_clean $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

cryptopp_clean:
	cd $(LIB_DIR) && $(DEL) *.o
	cd ..

#.cpp.o:
#$(CXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) -o $@ -c $

# DEPENDENCIES
main.o: main.cpp inputManager.cpp
menu.o: menu.cpp menu.h
inputManager.o: inputManager.cpp inputManager.h
secQuestions.o: secQuestions.cpp secQuestions.h
PasswordManager.o: PasswordManager.cpp PasswordManager.h
Password.o: Password.cpp Password.h
SecurityVerification.o: SecurityVerification.cpp SecurityVerification.h
