require "./State"

class SighState < State
  def initialize 
    @greeting = "Sigh..."
  end

  def transition(context, input)
    if input == "Hello" then
      context.changeState(self)
    elsif input == "Hi" then
      context.changeState(self)
    end
  end
end
