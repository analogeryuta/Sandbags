require "socket"

class EchoServer
  #initializer
  def initialize (port, count)
    @port = port
    @count = count
  end

  def start
    # open socket connection
    gs = TCPServer.open("", @port)

    # check IPSocket.addr
    # ["AF_INET", port_no, domain_name, ip_addr] 
    # => [port_no, domain_name, ip_addr]
    sock_addr = gs.addr
    sock_addr.shift 
    printf("echo server is on: %s\n", sock_addr.join(":"))

    count = 0
    while count < @count
      Thread.start(gs.accept) do |s|
        # s => TCPSocket object.
        print(s, " is accepted\n")
        while s.gets
          print("message => ", $_, "\n")
          s.write($_)
        end
        print(s, " is gone\n")
        s.close
      end
      count += 1
    end
  end 
end

server = EchoServer.new(12345, 5)
server.start
