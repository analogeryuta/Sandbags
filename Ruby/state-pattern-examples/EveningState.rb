require "./State"
require "./SighState"

class EveningState < State
  def initialize 
    @greeting = "Good evening people!"
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(SighState.new())
    elsif input == "Hi" then
      context.changeState(self)
    end
  end
end
