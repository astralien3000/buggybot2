function rad2deg(val) {
    return val * 180.0 / 3.1415;
}

function deg2rad(val) {
    return val * 3.1415 / 180.0;
}

var socket = io();
socket.on('error', function() {
    alert('error');
});
socket.on('connect', function() {
    //alert('connect');
});
socket.on('disconnect', function() {
    //alert('disconnect');
});

function get_config() {
    socket.removeListener('pos');
    socket.removeListener('angle');
    socket.on('pos', function(data) {
	$('#pos').text(data);
    });
    socket.on('angle', function(data) {
	$('#angle').text(rad2deg(data));
    });
    
    $.get('/api/getlist', function(data) {
	var old = $('select[name=id]').val();
	var lbl = '';
	
	$('select[name=id]').empty();
	
	$.each(data, function() {
	    opt = $('<option />').val(this.id);
	    
	    if(this.label && this.label != "") {
		opt.text(this.id + ' - ' + this.label);
	    }
	    else {
		opt.text(this.id);
	    }

	    if(old == this.id) {
		lbl = this.label;
	    }
	    
	    $('select[name=id]').append(opt);
	});

	$('select[name=id]').val(old);
	socket.emit('filter', old);
	socket.emit('filter-lbl', lbl);
	
	$.get('/api/get/'+$('select[name=id]').val(),
	      function(data) {
		  $('input[name=label]').val(data.label);
		  $('input[name=min_angle]')
		      .val(rad2deg(data.min_angle));
		  $('input[name=max_angle]')
		      .val(rad2deg(data.max_angle));
		  $('input[name=calib1_position]')
		      .val(data.calib1.position);
		  $('input[name=calib1_angle]')
		      .val(rad2deg(data.calib1.angle));
		  $('input[name=calib2_position]')
		      .val(data.calib2.position);
		  $('input[name=calib2_angle]')
		      .val(rad2deg(data.calib2.angle));

		  $('#pos').text('not connected');
		  $('#angle').text('not connected');

		  $("#check").attr('src', '/img/check.png');
	      });
    });

}

function set_config() {
    data = 'id=' + $('select[name=id]').val();
    $('input[name]').each(function() {
	data += '&';
	if($(this).attr('name').indexOf('angle') != -1) {
	    data += $(this).attr('name') + '=' + deg2rad($(this).val());
	}
	else {
	    data += $(this).attr('name') + '=' + $(this).val();
	}
    });
    
    $.post('/api/set', data,
	  function(data) {
	      get_config();
	  });
}

function changed_config() {
    $("#check").attr('src', '/img/uncheck.png');
}

function fill_current(name, id) {
    $('input[name='+name+']').val(parseFloat($('#'+id).text()));
}
