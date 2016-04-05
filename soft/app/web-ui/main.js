var zmq = require('zmq');

sock = zmq.socket('req');
sock.connect('ipc://servo-mapper.config');

var msg = JSON.stringify({
    "action": "set",
    "config": {
        "id": 1,
        "label": "test",
        "calib1": {
            "angle": 0,
            "position": 0
        },
        "calib2": {
            "angle": 0,
            "position": 0
        },
        "min_angle": 0,
        "max_angle": 0
    }
});

sock.send(msg);
console.log('send : ' + msg);

setInterval(function() {
    var msg = JSON.stringify({
	"action" : "get",
	"id" : 1,
    });
    
    sock.send(msg);
    console.log('send : ' + msg);
}, 1000);

sock.on('message', function(msg) {
    console.log('recv : ' + msg);
});
