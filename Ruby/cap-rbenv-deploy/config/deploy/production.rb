# set server account informations for remote login to Vagrant's VM
#
#
#server 'localhost', roles: %w{web node}, port: 2222, ssh_options

server "localhost", roles: %w{app, web}, ssh_options: {
  port: 2222,
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}
