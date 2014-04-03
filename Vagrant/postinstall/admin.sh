#!/bin/sh
# admin user settings

# Add the admin user
useradd -m -g adm -s /bin/bash admin -p '$1$RCNCPxGr$Dsq1rMqPgv5nGpWRNIO47/'

# Setting sudoers for admin
echo "%adm	ALL=(ALL) ALL" > /etc/sudoers.d/admin
chmod 0440 /etc/sudoers.d/admin

# Setting ssh keys
mkdir -pm 700 /home/admin/.ssh
wget --no-check-certificate 'https://github.com/wm-dev.keys' -O /home/admin/.ssh/authorized_keys
chmod 0600 /home/admin/.ssh/authorized_keys
chown -R admin:adm /home/admin/.ssh
