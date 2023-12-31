// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: rc_service.proto
#ifndef GRPC_rc_5fservice_2eproto__INCLUDED
#define GRPC_rc_5fservice_2eproto__INCLUDED

#include "rc_service.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

class RCRobot final {
 public:
  static constexpr char const* service_full_name() {
    return "RCRobot";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Process(::grpc::ClientContext* context, const ::Command& request, ::Message* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>> AsyncProcess(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>>(AsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>> PrepareAsyncProcess(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>>(PrepareAsyncProcessRaw(context, request, cq));
    }
    virtual ::grpc::Status SendCommand(::grpc::ClientContext* context, const ::Command& request, ::_None* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::_None>> AsyncSendCommand(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::_None>>(AsyncSendCommandRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::_None>> PrepareAsyncSendCommand(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::_None>>(PrepareAsyncSendCommandRaw(context, request, cq));
    }
    virtual ::grpc::Status ReadData(::grpc::ClientContext* context, const ::_None& request, ::Message* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>> AsyncReadData(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>>(AsyncReadDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>> PrepareAsyncReadData(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Message>>(PrepareAsyncReadDataRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void Process(::grpc::ClientContext* context, const ::Command* request, ::Message* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Process(::grpc::ClientContext* context, const ::Command* request, ::Message* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void SendCommand(::grpc::ClientContext* context, const ::Command* request, ::_None* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SendCommand(::grpc::ClientContext* context, const ::Command* request, ::_None* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void ReadData(::grpc::ClientContext* context, const ::_None* request, ::Message* response, std::function<void(::grpc::Status)>) = 0;
      virtual void ReadData(::grpc::ClientContext* context, const ::_None* request, ::Message* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Message>* AsyncProcessRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Message>* PrepareAsyncProcessRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::_None>* AsyncSendCommandRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::_None>* PrepareAsyncSendCommandRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Message>* AsyncReadDataRaw(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Message>* PrepareAsyncReadDataRaw(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status Process(::grpc::ClientContext* context, const ::Command& request, ::Message* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>> AsyncProcess(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>>(AsyncProcessRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>> PrepareAsyncProcess(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>>(PrepareAsyncProcessRaw(context, request, cq));
    }
    ::grpc::Status SendCommand(::grpc::ClientContext* context, const ::Command& request, ::_None* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::_None>> AsyncSendCommand(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::_None>>(AsyncSendCommandRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::_None>> PrepareAsyncSendCommand(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::_None>>(PrepareAsyncSendCommandRaw(context, request, cq));
    }
    ::grpc::Status ReadData(::grpc::ClientContext* context, const ::_None& request, ::Message* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>> AsyncReadData(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>>(AsyncReadDataRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>> PrepareAsyncReadData(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Message>>(PrepareAsyncReadDataRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void Process(::grpc::ClientContext* context, const ::Command* request, ::Message* response, std::function<void(::grpc::Status)>) override;
      void Process(::grpc::ClientContext* context, const ::Command* request, ::Message* response, ::grpc::ClientUnaryReactor* reactor) override;
      void SendCommand(::grpc::ClientContext* context, const ::Command* request, ::_None* response, std::function<void(::grpc::Status)>) override;
      void SendCommand(::grpc::ClientContext* context, const ::Command* request, ::_None* response, ::grpc::ClientUnaryReactor* reactor) override;
      void ReadData(::grpc::ClientContext* context, const ::_None* request, ::Message* response, std::function<void(::grpc::Status)>) override;
      void ReadData(::grpc::ClientContext* context, const ::_None* request, ::Message* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::Message>* AsyncProcessRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Message>* PrepareAsyncProcessRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::_None>* AsyncSendCommandRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::_None>* PrepareAsyncSendCommandRaw(::grpc::ClientContext* context, const ::Command& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Message>* AsyncReadDataRaw(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Message>* PrepareAsyncReadDataRaw(::grpc::ClientContext* context, const ::_None& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Process_;
    const ::grpc::internal::RpcMethod rpcmethod_SendCommand_;
    const ::grpc::internal::RpcMethod rpcmethod_ReadData_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Process(::grpc::ServerContext* context, const ::Command* request, ::Message* response);
    virtual ::grpc::Status SendCommand(::grpc::ServerContext* context, const ::Command* request, ::_None* response);
    virtual ::grpc::Status ReadData(::grpc::ServerContext* context, const ::_None* request, ::Message* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Process() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestProcess(::grpc::ServerContext* context, ::Command* request, ::grpc::ServerAsyncResponseWriter< ::Message>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SendCommand() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendCommand(::grpc::ServerContext* context, ::Command* request, ::grpc::ServerAsyncResponseWriter< ::_None>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_ReadData() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestReadData(::grpc::ServerContext* context, ::_None* request, ::grpc::ServerAsyncResponseWriter< ::Message>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Process<WithAsyncMethod_SendCommand<WithAsyncMethod_ReadData<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_Process() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::Command, ::Message>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::Command* request, ::Message* response) { return this->Process(context, request, response); }));}
    void SetMessageAllocatorFor_Process(
        ::grpc::MessageAllocator< ::Command, ::Message>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Command, ::Message>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Process(
      ::grpc::CallbackServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SendCommand() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::Command, ::_None>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::Command* request, ::_None* response) { return this->SendCommand(context, request, response); }));}
    void SetMessageAllocatorFor_SendCommand(
        ::grpc::MessageAllocator< ::Command, ::_None>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::Command, ::_None>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendCommand(
      ::grpc::CallbackServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_ReadData() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::_None, ::Message>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::_None* request, ::Message* response) { return this->ReadData(context, request, response); }));}
    void SetMessageAllocatorFor_ReadData(
        ::grpc::MessageAllocator< ::_None, ::Message>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::_None, ::Message>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* ReadData(
      ::grpc::CallbackServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_Process<WithCallbackMethod_SendCommand<WithCallbackMethod_ReadData<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Process() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SendCommand() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_ReadData() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Process() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestProcess(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SendCommand() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSendCommand(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_ReadData() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestReadData(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_Process() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Process(context, request, response); }));
    }
    ~WithRawCallbackMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Process(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SendCommand() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SendCommand(context, request, response); }));
    }
    ~WithRawCallbackMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SendCommand(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_ReadData() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->ReadData(context, request, response); }));
    }
    ~WithRawCallbackMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* ReadData(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Process : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Process() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Command, ::Message>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Command, ::Message>* streamer) {
                       return this->StreamedProcess(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Process() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Process(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedProcess(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Command,::Message>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SendCommand : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SendCommand() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Command, ::_None>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::Command, ::_None>* streamer) {
                       return this->StreamedSendCommand(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SendCommand() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SendCommand(::grpc::ServerContext* /*context*/, const ::Command* /*request*/, ::_None* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSendCommand(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Command,::_None>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_ReadData : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_ReadData() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::_None, ::Message>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::_None, ::Message>* streamer) {
                       return this->StreamedReadData(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_ReadData() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status ReadData(::grpc::ServerContext* /*context*/, const ::_None* /*request*/, ::Message* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedReadData(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::_None,::Message>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Process<WithStreamedUnaryMethod_SendCommand<WithStreamedUnaryMethod_ReadData<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Process<WithStreamedUnaryMethod_SendCommand<WithStreamedUnaryMethod_ReadData<Service > > > StreamedService;
};


#endif  // GRPC_rc_5fservice_2eproto__INCLUDED
