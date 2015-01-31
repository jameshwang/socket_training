var net = require('net');

var server = net.createServer(function (socket) {

  socket.write('hello\n');
  socket.end();
});

server.listen(9500, '127.0.0.1')
