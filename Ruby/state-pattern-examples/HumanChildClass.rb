# -*- coding: utf-8 -*-
require "./HumanClass"

class HumanChildClass < HumanClass
  def initialize
    @think = "あそびてー"
  end
  def say()
    puts @think
  end
end
