#!/bin/sh
echo -n "Remote host: "
read remote_host
echo -n "Remote host port: "
read remote_port
echo -n "Proxy host: "
read proxy_host
echo -n "Proxy port: "
read proxy_port
echo -n "Proxy username: "
read proxy_user
echo -n "Proxy password: "
read -s proxy_pass

ssh -o ProxyCommand="nc --proxy $proxy_host:$proxy_port --proxy-auth $proxy_user:$proxy_pass %h %p" $remote_host
#ssh -o ProxyCommand="nc --proxy 192.168.7.50:8080 --proxy-auth <user>:<pass> %h %p" $hostname
