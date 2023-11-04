#!/bin/bash

protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./rc_service.proto
protoc -I . --cpp_out=. ./rc_service.proto
