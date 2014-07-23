#
# rik-test: test server on RIK cloud.
#
server "rik-test", roles: %w{web}, ssh_options: {
  user: 'admin',
  forward_agent: true,
  keys: %w(~/.ssh/id_rsa-wm),
  auth_methods: %w(publickey)
}