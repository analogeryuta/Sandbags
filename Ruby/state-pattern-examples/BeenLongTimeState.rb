require "./State"
require "./HelloState"
require "./EveningState"

class BeenLongTimeState < State
  def initialize 
    @greeting = "It's been a long time!!"
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(EveningState.new())
    elsif input == "Hi" then
      context.changeState(HelloState.new())
    end
  end
end
