# config valid only for Capistrano 3.1
lock '3.1.0'

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
framework_tasks = [:starting, :started, :updating, :updated, :publishing, :published, :finishing, :finished]
 
framework_tasks.each do |t|
  Rake::Task["deploy:#{t}"].clear
end
 
Rake::Task[:deploy].clear

#
# set application's name and install directory
set :application, 'echo-server-tools'
set :deploy_to, '/home/vagrant/public'

#
# set SCM repository(for example, git)
# fetch github files
#set :application, 'Sandbags'
#set :repo_url, 'git@github.com:analogryuta/Sandbags'

#
# put 'rakugaki' files to VM server
#
task :rakugaki do
  # describe  your task here.
  run_locally do
    # run something locall tasks
    #execute "uptime"
    output = capture "echo 'hello my capistrano world!'"
    info output
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
# test /usr/bin/ruby exsists or not.
#
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
      execute "echo 'execute ruby script'"
      output = capture"ruby -v"
      info output
    else 
      execute "echo 'command not found.'"
    end
  end
end

#
# update app files
#
task :update do
  # fetch remote scm files here
  run_locally do
    execute "echo 'fetch sources from servers via SCM...'"
  end
end

#
# archive fetched files
#
task :archive => :update do
  run_locally do
    if test "[ -d #{fetch :application} ]"
      if test "[ -f #{fetch :application}.tgz ]"
        execute "echo 'tarball already created.'"
      else 
        execute "echo 'create tarball here.'"
        execute "tar -zcvf #{fetch :application}.tgz ./#{fetch :application}"
      end
    else 
      execute "echo 'there's no tools, please create files.'"
    end
  end
end


#
# transfar files local to remote
#
task :file_transfar => :archive do
  archive_file = "#{fetch :application}.tgz"
 #release_path = fetch :archive_name
  release_path = File.join(fetch(:deploy_to), "")

  # task on local
  run_locally do
    #is there nothing to do with local?
  end
  # task on remote
  on roles(:web) do
    if test "[ -d #{release_path} ]"
      execute "echo 'release directory was already created.'"
    else 
      execute "mkdir -p #{release_path}"
    end

    upload! archive_file, release_path
    execute "cd #{release_path}; tar -zxvf #{fetch :application}.tgz"
  end
end

#
# clean gabage tgz files.
#
