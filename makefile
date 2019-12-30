default:all
fragenGenerator: fragenGenerator.cpp
	g++ -g -o fragenGenerator fragenGenerator.cpp
defGenerator: defGenerator.cpp
	g++ -g -o defGenerator defGenerator.cpp
all: fragenGenerator defGenerator
zip: all 
	zip -o generator.zip *.* makefile 

frage: fragenGenerator
	./fragenGenerator
def: defGenerator
	./defGenerator
