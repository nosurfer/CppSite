# nginx_apache_coursework

## Description
This coursework presents a comparative analysis of security vulnerabilities in Apache and Nginx web servers, examining their configuration features including security headers setup and access parameter optimization, with an intentionally introduced SQL injection vulnerability to effectively demonstrate common flaws and detection methods, ultimately showcasing various aspects of server protection against typical attacks and highlighting the importance of proper configuration for building a secure web infrastructure.
## Deploy
1. Clone the repository
```bash
git clone https://github.com/nosurfer/nginx_apache_coursework.git
cd nginx_apache_coursework
```
2. Configure docker-compose.yaml:
- Select the server you want to test (comment out the other one);
- Configure the ports as needed for your environment;
- Adjust any other settings according to your testing requirements.
3. Add entries to your hosts file:
```bash
127.0.0.1 vulnerable1.com # for apache
127.0.0.1 vulnerable.com # for nginx
```
4. Launch docker compose:
```bash
docker compose up -d 
```
5. Access the web interface:
- https://vulnerable1.com (Apache configuration)
- https://vulnerable.com (Nginx configuration)
---
:triangular_flag_on_post: This project contains intentional vulnerabilities for educational purposes.

<!-- nosurfer -->
