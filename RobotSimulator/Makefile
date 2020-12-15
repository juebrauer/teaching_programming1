all:
	rm -f robot_simulator
	clear
	@echo "Let us build the project"
	g++ robot_simulator.cpp robot.cpp \
	    -o robot_simulator \
		`pkg-config --cflags --libs opencv4`
