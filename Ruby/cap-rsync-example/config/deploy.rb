# config valid only for Capistrano 3.1
lock '3.2.1'

#set :application, 'my_app_name'
#set :repo_url, 'git@example.com:me/my_repo.git'

# Default branch is :master
# ask :branch, proc { `git rev-parse --abbrev-ref HEAD`.chomp }.call

# Default deploy_to directory is /var/www/my_app
# set :deploy_to, '/var/www/my_app'

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

namespace :deploy do

  desc 'Restart application'
  task :restart do
    on roles(:app), in: :sequence, wait: 5 do
      # Your restart mechanism here, for example:
      # execute :touch, release_path.join('tmp/restart.txt')
    end
  end

  after :restart, :clear_cache do
    on roles(:web), in: :groups, limit: 3, wait: 10 do
      # Here we can do anything such as:
      # within release_path do
      #   execute :rake, 'cache:clear'
      # end
    end
  end

end

set :rbenv_url, "https://github.com/sstephenson/rbenv.git"
set :ruby_build_url, "https://github.com/sstephenson/ruby-build.git"
set :ruby_build_path, "#{fetch(:rbenv_path)}/plugins/ruby-build"

namespace :setup_rbenv do

  desc "Fetch rbenv repository on VM server"
  task :fetch_rbenv do
    on roles(:web) do
      if test "[ -d #{fetch(:rbenv_path)} ]"
        info "rbenv is already installed."
      else 
        info "rbenv is not installed."
        execute "git clone #{fetch(:rbenv_url)} #{fetch(:rbenv_path)}"
        output = capture "uptime"
        info output
      end
    end
  end

  task :build_rbenv =>:fetch_rbenv do
    on roles(:web) do
      if test "[ ! -d #{fetch(:rbenv_ruby_dir)} ]"
        execute "echo \'export PATH\=\"\$HOME/.rbenv/bin:\$PATH\"\' >> ~/.bash_profile"
        execute "#{fetch(:rbenv_path)}/bin/rbenv install 2.1.1"
        execute "#{fetch(:rbenv_path)}/bin/rbenv global 2.1.1"
      end
    end
  end

  desc "Fetch ruby-build repository on VM server"
  before 'rbenv:validate', :fetch_ruby_build => :build_rbenv do
    on roles(:web) do
      if test "[ -d #{fetch(:ruby_build_path)} ]"
        info "ruby-build is already installed."
      else 
        execute "git clone #{fetch(:ruby_build_url)} #{fetch(:ruby_build_path)}"
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