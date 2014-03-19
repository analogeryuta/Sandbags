#!/bin/sh
# Proxy settings

proxy='http://proxy.occ.co.jp:8080'

# wget
echo "http_proxy = $proxy"  >> /etc/wgetrc
echo "https_proxy = $proxy" >> /etc/wgetrc

# curl
echo "proxy = $proxy" >> /etc/curlrc

# System environement variable
echo "export http_proxy=$proxy"  >> /etc/environment
echo "export https_proxy=$proxy" >> /etc/environment

if [ -f /etc/system-release ]; then
  echo "proxy=$proxy" >> /etc/yum.conf
fi

if [ -f /etc/debian_version ]; then
  echo "Acquire::http::proxy \"$proxy\";"  >> /etc/apt/apt.conf.d/02proxy
  echo "Acquire::https::proxy \"$proxy\";" >> /etc/apt/apt.conf.d/02proxy
fi
