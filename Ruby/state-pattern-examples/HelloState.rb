require "./State"
require "./AlreadyState"
require "./BeenLongTimeState"

class HelloState < State
  def initialize 
    @greeting = "Hello!"
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(AlreadyState.new())
    elsif input == "Hi" then
      context.changeState(BeenLongTimeState.new())
    end
  end
end
