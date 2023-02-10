FROM centos:7

RUN sed -e 's|^mirrorlist=|#mirrorlist=|g' -e 's|^#baseurl=http://mirror.centos.org|baseurl=https://mirrors.tuna.tsinghua.edu.cn|g' -i.bak /etc/yum.repos.d/CentOS-*.repo
RUN yum update -y
RUN yum install -y perl gcc make pcre pcre-devel zlib zlib-devel openssl openssl-devel

COPY ./resources/GmSSL-2.5.4 /usr/local/GmSSL-master
WORKDIR /usr/local/GmSSL-master
RUN ./config --prefix=/usr/local/gmssl/
RUN make -j4
RUN make install

RUN ln -s /usr/local/gmssl/lib/libssl.so.1.1 /usr/lib64/libssl.so.1.1
RUN ln -s /usr/local/gmssl/lib/libcrypto.so.1.1 /usr/lib64/libcrypto.so.1.1
RUN ln -sv /usr/local/gmssl/bin/gmssl /usr/sbin/

RUN gmssl version

COPY ./resources/openresty-1.19.3.1 /usr/local/openresty
RUN sed -e 's|$OPENSSL/.openssl|$OPENSSL|g' -i.bak /usr/local/openresty/bundle/nginx-1.19.3/auto/lib/openssl/conf
RUN cat /usr/local/openresty/bundle/nginx-1.19.3/auto/lib/openssl/conf | grep $OPENSSL/
WORKDIR /usr/local/openresty
RUN ./configure --prefix=/usr/local/openresty/  --with-http_stub_status_module --with-http_ssl_module --with-openssl=/usr/local/gmssl/
RUN make -j4
RUN make install

ENV PATH=$PATH:/usr/local/openresty/luajit/bin:/usr/local/openresty/nginx/sbin:/usr/local/openresty/bin

# 有可能运行时，找不到libpcre.so.3做个软连接即可
RUN ln -s /usr/lib64/libpcre.so.1 /usr/lib64/libpcre.so.3

CMD ["/usr/local/openresty/bin/openresty", "-g", "daemon off;"]

STOPSIGNAL SIGQUIT