#
# set server account informations for remote login to Vagrant's VM
#

#server 'localhost', roles: %w{web node}, port: 2222, ssh_options

server "localhost", roles: %w{web node1}, ssh_options: {
  port: 2222,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

server 'localhost', roles: %w{web node2}, ssh_options: {
  port: 2200,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}

server 'localhost', roles: %w{web node3}, ssh_options: {
  port: 2201,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  forward_agent: true,
  auth_methods: %w(publickey)
}
