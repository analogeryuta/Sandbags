require "./State"
require "./HelloState"
require "./TiredState"

class InitState
  def transition(context, input)
    if input == "Hello" then
      context.changeState(HelloState.new())
    elsif input == "Hi" then
      context.changeState(TiredState.new())
    end
  end
end
