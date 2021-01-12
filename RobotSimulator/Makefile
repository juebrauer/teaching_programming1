all:
	rm -f robot_simulator
	clear
	@echo "Let us build the project"
	g++ -Wall *.cpp \
	    -o robot_simulator \
		`pkg-config --cflags --libs opencv4`
	@echo CODE COMPILED SUCCESSFULLY!