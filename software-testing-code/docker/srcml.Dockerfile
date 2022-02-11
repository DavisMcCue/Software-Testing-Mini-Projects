FROM ubuntu:latest    

WORKDIR /usr/src/app

RUN apt update
RUN apt -yq install g++ libxml2-dev libxslt1-dev libarchive-dev antlr libantlr-dev libcurl4-openssl-dev libssl-dev cmake python
RUN apt -yq install wget

RUN wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2
RUN tar xvf boost_1_71_0.tar.bz2
RUN cd boost_1_71_0 && \
	./bootstrap.sh --without-libraries=atomic,chrono,context,coroutine,exception,graph,graph_parallel,iostreams,locale,log,math,mpi,python,random,serialization,test,timer,wave && \
	./b2 link=static cxxflags="-fPIC -static -Wl,--whole-archive" threading=multi install

COPY . .

RUN mkdir build && cd build && cmake ../ && make -j4 && make install
RUN cp /usr/local/lib/libsrcml* /usr/lib/

ENTRYPOINT [ "srcml" ]
