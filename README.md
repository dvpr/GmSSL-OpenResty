### 运行
```
docker-compose up -d # 编译安装 GmSSL 2.5.4 和 OpenResty 1.19.3.1 并使用预置的SSL证书启动OpenResty
https://localhost # 使用支持国密证书的浏览器访问
```


### 生成自签名证书

##### 创建相关文件和目录
```
mkdir /usr/local/gmssl/ssl/newcerts
touch /usr/local/gmssl/ssl/index.txt
touch /usr/local/gmssl/ssl/serial
touch /usr/local/gmssl/ssl/crlnumber
echo '01' > /usr/local/gmssl/ssl/serial
echo '01' > /usr/local/gmssl/ssl/crlnumber
vi /usr/local/gmssl/ssl/openssl.cnf
dir = /usr/local/gmssl/ssl/
private_key = $dir/CA/rootca.key
certificate = $dir/CA/rootcasm2.cer
```

##### 自签发CA证书
```
gmssl ecparam -genkey -name SM2 -out /usr/local/gmssl/ssl/CA/rootca.key
gmssl req -new -x509 -sm3 -key /usr/local/gmssl/ssl/CA/rootca.key -out /usr/local/gmssl/ssl/CA/rootcasm2.cer -days 10000 -subj '/C=CN/O=HUB/OU=WUHAN_SM2'
```

##### server签名证书
```
gmssl ecparam -genkey -name SM2 -noout -out /usr/local/gmssl/ssl/CA/server.key
gmssl req -new -SM3 -key /usr/local/gmssl/ssl/CA/server.key -out /usr/local/gmssl/ssl/CA/server.csr -subj '/C=CN/O=HUB/OU=WUHAN_SM2/CN=www.test.com'
cd /usr/local/gmssl/ssl/CA/
gmssl x509 -req -SM3 -days 3650 -in server.csr -extfile ../openssl.cnf -extensions v3_req -CA rootcasm2.cer -CAkey rootca.key -set_serial 1000000001 -out server.cer
```

##### server加密证书
```
gmssl ecparam -genkey -name SM2 -noout -out server_en.key
gmssl req -new -SM3 -key server_en.key -out server1.csr -subj '/C=CN/O=HUB/OU=WUHAN_SM2/CN=www.test.com'
gmssl x509 -req -SM3 -days 3650 -in server1.csr -extfile ../openssl.cnf -extensions v3enc_req -CA rootcasm2.cer -CAkey rootca.key -set_serial 1000002001 -out server_en.cer
```

##### client签名证书
```
gmssl ecparam -genkey -name SM2 -noout -out client.key
gmssl req -new -key client.key -out client.req -subj "/C=CN/O=HUB/OU=WUHAN_SM2/CN=client"
gmssl x509 -req -SM3 -days 3650 -in client.req -extfile ../openssl.cnf -extensions v3_req -CA rootcasm2.cer -CAkey rootca.key -CAcreateserial  -out client.cer
```

##### client加密证书
```
gmssl ecparam -genkey -name SM2 -noout -out client_en.key
gmssl req -new -key client_en.key -out client_en.req -subj "/C=CN/O=HUB/OU=WUHAN_SM2/CN=client"
gmssl x509 -req -SM3 -days 3650 -in client_en.req -CA rootcasm2.cer -extfile ../openssl.cnf -extensions v3enc_req -CAkey rootca.key -CAcreateserial  -out client_en.cer
```