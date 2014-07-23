#
# local.rb: Sever settings for test on local environment(via Vagrant).
# you must setting ssh forward login(~/.ssh/config)
#

server "localhost", roles: %w{master}, ssh_options: {
  port: 2222,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

server 'dummy-server-1', roles: %w{node}, ssh_options: {
  user: 'vagrant',
  forward_agent: true,
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

server 'dummy-server-2', roles: %w{node}, ssh_options: {
  user: 'vagrant',
  forward_agent: true,
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}
