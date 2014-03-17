#!/usr/bin/ruby 

require 'json'

# array to string
arr = {"name" => "bourn, jason", "age" => 35}
p arr.to_json

# string to json
str = '{"name":"hoge","age":32}'
json = JSON.parse(str)

# iterate from json objects
json.each do |key,val|
  puts "#{key}: #{val}\n"
end
