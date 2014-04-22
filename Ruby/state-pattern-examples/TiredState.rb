require "./State"
require "./BeenLongTimeState"

class TiredState < State
  def initialize 
    @greeting = "It's been a long time!"
  end

  def transition(context, input)
    if input == "Hello" || input == "Hi" then
      context.changeState(AfternoonState.new())
    end
  end
end
