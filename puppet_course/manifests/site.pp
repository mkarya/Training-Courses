import 'classes/*.pp'

class toolbox {
        file { '/usr/local/sbin/puppetsimple.sh':
                owner => root, group => root, mode => 0755,
                content => "#!/bin/bash\npuppet agent --no-daemonize --onetime --verbose\n",
              }
        file {'example.sh':
                mode => 0755,
                path => '/home/mukesh_arya24/example.sh',
                ensure => file,
                owner => mukesh_arya24,
                group => mukesh_arya24,
                source => '/root/example.sh',
        }
}

node 'puppetagent.c.micro-reserve-139808.internal' {
        include toolbox
        include ntp_service
}
