require "./State"
require "./AlreadyState"
require "./BeenLongTimeState"

class AfternoonState < State
  def initialize 
    @greeting = "Good after noon people !"
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(AlreadyState.new())
    elsif input == "Hi" then
      context.changeState(BeenLongTimeState.new())
    end
  end
end
