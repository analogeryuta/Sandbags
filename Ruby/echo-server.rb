require "socket"

class EchoServer
  #initializer
  def initialize (port)
    @port = port
  end

  def start
    # open socket connection
    # cast for Array object
    gs = TCPServer.open("",@port)
    socks = [gs]

    # check IPSocket.addr
    # ["AF_INET", port_no, domain_name, ip_addr] => [port_no, domain_name, ip_addr]
    sock_addr = gs.addr
    sock_addr.shift 
    printf("echo server is on: %s\n", sock_addr.join(":"))

    while true
      #IO::select(). wait socket connection from client.
      print("waiting...\n")
      nsock = select(socks)
      print("connect.\n")

      #If there's no connection, go to next loop.
      next if nsock == nil 

      print(nsock, " => nsock[]\n")
      for s in nsock[0]
        # if get TCPServer object(socket connection is established)
        if s == gs 
          # push accepted TCPSocket object to Array
          socks.push(s.accept)
          print(s, " accept client\n")
        else 
          # if get TCPSocket object(socket connection was established)
          if s.eof?
            # if get escape sequence
            print(s, " is gone\n")
            s.close
            socks.delete(s)
          else 
            # if get any data, write same data to socket.
            str = s.gets
            printf("accept data from client: %s", str)
            s.write(str)
          end
        end
      end
    end
  end 
end

server = EchoServer.new(12345)
server.start
