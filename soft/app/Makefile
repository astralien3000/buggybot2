
all:
	cd serial-controller && make
	cd servo-mapper && make
	cd ik && make
	cd teleopt-server && make
	cd teleopt-client && make

run:
	./serial-controller/build/bin/serial-controller &
	./servo-mapper/build/servo-mapper &
	./ik/build/ik &
	./teleopt-server/build/teleopt &
	./teleopt-client/build/teleopt-client

kill:
	killall serial-controller
	killall servo-mapper
	killall ik
	killall teleopt
