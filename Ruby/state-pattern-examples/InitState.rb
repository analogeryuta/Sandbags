require "./State"
require "./HelloState"

class InitState
  def transition(context, input)
    if input == "Hello" then
      context.changeState(HelloState.new())
    elsif input == "Hi" then
      context.changeState(HelloState.new())
    end
  end
end
