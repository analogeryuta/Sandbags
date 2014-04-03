require "socket"

# open socket connection
gs = TCPServer.open("127.0.0.1", 12345)

# cast for Array object
socks = [gs]
printf("socks: %s\n", socks)

# IPSocket.addr
# ["AF_INET", port_no, domain_name, ip_addr] => [port_no, domain_name, ip_addr]
addr = gs.addr
addr.shift 
printf("echo server is on: %s\n", addr.join(":"))

while true
  #IO::select(). check socket connection from client.
  nsock = select(socks)

  #If there's no connection, go to next loop.
  next if nsock == nil 

  for s in nsock[0]
    # if get TCPServer object(socket connection is established)
    if s == gs 
      # push TCPServer object to Array object
      socks.push(s.accept)
      print(s, " is accepted\n")
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
