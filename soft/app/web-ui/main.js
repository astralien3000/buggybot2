var zmq = require('zmq');

sock = zmq.socket('sub');
sock.bindSync('ipc://embed.out');
sock.subscribe('');

sock.on('message', function(msg) {
    console.log('message : ' + msg);
});
