#
# set server account informations for remote login to Vagrant's VM
#
server '127.0.0.1', roles: %w{web}, user: 'vagrant', port: 2222, ssh_options: {
  user: 'vagrant',
  keys: %w(~/.vagrant.d/insecure_private_key),
  auth_methods: %w(publickey)
}
