#
# class examples
# how can I make getter/setter method in class?
#
class SampleClass
  # attr ... equal to attr_reader
  # attr :name, :age
  # attr_reader :name, :age
  # attr_writer :name, :age
  attr_accessor :name , :age

  def initialize name, age
    @name = name
    @age = age
  end

  def hello
    puts("Hello, " + @name + "'s Ruby World!\n")
  end

  # is duplicate definition possible?
  def age
    print("Age: ", @age, "\n")
  end
end

greeting = SampleClass.new("akamine", 29)
greeting.hello

## test for duplicate definition
greeting.age = 28
greeting.age
