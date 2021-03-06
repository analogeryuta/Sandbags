require "./State"
require "./AfternoonState"

class HelloState < State
  def initialize 
    @greeting = "Hello!"
  end

  def transition(context, input)
    if input == "Hello" || input == "Hi" then
      context.changeState(AfternoonState.new())
    end
  end
end
