var zmq = require('zmq');
var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var http = require('http');
var server = http.Server(app);
var io = require('socket.io')(server);

app.use(bodyParser.urlencoded({
    extended: true
}));

app.set('views', __dirname + '/views');
app.set('view engine', 'jade');

app.use(express.static(__dirname + "/public"));

app.get('/', function (req, res) {
    res.render('index', { title : 'buggybot2' });
});

app.get('/api/get/:id', function(req, res) {
    var msg = JSON.stringify({
	"action" : "get",
	"id" : parseInt(req.params.id),
    });

    sock = zmq.socket('req');
    sock.connect('ipc://servo-mapper.config');

    sock.send(msg);

    sock.on('message', function(msg) {
	res.send(JSON.parse(msg.toString()).data);
	sock.disconnect('ipc://servo-mapper.config');
    });
});

app.get('/api/getlist', function(req, res) {
    var msg = JSON.stringify({
	"action" : "getall",
    });

    sock = zmq.socket('req');
    sock.connect('ipc://servo-mapper.config');

    sock.send(msg);

    sock.on('message', function(msg) {
	answer = JSON.parse(msg.toString());
	//res.send(answer.data);
	list = []
	for(var i = 0 ; i < answer.data.length ; i++) {
	    list.push({
		'id' : answer.data[i].value.id,
		'label' : answer.data[i].value.label,
	    });
	}
	res.send(list);
	sock.disconnect('ipc://servo-mapper.config');
    });
});

app.post('/api/set', function(req, res) {    
    var msg = JSON.stringify({
	"action": "set",
	"config": {
	    "id": parseInt(req.body.id),
	    "label": req.body.label,
	    "calib1": {
		"angle": parseFloat(req.body.calib1_angle),
		"position": parseInt(req.body.calib1_position)
	    },
	    "calib2": {
		"angle": parseFloat(req.body.calib2_angle),
		"position": parseInt(req.body.calib2_position)
	    },
	    "min_angle": parseFloat(req.body.min_angle),
	    "max_angle": parseFloat(req.body.max_angle)
	}
    });

    console.log(req.body);
    console.log(msg);

    sock = zmq.socket('req');
    sock.connect('ipc://servo-mapper.config');

    sock.send(msg);
    
    sock.on('message', function(msg) {
	res.send(msg.toString());
	sock.disconnect('ipc://servo-mapper.config');
    });
});

server.listen(3000);

io.on('connection', function(io_sock) {
    embed_sock = zmq.socket('sub');
    embed_sock.connect('ipc://embed.in');
    embed_sock.subscribe('');

    servo_sock = zmq.socket('sub');
    servo_sock.connect('ipc://servo.in');
    servo_sock.subscribe('');

    io_sock.on('filter', function(msg) {
	io_sock.id_filter = msg;
    });

    io_sock.on('filter-lbl', function(msg) {
	io_sock.lbl_filter = msg;
    });

    io_sock.on('disconnect', function() {
	embed_sock.close();
	servo_sock.close();
    });

    embed_sock.on('message', function(msg) {
	msg = JSON.parse(msg.toString());
	if(msg.value1 == io_sock.id_filter) {
	    io_sock.emit('pos', msg.value2);
	}
    });
    
    servo_sock.on('message', function(msg) {
	msg = JSON.parse(msg.toString());
	if(msg.value0.label == io_sock.lbl_filter) {
	    io_sock.emit('angle', msg.value0.angle);
	}
    });
});
