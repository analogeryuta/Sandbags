#
# test for stdout-to-array from command line `vagrant ssh-config default`
#
match = []
host, user, keyfile, port = ""
config = `vagrant ssh-config default`
if config != ''
  config.each_line do |line|
      if match = /HostName (.*)/.match(line)
        p "enter: processing... host"
        #host = match[1].chomp
        host = match[1]
      elsif  match = /User (.*)/.match(line)
        p "enter: processing... user"
        #user = match[1].chomp
        user = match[1]
      elsif match = /IdentityFile (.*)/.match(line)
        p "enter: processing... keyfile"
        keyfile =  [match[1].gsub(/"/,'')]
        #keyfile.each { |k| k.chomp! }
      elsif match = /Port (.*)/.match(line)
        p "enter: processing... port"
        #port = match[1].chomp
        port = match[1]
      end
  end
  p "Debug string below"
  p host, user, keyfile, port
end
