#!/bin/sh
service postgresql start && service redis-server start && service gitlab start && service ssh start
exec nginx -g 'daemon off;'
