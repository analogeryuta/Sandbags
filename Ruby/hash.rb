#
# hash routine examples
#

class HashTest
  attr :hash 
  def initialize val
    @hash = val
  end
end

val = HashTest.new({"one" => 1, "two" => 2, "three" => 3})

puts val.hash["one"]
puts val.hash["three"]
