# CppSite

openssl req -x509 -days 365 -nodes -newkey rsa:2048 -subj /CN=aboba/countryName=RU/stateOrProvinceName=abobus/organizationName=aboba -keyout ./nginx-selfsigned.key -text -out ./nginx-selfsigned.crt