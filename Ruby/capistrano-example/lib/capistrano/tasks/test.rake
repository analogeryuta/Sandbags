#
# test.rb: test tasks for capistrano.
#
desc "put 'rakugaki' files to VM server"
task :rakugaki do
  # describe  your task here.
  run_locally do
    # doing something on local.
  end
  on roles(:web) do |host|
    # run something tasks on server
    if test "[ -f rakugaki ]"
      execute "echo 'kilroy was here' >> rakugaki"
      info "Host #{host} (#{host.roles.to_a.join(', ')}): #{capture(:uptime)}"
      info 'Done rakugaki'
      info capture "uptime"
    else 
      execute "touch rakugaki;echo 'kilroy was here'>>rakugaki"
      info capture "uptime"
    end
  end
end

desc "test system's ruby exsists or not."
task :check_ruby do
  # describe  your task here.
  run_locally do
    # run something locall tasks
    #execute "uptime"
    output = capture "echo 'nothing to do on local environment.'"
    info output
  end
  on roles(:web) do
    # run something tasks on server
    if test "[ -e /usr/bin/ruby ]"
      info 'execute ruby script'
      output = capture "ruby -v"
      info output
    else 
      info 'command not found.'
    end
  end
end

desc "Ask input from prompt"
task :test_prompt do
  ask(:breakfast, "daunut")
  on roles(:all) do |h|
    execute "echo \"$(whoami) wants #{fetch(:breakfast)} for breakfast!\""
  end
end
