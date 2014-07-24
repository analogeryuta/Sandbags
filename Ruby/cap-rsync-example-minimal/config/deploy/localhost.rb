# set server account informations for remote login to Vagrant's VM
#
#
#server 'localhost', roles: %w{web node}, port: 2222, ssh_options

set :ssh_options, {
  port: 2222,
  user: 'vagrant',
  keys: [File.expand_path('~/.vagrant.d/insecure_private_key')],
  auth_methods: %w(publickey)
}

server "localhost", roles: %w(app, web), ssh_options: fetch(:ssh_options)

set :branch, ENV['BRANCH'] || 'master'
set :rbenv_type, :user
set :keep_releases, 5
set :scm, :bundle_rsync # Need this
#set :bundle_rsync_scm, 'local_git'
set :bundle_rsync_max_parallels, ENV['PARA']
set :bundle_rsync_skip_bundle, true
set :application, 'dotfiles'
set :repo_url, "git@github.com:analogeryuta/dotfiles.git"
#set :repo_url, "#{ENV['HOME']}/dotfiles"
set :deploy_to, "/home/vagrant/deploy"
set :rbenv_ruby, "2.1.1" # Required on both deploy machine and remote machines
