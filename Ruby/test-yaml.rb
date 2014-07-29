require 'yaml'
require 'pp'

str = ARGF.read()
data = YAML.load(str)
pp data
