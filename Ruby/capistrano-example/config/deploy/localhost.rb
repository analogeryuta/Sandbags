# set server account informations for remote login to Vagrant's VM
#
#
#server 'localhost', roles: %w{web node}, port: 2222, ssh_options

server "localhost", roles: %w{app}, ssh_options: {
  port: 2222,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

set :branch, ENV['BRANCH'] || 'master'
set :rbenv_type, :user
set :linked_dirs, %w(log tmp/pids tmp/cache tmp/sockets vendor/bundle public/system tmp/run)
set :keep_releases, 5
set :scm, :bundle_rsync # Need this
set :bundle_rsync_max_parallels, ENV['PARA']
set :bundle_rsync_rsync_bwlimit, ENV['BWLIMIT'] # like 20000
set :bundle_rsync_config_files, ['./config/rsync/database.yml']

set :application, 'dotfiles'
set :repo_url, "git@github.com:analogeryuta/dotfiles.git"
set :deploy_to, "/home/vagrant/dotfiles"
set :rbenv_ruby, "2.1.1" # Required on both deploy machine and remote machines
