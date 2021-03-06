// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CLogin.proto

#ifndef PROTOBUF_CLogin_2eproto__INCLUDED
#define PROTOBUF_CLogin_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_CLogin_2eproto();
void protobuf_AssignDesc_CLogin_2eproto();
void protobuf_ShutdownFile_CLogin_2eproto();

class CLogin;

// ===================================================================

class CLogin : public ::google::protobuf::Message {
 public:
  CLogin();
  virtual ~CLogin();

  CLogin(const CLogin& from);

  inline CLogin& operator=(const CLogin& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CLogin& default_instance();

  void Swap(CLogin* other);

  // implements Message ----------------------------------------------

  CLogin* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CLogin& from);
  void MergeFrom(const CLogin& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // required string number = 3;
  inline bool has_number() const;
  inline void clear_number();
  static const int kNumberFieldNumber = 3;
  inline const ::std::string& number() const;
  inline void set_number(const ::std::string& value);
  inline void set_number(const char* value);
  inline void set_number(const char* value, size_t size);
  inline ::std::string* mutable_number();
  inline ::std::string* release_number();
  inline void set_allocated_number(::std::string* number);

  // @@protoc_insertion_point(class_scope:CLogin)
 private:
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_number();
  inline void clear_has_number();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* password_;
  ::std::string* number_;
  friend void  protobuf_AddDesc_CLogin_2eproto();
  friend void protobuf_AssignDesc_CLogin_2eproto();
  friend void protobuf_ShutdownFile_CLogin_2eproto();

  void InitAsDefaultInstance();
  static CLogin* default_instance_;
};
// ===================================================================


// ===================================================================

// CLogin

// required string password = 2;
inline bool CLogin::has_password() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CLogin::set_has_password() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CLogin::clear_has_password() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CLogin::clear_password() {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& CLogin::password() const {
  // @@protoc_insertion_point(field_get:CLogin.password)
  return *password_;
}
inline void CLogin::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set:CLogin.password)
}
inline void CLogin::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set_char:CLogin.password)
}
inline void CLogin::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:CLogin.password)
}
inline ::std::string* CLogin::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:CLogin.password)
  return password_;
}
inline ::std::string* CLogin::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void CLogin::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:CLogin.password)
}

// required string number = 3;
inline bool CLogin::has_number() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CLogin::set_has_number() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CLogin::clear_has_number() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CLogin::clear_number() {
  if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_->clear();
  }
  clear_has_number();
}
inline const ::std::string& CLogin::number() const {
  // @@protoc_insertion_point(field_get:CLogin.number)
  return *number_;
}
inline void CLogin::set_number(const ::std::string& value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set:CLogin.number)
}
inline void CLogin::set_number(const char* value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set_char:CLogin.number)
}
inline void CLogin::set_number(const char* value, size_t size) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:CLogin.number)
}
inline ::std::string* CLogin::mutable_number() {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:CLogin.number)
  return number_;
}
inline ::std::string* CLogin::release_number() {
  clear_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = number_;
    number_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void CLogin::set_allocated_number(::std::string* number) {
  if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete number_;
  }
  if (number) {
    set_has_number();
    number_ = number;
  } else {
    clear_has_number();
    number_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:CLogin.number)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CLogin_2eproto__INCLUDED
