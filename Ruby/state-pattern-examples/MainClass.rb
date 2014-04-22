# -*- coding: utf-8 -*-
require "./HelloBot"
class MainClass 
end

helloBot = HelloBot.new()

while true do
  print(">")
  input = STDIN.gets.chomp

  if input == "END" then
    print("Done.")
    break
  else
    helloBot.bot_say(input)
  end
end

#stateValue = 0

# while true do
#   print(">")
#   str = STDIN.gets.chomp
#   print("output:" + str + "\n")

#   if str == "Hello" then
#     if stateValue == 0 then
#       print "Hello, people!! \n"
#       stateValue = stateValue+1
#     elsif stateValue == 1 then
#       print "You already said that...\n"
#       stateValue = stateValue+1
#     elsif stateValue == 2 then
#       print "sigh...\n"
#     end
#   elsif str == "Hi" then
#     if stateValue == 1 then
#        #
#     elsif stateValue == 2 then
#       #
#     end  
#   end

#   if str == "END" then
#     print("end.")
#     break
#   end

#end
