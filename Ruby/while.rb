#
# while loop routine practice.
#
class WhileTest
  def initialize 
  end
  
  def whileLoop (max)
    flag = true
    count = 0
    while flag
      if count < max
        print("count :", count, "\n")
        count += 1
      else 
        flag = nil
      end
    end
  end
end
  
test = WhileTest.new()
test.whileLoop(128)
