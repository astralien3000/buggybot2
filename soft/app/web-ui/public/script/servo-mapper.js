function get_config() {
    //alert('get');
    
    $.get('/api/getlist', function(data) {
	var old = $('select[name=id]').val()
	
	$('select[name=id]').empty();
	
	$.each(data, function() {
	    $('select[name=id]').append(
		$('<option />')
		    .val(this.id)
		    .text(this.id + ' - ' + this.label)
	    );
	});

	$('select[name=id]').val(old);

	$.get('/api/get/'+$('select[name=id]').val(),
	      function(data) {
		  $('input[name=label]').val(data.label);
		  $('input[name=min_angle]').val(data.min_angle);
		  $('input[name=max_angle]').val(data.max_angle);
		  $('input[name=calib1_position]')
		      .val(data.calib1.position);
		  $('input[name=calib1_angle]')
		      .val(data.calib1.angle);
		  $('input[name=calib2_position]')
		      .val(data.calib2.position);
		  $('input[name=calib2_angle]')
		      .val(data.calib2.angle);

		  $("#check").attr('src', '/img/check.png');
	      });
    });

}

function set_config() {
    data = 'id=' + $('select[name=id]').val();
    $('input[name]').each(function() {
	data += '&';
	data += $(this).attr('name') + '=' + $(this).val();
    });
    
    $.post('/api/set', data,
	  function(data) {
	      get_config();
	  });
}

function changed_config() {
    $("#check").attr('src', '/img/uncheck.png');
}
