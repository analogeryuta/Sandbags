#
# dir.rb: test for directory search
#
Dir::foreach('./capistrano-example') do |d|
  if File::ftype(d) == "directory"
    puts "#{d}"
  end
end
