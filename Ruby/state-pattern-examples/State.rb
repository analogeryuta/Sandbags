class State
  def initialize
    @greeting = ""
  end

  def transition (context, input)
  end

  def say
    print @greeting + "\n"
  end
end
