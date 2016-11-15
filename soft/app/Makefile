
all:
	cd serial-controller && make
	cd servo-mapper && make
	cd ik && make
	cd teleopt-server && make
	cd teleopt-client && make

run_teleopt:
	./serial-controller/build/bin/serial-controller &
	./servo-mapper/build/servo-mapper &
	./ik/build/ik &
	./teleopt-server/build/teleopt &
	./teleopt-client/build/teleopt-client

run_ui:
	./serial-controller/build/bin/serial-controller &
	./servo-mapper/build/servo-mapper &
	./ik/build/ik &
	node servo-mapper-ui/main.js &

kill:
	killall serial-controller servo-mapper ik teleopt node
