#
# local.rb: Sever settings for test on local environment(via Vagrant).
# you must setting ssh forward login(~/.ssh/config)
#
ask :user, 'vagrant'
ask :keypath, '~/.vagrant.d/insecure_private_key'
ask :port, '2222'

server 'localhost', roles: %w(master, node), ssh_options: {
  user: fetch(:user),
  port: fetch(:port),
  keys: fetch(:keypath),
  auth_methods: %w(publickey)
}

server 'dummy-server-1', roles: %w(node), ssh_options: {
  user: 'vagrant',
  forward_agent: true,
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

server 'dummy-server-2', roles: %w(node), ssh_options: {
  user: 'vagrant',
  forward_agent: true,
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}
