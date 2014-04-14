#
# example for code block definitions
#
class YieldTest
  def initialize foo
    @foo = foo
  end

  def each
    i=0
    while @foo[i] != nil
      yield @foo[i]
      i+=1
    end
  end
end

def yieldTest
puts "enter: yieldTest\n"
  yield 
puts "exit: yieldTest\n"
end

yieldTest do
  puts "hoge"
end

#
# emulate Array.each
#
test = YieldTest.new([1, 2, 3, 4, 5])
test.each do |i|
    puts i
end

test.each {|i|
  puts i
}
