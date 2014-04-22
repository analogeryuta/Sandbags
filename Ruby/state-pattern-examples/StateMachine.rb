# -*- coding: utf-8 -*-

#
# single class for if/else state change examples
#
#      print "Hello, people!! \n"
#      print "You already said that...\n"
#      print "sigh...\n"

class StateMachine
  # attr_accessor :helloCount, :hiCount
  # def initialize
  #   @helloCount = 0
  #   @hiCount = 0
  # end

end

helloCount = 0
hiCount = 0

while true do
  print(">")
  str = STDIN.gets.chomp
  print("output:" + str + "\n")

  if str == "Hello" then
    if  helloCount == 0 && hiCount == 0 then
      print "Hello!"
      helloCount = helloCount + 1
    end
  elsif str == "Hi" then
    if hiCount == 0 && hiCount == 0 then
      print "I'm tired...\n"
      hiCount = hiCount + 1
    elsif helloCount == 0 && hiCount == 1 then
      print "It's been a long time!"
      hiCount = hiCount + 1
    end
  end

  if str == "END" then
    print("end.")
    break
  end
end
