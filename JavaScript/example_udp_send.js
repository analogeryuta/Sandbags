var dgram = require('dgram');
var client = dgram.createSocket("udp4");
var message = new Buffer("Hello node.js world via UDP port.");

client.on("message" , function (msg, rinfo) {
	console.log("got from server: " + msg + " addr: " + rinfo.address);
	client.close();
    });

client.on("listening", function () {
	console.log("client listening" + 
		    client.address().address + ":" + client.address().port);
	client.send(message, 0, message.length, 8124, "127.0.0.1");
    });

client.bind(8125);