# Claudius

## DB Setup 
### Install
install odbc `sudo apt-get install unixodbc-dev unixodbc-bin unixodbc`

install mysql odbc driver `sudo apt-get install libmyodbc`

Find the mysql driver and setup `find /usr/lib -name 'lib*odbc*.so'`

In my case they are:
`/usr/lib/x86_64-linux-gnu/odbc/libmyodbc.so`
`/usr/lib/x86_64-linux-gnu/odbc/libodbcmyS.so`

### Setup Driver 
Helpful link to understand drivers and templates http://www.unixodbc.org/odbcinst.html

Edit contents of `/etc/odbcinst.ini`
```
[MySQL]
Driver = /usr/lib/x86_64-linux-gnu/odbc/libmyodbc.so
Setup = /usr/lib/x86_64-linux-gnu/odbc/libodbcmyS.so
Description  = MySQL driver
FileUsage = 1
```

Edit contents of `~/odbc_template`
```
[MySQL]
Driver = /usr/lib/x86_64-linux-gnu/odbc/libmyodbc.so
Setup = /usr/lib/x86_64-linux-gnu/odbc/libodbcmyS.so
Description  = MySQL driver
```
Finally to install driver `odbcinst -i -d -f ~/odbc_template`
