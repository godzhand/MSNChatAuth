all: auth

auth: auth.o
	g++ -o auth auth.cpp MD5X.h