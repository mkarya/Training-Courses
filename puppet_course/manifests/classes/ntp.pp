class ntp_service {
        package { 'ntp':
          ensure => installed,
        }

        service { 'ntp':
          name      => $service_name,
          ensure    => running,
          enable    => true,
          subscribe => File['ntp.conf'],
        }

        file { 'ntp.conf':
          path    => '/etc/ntp.conf',
          ensure  => file,
          require => Package['ntp'],
          #source  => "puppet:///modules/ntp/ntp.conf",
          # This source file would be located on the Puppet master at
          # /etc/puppetlabs/code/modules/ntp/files/ntp.conf
        }
}
