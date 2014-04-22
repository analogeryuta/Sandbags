require './HumanClass'
require './HumanChildClass'

class WorldClass

end

# HumanClass's message
human = HumanClass.new()
human.say()

# HumanChildClass's message
child = HumanChildClass.new()
child.say()
