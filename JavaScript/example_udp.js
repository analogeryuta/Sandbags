var dgram = require("dgram");
var server = dgram.createSocket("udp4");
var msgAck = new Buffer("ack from server");

server.on("message", function (msg, rinfo) {
    console.log("server got: " + msg + " from " +
		rinfo.address + ":" + rinfo.port);
    server.send(msgAck, 0, msgAck.length, rinfo.port, rinfo.address);
    });

server.on("listening", function () {
    console.log("server listening " + 
		server.address().address + ":" + server.address().port);
    });

server.bind(8124, '127.0.0.1');