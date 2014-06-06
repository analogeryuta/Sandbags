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
  #ask(:database_password, "default", echo: false)
  ask(:breakfast, "daunut")
  on roles(:all) do |h|
    execute "echo \"$(whoami) wants #{fetch(:breakfast)} for breakfast!\""
   # execute "echo \"$(whoami) wants password: #{fetch(:database_passowrd)}\""
  end
end

namespace :setup_rbenv do
  desc "Fetch rbenv repository on VM server"
  task :fetch_rbenv do
    on roles(:web) do
      if test "[ -d #{fetch(:rbenv_path)} ]"
        info "rbenv is already installed."
      else 
        execute "git clone #{fetch(:rbenv_repo)} #{fetch(:rbenv_path)}"
        execute "export"
        output = capture "uptime"
        info output
      end
    end
  end

  desc "Fetch ruby-build repository on VM server"
  task :fetch_ruby_build => :fetch_rbenv do
    on roles(:web) do
      if test "[ -d #{fetch(:ruby_build_path)} ]"
        info "ruby-build is already installed."
      else 
        execute "git clone #{fetch(:ruby_build_repo)} #{fetch(:ruby_build_path)}"
        output = capture "uptime"
        info output
      end
    end
  end

  desc "remove rbenv directories and files on VM server"
  task :remove_rbenv_dir do
    on roles(:web) do
      if !test "[ -d #{fetch(:rbenv_path)} ]"
        info "rbenv is not installed."
      else 
        execute "rm -rf #{fetch(:rbenv_path)}"
        output = capture "uptime"
        info output
      end
    end
  end
end  
#before 'deploy:starting', 'fetch_rb_env'
#before 'deploy:starting', 'fetch_ruby_build' 


desc "exec echo server"
task :exec_echo_server do
  on roles(:web) do
  end
end

desc "Restart application"
task :restart_echo_server do
  #restart command here
end
