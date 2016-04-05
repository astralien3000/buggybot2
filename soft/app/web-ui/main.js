var zmq = require('zmq');
var express = require('express');
var bodyParser = require('body-parser')



/*
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
*/

var app = express();

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
	res.send(msg.toString());
	sock.disconnect('ipc://servo-mapper.config');
    });
});

app.post('/api/set', function(req, res) {
    console.log(req.body);
    
    var msg = JSON.stringify({
	"action": "set",
	"config": {
	    "id": parseInt(req.body.id),
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

    sock = zmq.socket('req');
    sock.connect('ipc://servo-mapper.config');

    sock.send(msg);
    
    sock.on('message', function(msg) {
	res.send(msg.toString());
	sock.disconnect('ipc://servo-mapper.config');
    });
});

app.listen(3000);
