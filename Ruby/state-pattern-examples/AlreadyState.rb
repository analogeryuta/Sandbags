require "./State"
require "./SighState"
require "./BeenLongTimeState"

class AlreadyState < State
  def initialize 
    @greeting = "You already said that..."
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(SighState.new())
    elsif input == "Hi" then
      context.changeState(BeenLongTimeState.new())
    end
  end
end
