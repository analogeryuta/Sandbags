require "./State"
require "./HelloState"

class BeenLongTimeState < State
  def initialize 
    @greeting = "It's been a long time!!"
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(self)
    elsif input == "Hi" then
      context.changeState(HelloState.new())
    end
  end
end
