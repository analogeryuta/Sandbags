# config valid only for Capistrano 3.1
lock '3.2.1'

#set :application, 'my_app_name'

#set :repo_url, 'git@example.com:me/my_repo.git'

# Default branch is :master
# ask :branch, proc { `git rev-parse --abbrev-ref HEAD`.chomp }

# Default deploy_to directory is /var/www/my_app
#set :deploy_to, '/var/www/my_ap'

# Default value for :scm is :git
# set :scm, :git

# Default value for :format is :pretty
# set :format, :pretty

# Default value for :log_level is :debug
# set :log_level, :debug

# Default value for :pty is false
# set :pty, true

# rbenv settings on remote environmentnt
set :rbenv_type, :user
set :rbenv_ruby, '2.1.1'
# default settings is : ~/.rbenv (:user) , /usr/local/rbenv(:system)
#set :rbenv_custom_path, '/home/vagrant/.rbenv'
set :rbenv_prefix, "RBENV_ROOT=#{fetch(:rbenv_path)} RBENV_VERSION=#{fetch(:rbenv_ruby)} #{fetch(:rbenv_path)}/bin/rbenv exec"
set :rbenv_map_bins, %w{rake gem bundle ruby rails}
set :rbenv_roles, :all # default value

# Default value for :linked_files is []
# set :linked_files, %w{config/database.yml}

# Default value for linked_dirs is []
# set :linked_dirs, %w{bin log tmp/pids tmp/cache tmp/sockets vendor/bundle public/system}

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
# set :keep_releases, 5

#
# for Capistrano tutorial: disable all deploy Tasks using Rake::Task.clear
#
# framework_tasks = [:starting, :started, :updating, :updated, :publishing, :published, :finishing, :finished]
 
# framework_tasks.each do |t|
#   Rake::Task["deploy:#{t}"].clear
# end
 
# Rake::Task[:deploy].clear

#
# set application's name and install directory
set :application, 'echo-server-tools'
set :deploy_to, '/home/vagrant/public'

#
# set SCM repository(for example, git)
# fetch github files
#set :application, 'Sandbags'
#set :repo_url, 'git@github.com:analogryuta/Sandbags'

desc "put 'rakugaki' files to VM server"
task :rakugaki do
  # describe  your task here.
  run_locally do
    # run something locall tasks
    #execute "uptime"
    output = capture "echo 'hello my capistrano world!'"
    info outputp
  end
  on roles(:web) do
    # run something tasks on server
    if test "[ -e rakugaki ]"
      execute "echo 'kilroy was here' >> rakugaki"
      output = capture "echo 'Done rakugaki'"
      info output
    else 
      execute "touch rakugaki;echo 'kilroy was here'>>rakugaki"
      output = capture "uptime"
      info output
    end
  end
end

#
# clean gabage tgz files.
#

namespace :deploy do    
  desc "test /usr/bin/ruby exsists or not."
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

  desc "update app files"
  task :update_file do
    # fetch remote scm files here
    run_locally do
      execute "echo 'fetch sources from servers via SCM...'"
    end
  end

  desc "archive fetched files"
  task :archive_file => :update_file do
    run_locally do
      if test "[ -d #{fetch :application} ]"
        if test "[ -f #{fetch :application}.tgz ]"
          info 'tarball already created.'
        else 
          info 'create tarball here.'
          execute "tar -zcvf #{fetch :application}.tgz ./#{fetch :application}"
        end
      else 
        info 'there are no tools, please create files.'
      end
    end
  end

  desc "transfar files local to remote"
  task :upload_file => :archive_file do
    archive_file = "#{fetch :application}.tgz"
    release_path = File.join(fetch(:deploy_to), "")

    on roles(:web) do
      if test "[ -d #{release_path} ]"
        info 'release directory was already created.'
      else 
        execute "mkdir -p #{release_path}"
      end
      upload! archive_file, release_path
      execute "cd #{release_path}; tar -zxvf #{fetch :application}.tgz"
    end
  end

  desc "exec echo server"
  task :exec_echo_server do
    on roles(:web) do
    end
  end

  desc "Restart application"
  task :restart_echo_server do
    #restart command here
  end
end

#
# rbenv installation settings
#
set :rbenv_path, '/home/vagrant/.rbenv'
set :rbenv_repo, 'https://github.com/sstephenson/rbenv.git'
set :ruby_build_repo, 'https://github.com/sstephenson/ruby-build.git'
set :ruby_build_path, '/home/vagrant/.rbenv/plugins/ruby-build'

desc "Fetch rbenv repository on VM server"
task :fetch_rbenv do
  on roles(:web) do
    # run something tasks on server
    if test "[ -d #{fetch(:rbenv_path)} ]"
      output = capture "echo 'rbenv is already installed.'"
      info output
    else 
      execute "git clone #{fetch(:rbenv_repo)} #{fetch(:rbenv_path)}"
      output = capture "uptime"
      info output
    end
  end
end

desc "Fetch ruby-build repository on VM server"
task :fetch_ruby_build => :fetch_rbenv do
  on roles(:web) do
    # run something tasks on server
    if test "[ -d #{fetch(:ruby_build_path)} ]"
      output = capture "echo 'ruby-build is already installed.'"
      info output
    else 
      execute "git clone #{fetch(:ruby_build_repo)} #{fetch(:ruby_build_path)}"
      output = capture "uptime"
      info output
    end
  end
end
