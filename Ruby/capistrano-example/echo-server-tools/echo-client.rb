require "socket"

class EchoClient
  def initialize(host, port)
    @host = host
    @port = port
  end

  def send_request
    s = TCPSocket.open(@host, @port)
    s.write("send request from client")
    s.close
  end
end

client = EchoClient.new("localhost", 5000)
client.send_request
