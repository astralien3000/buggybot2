# RIOT and Aversive++ experiment with Buggybot

[Here is the subject of this experiment](https://youtu.be/6bN-u-e33gY). Buggybot is a four-legged robot able to walk, turn, and play various animations.

## Hardware

### Actuators

 - 12 "smart" servomotors, controlled by half-duplex UART communication
 - from 0 to 4 "basic" servomotors, when needed for a particular action

### Sensors

 - 4 Infrared distance sensors, returning an analogical signal
 - 1 gyro/accelerometer sensor, not so much used...
 - All sensors included in the smart servomotors (voltage, speed, current, force, angle)

### Control

The first hardware embedded on the robot is an Arduino Mega 2560 with a Raspberry Pi. 

 - The job of the Arduino is to handle the low-level hardware (sensors like infrared distance sensors, gyro, accelerometer or actuators like the servomotors that enable it's legs to move).
 - The Raspberry Pi will handle the Human-Robot interface (a web interface, or simple TCP communication) via Wifi, and will compute alogrithmes needed for the movement, but too time consuming for the Arduino.

## Software

### Architecture's description

The robot's software is divided in several "nodes", which are independent process that intercommunicate to provide different services. The concept of node is very similar to the ROS concept of node, even if ROS is not used in this case. Indeed, ROS is a big framework the was not supposed to support the linux distribution installed on the raspberry pi. Furthermore, since the aim was to use very few of the ROS capacity (only the message, topic, publish/subscribe systems), I chose to use a simpler library that does the job quite well : ZeroMQ.

### Presentation of the nodes

The robot has currently 8 nodes : 
 - The **embedded** node, which handle the low level hardware, and make it available to others nodes.
 - The **embedded-controller**, which just translate messages from the embedded node to others (USB/Serial to ZMQ/TCP/IP)
 - The **servo-mapper**, which will map servomotors IDs to comprehensive robot's joint (for example, a "Left Front Shoulder"), and convert angles in radians to servomotor's commands.
 - The **ik** (Inverse Kinematics) modules, which enable the robot to have an "intelligent" movement for animations. It translates positions of the feet of the robot into angles for the joints.
 - The **strategy** node, which is designed to take part to the Eurobot competition. It triggers animations to play when needed (for moving or manipulating an object, for example). This node makes the robot autonomous.
 - The **web-ui**, which is used to configure the nodes. Currently, only the servo-mapper node manage configuration.
 - The **teleoperation-server**, which replace the strategy node when the user just want to control the robot with his computer.
 - The **teleoperation-client**, which is executed on the user's device (a computer/table/smartphone), and communicate (via wifi) with the robot's teleoperation-server.

### Where does it runs ?

The first node is executed on the Arduino.
The last node may be executed anywhere, but mainly on the user's computer.
The other nodes are executed on the Raspberry Pi.

### How does the components communicate ?

The **embedded** node communicate with the **embedded-controller** via the standard USB/Serial port provided by the Arduino Mega. The protocol used is a simple custom binary protocol.

The nodes **embedded-controller**, **servo-mapper**, **ik**, **strategy**, **web-ui** and **teleoperation-server** communicate via IPC (Inter Process Communication). The library used to interface each other is ZeroMQ, which enable the nodes to use TCP instead if IPC communication with very few to no modification, so that the nodes could be executed on different platforms with no problem.

The **teleoperation-server** and **telecommunication-client** communicate via ZeroMQ/TCP (to enable wireless communication between the user and the robot).

### Which library is used for the Arduino Mega ?

No, it is not Arduino ! ;)

Aversive++ manage the Hardware abstraction layer and the different drivers (for the servomotors, mainly).

# Porting Buggybot to RIOT

The aim here is to use RIOT instead of Aversive++ as a Hardware Abstraction Layer, and use an UDP/IPv6 wireless communication instead of a custom protocol on a Serial link. This enable to remove the Raspberry from the robot and execute the code anywhere (even the cloud ?).

## Choosing a new hardware

First of all, I chose a new board that was fully compatible with RIOT, had at least 2 UART ports, and had enough memory to handle an UDP server. I chose to use the SAMR21-XPRO board, because it meets all requirements, and a very good tutorial from Alexandre Abadie was available with this board.

The biggest problem of all ARM-based boards is that GPIOs can handle 3V3 signals. Some are 5V tolerant, but it remains unsafe to use 5V signals. Anyway the SAMR21 is not 5V tolerant. So, I used a level shifter board to translate 3V3 UART to 5V UART (to communicate with the servomotors).

A second board was also needed to do the border router. As explained in the tutorial, a SAMR21-XPRO was used too.

## Porting the embedded code

Porting the embedded code, since it was only a proof of concept was quite easy. I dropped the use of sensors, which are only useful in autonomous mode, to focus on servomotors control.

Since The driver for the servomotor used in buggybot are only available for the Arduino library and the Aversive++ library, I needed to provide an adaptation layer between RIOT's UART driver and Aversive++'s Stream interface (which is used by the driver).

I followed 3 steps to have a fully functional embedded node : 
 - I made sure the servomotor driver was working with the new HAL.
 - I followed the tutorial, which sets up a COAP server. The servomotor command was done by sending a COAP PUT request with a table of 12 unsigned shots as a content. I could have stopped there, but the COAP server needed to send back an answer to the request, which increased the latency time between servomotors commands (the client had to wait for the answer).
 - I dropped the COAP server and used a simple UDP server. The UDP message are quite tiny, and don't need an answer, so that the client could send almost continuously messages. The loss of servomotor message is not a real problem for the robot, as long as it receive the last position to reach frequently enough.

## Porting other nodes

Since the embedded node is now using a well known internet standard (UDP over IPv6), the embedded-controller could be simply removed to let directly the others nodes communicate with the embedded node. But the problem of the library used for networking, ZeroMQ, is that it does not support UDP. So that, as my goal was to change as few things as possible. The embedded-controller is transformed into a ZMQ to UDP forwarder.

Others nodes were not changed at all.

## Result

[Here is the robot controlled with a SAMR21-XPRO, under RIOT](https://youtu.be/J5Ogdffptdg).

# Improvements

## Porting all nodes to RIOT

Since RIOT has the capacity to run on native target, and has capacity to establish communication between nodes, it may be interesting to port every nodes to RIOT and then unify the communication between embedded and other platforms.

## Making nodes able to run on an embedded target

Almost every nodes may be able to run on an embedded target. It would be nice to be able to move nodes from the Raspberry Pi, to the SAMR21 board, or to the cloud, or to an other embedded board that could be added to the robot. Porting the nodes to RIOT would really help to meet this aim.

## Fusioning nodes

Since nodes could run on an embedded target, it would be nice to be able to run several nodes on the same board. For example, running **embedded** and **servo-mapper** on the SAMR21 board.

## Optimisation

Especially if several nodes are running on the same embedded board, it may be interesting to not go through a complete communication stack (UDP/IPv6). The API that can switch between a full stack an a "light" stack should be transparent to the node developer.
