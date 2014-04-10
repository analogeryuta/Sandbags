#
# examples for accessor method definition
# (using "attr", "attr_writer", "attr_accessor")
#

class SampleTest
  attr_reader :foo
  attr_writer :bar
  attr_accessor :hoge

  def initialize foo, bar, hoge
    @foo = foo
    @bar = bar
    @hoge = hoge
  end

  def isCorrect var
    if @bar == var
      return true
    else 
      return false
    end
  end
end

sample = SampleTest.new("foo", "bar", "hoge")
#sample.foo = "Foo"
sample.bar = "Bar"
sample.hoge = "HOGE"

puts sample.foo
puts sample.isCorrect("bar")
puts sample.hoge
