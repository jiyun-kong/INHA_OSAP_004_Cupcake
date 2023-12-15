FROM ubuntu:latest
RUN apt-get -qq update \
&& apt-get -qq install -y g++ cmake \
&& apt-get clean

EXPOSE 8000
ENTRYPOINT ["/bin/bash"]
