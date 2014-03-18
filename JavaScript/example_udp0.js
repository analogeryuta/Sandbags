var dgram = require('dgram');
var echoServer = dgram.createSocket('udp4');

echoServer.on('message', function(msg, rinfo) {
  console.log('msg: ' + msg + ', length: ' + msg.length + ', from: ' + rinfo.address + ':' + rinfo.port);
  echoServer.send(msg, 0, msg.length, rinfo.port, rinfo.address);
})

var address =  '127.0.0.1';
var port =  12345;
echoServer.bind(port, address);
