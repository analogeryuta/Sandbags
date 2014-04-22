class MainClass 

end

while true do
  print(">")
  str = STDIN.gets
  print("output:" + str)

  if str == "END\n" then
    print("end.")
    break
  end
end
