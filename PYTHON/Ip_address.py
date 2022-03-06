import socket


def ip_address():
  
  #Get the address
  site = input('Enter the site address: ')
  
  #Find out the IP
  ip = socket.gethostbyname_ex(site)

  # Result
  print('\nSite: {0}\n'.format(site))
  for ip_adress in ip[2]:
    print(ip_adress)


ip_address()
