require "./InitState"

class HelloBot
  def initialize
    @currentState = InitState.new()
  end

  def changeState(state)
    @currentState = state
  end

  def bot_say(input)
    if (input == "Hello") || (input == "Hi") then
      @currentState.transition(self, input)
      @currentState.say()
    else 
      print("?\n")
    end
  end
end
