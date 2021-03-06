// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CCreateRole.proto

#ifndef PROTOBUF_CCreateRole_2eproto__INCLUDED
#define PROTOBUF_CCreateRole_2eproto__INCLUDED

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
void  protobuf_AddDesc_CCreateRole_2eproto();
void protobuf_AssignDesc_CCreateRole_2eproto();
void protobuf_ShutdownFile_CCreateRole_2eproto();

class CCreateRole;

// ===================================================================

class CCreateRole : public ::google::protobuf::Message {
 public:
  CCreateRole();
  virtual ~CCreateRole();

  CCreateRole(const CCreateRole& from);

  inline CCreateRole& operator=(const CCreateRole& from) {
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
  static const CCreateRole& default_instance();

  void Swap(CCreateRole* other);

  // implements Message ----------------------------------------------

  CCreateRole* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CCreateRole& from);
  void MergeFrom(const CCreateRole& from);
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

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

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

  // required int32 hair = 4;
  inline bool has_hair() const;
  inline void clear_hair();
  static const int kHairFieldNumber = 4;
  inline ::google::protobuf::int32 hair() const;
  inline void set_hair(::google::protobuf::int32 value);

  // required int32 body = 5;
  inline bool has_body() const;
  inline void clear_body();
  static const int kBodyFieldNumber = 5;
  inline ::google::protobuf::int32 body() const;
  inline void set_body(::google::protobuf::int32 value);

  // required int32 weapon = 6;
  inline bool has_weapon() const;
  inline void clear_weapon();
  static const int kWeaponFieldNumber = 6;
  inline ::google::protobuf::int32 weapon() const;
  inline void set_weapon(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CCreateRole)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_number();
  inline void clear_has_number();
  inline void set_has_hair();
  inline void clear_has_hair();
  inline void set_has_body();
  inline void clear_has_body();
  inline void set_has_weapon();
  inline void clear_has_weapon();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* name_;
  ::std::string* password_;
  ::std::string* number_;
  ::google::protobuf::int32 hair_;
  ::google::protobuf::int32 body_;
  ::google::protobuf::int32 weapon_;
  friend void  protobuf_AddDesc_CCreateRole_2eproto();
  friend void protobuf_AssignDesc_CCreateRole_2eproto();
  friend void protobuf_ShutdownFile_CCreateRole_2eproto();

  void InitAsDefaultInstance();
  static CCreateRole* default_instance_;
};
// ===================================================================


// ===================================================================

// CCreateRole

// required string name = 1;
inline bool CCreateRole::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CCreateRole::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CCreateRole::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CCreateRole::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& CCreateRole::name() const {
  // @@protoc_insertion_point(field_get:CCreateRole.name)
  return *name_;
}
inline void CCreateRole::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:CCreateRole.name)
}
inline void CCreateRole::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:CCreateRole.name)
}
inline void CCreateRole::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:CCreateRole.name)
}
inline ::std::string* CCreateRole::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:CCreateRole.name)
  return name_;
}
inline ::std::string* CCreateRole::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void CCreateRole::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:CCreateRole.name)
}

// required string password = 2;
inline bool CCreateRole::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CCreateRole::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CCreateRole::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CCreateRole::clear_password() {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& CCreateRole::password() const {
  // @@protoc_insertion_point(field_get:CCreateRole.password)
  return *password_;
}
inline void CCreateRole::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set:CCreateRole.password)
}
inline void CCreateRole::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set_char:CCreateRole.password)
}
inline void CCreateRole::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:CCreateRole.password)
}
inline ::std::string* CCreateRole::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:CCreateRole.password)
  return password_;
}
inline ::std::string* CCreateRole::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void CCreateRole::set_allocated_password(::std::string* password) {
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
  // @@protoc_insertion_point(field_set_allocated:CCreateRole.password)
}

// required string number = 3;
inline bool CCreateRole::has_number() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CCreateRole::set_has_number() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CCreateRole::clear_has_number() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CCreateRole::clear_number() {
  if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_->clear();
  }
  clear_has_number();
}
inline const ::std::string& CCreateRole::number() const {
  // @@protoc_insertion_point(field_get:CCreateRole.number)
  return *number_;
}
inline void CCreateRole::set_number(const ::std::string& value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set:CCreateRole.number)
}
inline void CCreateRole::set_number(const char* value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set_char:CCreateRole.number)
}
inline void CCreateRole::set_number(const char* value, size_t size) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:CCreateRole.number)
}
inline ::std::string* CCreateRole::mutable_number() {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:CCreateRole.number)
  return number_;
}
inline ::std::string* CCreateRole::release_number() {
  clear_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = number_;
    number_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void CCreateRole::set_allocated_number(::std::string* number) {
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
  // @@protoc_insertion_point(field_set_allocated:CCreateRole.number)
}

// required int32 hair = 4;
inline bool CCreateRole::has_hair() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CCreateRole::set_has_hair() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CCreateRole::clear_has_hair() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CCreateRole::clear_hair() {
  hair_ = 0;
  clear_has_hair();
}
inline ::google::protobuf::int32 CCreateRole::hair() const {
  // @@protoc_insertion_point(field_get:CCreateRole.hair)
  return hair_;
}
inline void CCreateRole::set_hair(::google::protobuf::int32 value) {
  set_has_hair();
  hair_ = value;
  // @@protoc_insertion_point(field_set:CCreateRole.hair)
}

// required int32 body = 5;
inline bool CCreateRole::has_body() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void CCreateRole::set_has_body() {
  _has_bits_[0] |= 0x00000010u;
}
inline void CCreateRole::clear_has_body() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void CCreateRole::clear_body() {
  body_ = 0;
  clear_has_body();
}
inline ::google::protobuf::int32 CCreateRole::body() const {
  // @@protoc_insertion_point(field_get:CCreateRole.body)
  return body_;
}
inline void CCreateRole::set_body(::google::protobuf::int32 value) {
  set_has_body();
  body_ = value;
  // @@protoc_insertion_point(field_set:CCreateRole.body)
}

// required int32 weapon = 6;
inline bool CCreateRole::has_weapon() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void CCreateRole::set_has_weapon() {
  _has_bits_[0] |= 0x00000020u;
}
inline void CCreateRole::clear_has_weapon() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void CCreateRole::clear_weapon() {
  weapon_ = 0;
  clear_has_weapon();
}
inline ::google::protobuf::int32 CCreateRole::weapon() const {
  // @@protoc_insertion_point(field_get:CCreateRole.weapon)
  return weapon_;
}
inline void CCreateRole::set_weapon(::google::protobuf::int32 value) {
  set_has_weapon();
  weapon_ = value;
  // @@protoc_insertion_point(field_set:CCreateRole.weapon)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CCreateRole_2eproto__INCLUDED
