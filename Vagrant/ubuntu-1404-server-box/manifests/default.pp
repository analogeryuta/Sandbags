### load path settings
Exec {
  path => "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
}

exec { "apt-get update":
  command => "apt-get update"
}

exec { "apt-get upgrade":
  command => "apt-get upgrade -y",
  require => Exec["apt-get update"]
}

### Install development packages
$development_packages = [
  "ntp",
  "zsh",
  "vim",
  "git",
  "ruby",
  "emacs"
]

package { $development_packages:
  ensure => latest,
  require => Exec["apt-get upgrade"]
}

### Install dependency RubyGem
#package { "bundler":
#  provider => "gem",
#  require => Package[$development_packages]
#}

### Install rbenv environment (on vagrant user.)
exec { "fetch-rbenv":
  user => "vagrant",
  group => "vagrant",
  cwd => "/home/vagrant",
  command => "git clone https://github.com/sstephenson/rbenv.git .rbenv",
  require => Package[$development_packages]
}

### Setup shell's path for rbenv
exec { "set-rbenv-path":
  user => "vagrant",
  group => "vagrant",
  cwd => "/home/vagrant",
  command => "echo \'export PATH=\"\$HOME/.rbenv/bin:\$PATH\"\' >> .bash_profile",
  require => Exec["fetch-rbenv"]
}

### Setup rbenv shims
exec { "set-rbenv-shims":
  user => "vagrant",
  group => "vagrant",
  cwd => "/home/vagrant",
  command => "echo \'eval \"\$(rbenv init -)\"\' >> .bash_profile",
  require => Exec["set-rbenv-path"]
}

### Install ruby-build(rbenv's plugin).
exec { "fetch-ruby-build":
  user => "vagrant",
  group => "vagrant",
  cwd => "/home/vagrant",
  command => "git clone https://github.com/sstephenson/ruby-build.git .rbenv/plugins/ruby-build",
  require => Exec["set-rbenv-shims"]
}
