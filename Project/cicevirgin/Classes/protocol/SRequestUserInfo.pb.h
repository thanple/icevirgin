// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SRequestUserInfo.proto

#ifndef PROTOBUF_SRequestUserInfo_2eproto__INCLUDED
#define PROTOBUF_SRequestUserInfo_2eproto__INCLUDED

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
void  protobuf_AddDesc_SRequestUserInfo_2eproto();
void protobuf_AssignDesc_SRequestUserInfo_2eproto();
void protobuf_ShutdownFile_SRequestUserInfo_2eproto();

class SRequestUserInfo;

// ===================================================================

class SRequestUserInfo : public ::google::protobuf::Message {
 public:
  SRequestUserInfo();
  virtual ~SRequestUserInfo();

  SRequestUserInfo(const SRequestUserInfo& from);

  inline SRequestUserInfo& operator=(const SRequestUserInfo& from) {
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
  static const SRequestUserInfo& default_instance();

  void Swap(SRequestUserInfo* other);

  // implements Message ----------------------------------------------

  SRequestUserInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SRequestUserInfo& from);
  void MergeFrom(const SRequestUserInfo& from);
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

  // required int32 id = 2;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 2;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

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

  // required int32 money = 7;
  inline bool has_money() const;
  inline void clear_money();
  static const int kMoneyFieldNumber = 7;
  inline ::google::protobuf::int32 money() const;
  inline void set_money(::google::protobuf::int32 value);

  // required int32 nskill = 8;
  inline bool has_nskill() const;
  inline void clear_nskill();
  static const int kNskillFieldNumber = 8;
  inline ::google::protobuf::int32 nskill() const;
  inline void set_nskill(::google::protobuf::int32 value);

  // required int32 exp = 9;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 9;
  inline ::google::protobuf::int32 exp() const;
  inline void set_exp(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:SRequestUserInfo)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_number();
  inline void clear_has_number();
  inline void set_has_hair();
  inline void clear_has_hair();
  inline void set_has_body();
  inline void clear_has_body();
  inline void set_has_weapon();
  inline void clear_has_weapon();
  inline void set_has_money();
  inline void clear_has_money();
  inline void set_has_nskill();
  inline void clear_has_nskill();
  inline void set_has_exp();
  inline void clear_has_exp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* name_;
  ::std::string* number_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 hair_;
  ::google::protobuf::int32 body_;
  ::google::protobuf::int32 weapon_;
  ::google::protobuf::int32 money_;
  ::google::protobuf::int32 nskill_;
  ::google::protobuf::int32 exp_;
  friend void  protobuf_AddDesc_SRequestUserInfo_2eproto();
  friend void protobuf_AssignDesc_SRequestUserInfo_2eproto();
  friend void protobuf_ShutdownFile_SRequestUserInfo_2eproto();

  void InitAsDefaultInstance();
  static SRequestUserInfo* default_instance_;
};
// ===================================================================


// ===================================================================

// SRequestUserInfo

// required string name = 1;
inline bool SRequestUserInfo::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SRequestUserInfo::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SRequestUserInfo::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SRequestUserInfo::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& SRequestUserInfo::name() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.name)
  return *name_;
}
inline void SRequestUserInfo::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:SRequestUserInfo.name)
}
inline void SRequestUserInfo::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:SRequestUserInfo.name)
}
inline void SRequestUserInfo::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SRequestUserInfo.name)
}
inline ::std::string* SRequestUserInfo::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SRequestUserInfo.name)
  return name_;
}
inline ::std::string* SRequestUserInfo::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SRequestUserInfo::set_allocated_name(::std::string* name) {
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
  // @@protoc_insertion_point(field_set_allocated:SRequestUserInfo.name)
}

// required int32 id = 2;
inline bool SRequestUserInfo::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SRequestUserInfo::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SRequestUserInfo::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SRequestUserInfo::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 SRequestUserInfo::id() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.id)
  return id_;
}
inline void SRequestUserInfo::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.id)
}

// required string number = 3;
inline bool SRequestUserInfo::has_number() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SRequestUserInfo::set_has_number() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SRequestUserInfo::clear_has_number() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SRequestUserInfo::clear_number() {
  if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_->clear();
  }
  clear_has_number();
}
inline const ::std::string& SRequestUserInfo::number() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.number)
  return *number_;
}
inline void SRequestUserInfo::set_number(const ::std::string& value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set:SRequestUserInfo.number)
}
inline void SRequestUserInfo::set_number(const char* value) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(value);
  // @@protoc_insertion_point(field_set_char:SRequestUserInfo.number)
}
inline void SRequestUserInfo::set_number(const char* value, size_t size) {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  number_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SRequestUserInfo.number)
}
inline ::std::string* SRequestUserInfo::mutable_number() {
  set_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    number_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SRequestUserInfo.number)
  return number_;
}
inline ::std::string* SRequestUserInfo::release_number() {
  clear_has_number();
  if (number_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = number_;
    number_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SRequestUserInfo::set_allocated_number(::std::string* number) {
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
  // @@protoc_insertion_point(field_set_allocated:SRequestUserInfo.number)
}

// required int32 hair = 4;
inline bool SRequestUserInfo::has_hair() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SRequestUserInfo::set_has_hair() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SRequestUserInfo::clear_has_hair() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SRequestUserInfo::clear_hair() {
  hair_ = 0;
  clear_has_hair();
}
inline ::google::protobuf::int32 SRequestUserInfo::hair() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.hair)
  return hair_;
}
inline void SRequestUserInfo::set_hair(::google::protobuf::int32 value) {
  set_has_hair();
  hair_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.hair)
}

// required int32 body = 5;
inline bool SRequestUserInfo::has_body() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SRequestUserInfo::set_has_body() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SRequestUserInfo::clear_has_body() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SRequestUserInfo::clear_body() {
  body_ = 0;
  clear_has_body();
}
inline ::google::protobuf::int32 SRequestUserInfo::body() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.body)
  return body_;
}
inline void SRequestUserInfo::set_body(::google::protobuf::int32 value) {
  set_has_body();
  body_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.body)
}

// required int32 weapon = 6;
inline bool SRequestUserInfo::has_weapon() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void SRequestUserInfo::set_has_weapon() {
  _has_bits_[0] |= 0x00000020u;
}
inline void SRequestUserInfo::clear_has_weapon() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void SRequestUserInfo::clear_weapon() {
  weapon_ = 0;
  clear_has_weapon();
}
inline ::google::protobuf::int32 SRequestUserInfo::weapon() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.weapon)
  return weapon_;
}
inline void SRequestUserInfo::set_weapon(::google::protobuf::int32 value) {
  set_has_weapon();
  weapon_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.weapon)
}

// required int32 money = 7;
inline bool SRequestUserInfo::has_money() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void SRequestUserInfo::set_has_money() {
  _has_bits_[0] |= 0x00000040u;
}
inline void SRequestUserInfo::clear_has_money() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void SRequestUserInfo::clear_money() {
  money_ = 0;
  clear_has_money();
}
inline ::google::protobuf::int32 SRequestUserInfo::money() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.money)
  return money_;
}
inline void SRequestUserInfo::set_money(::google::protobuf::int32 value) {
  set_has_money();
  money_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.money)
}

// required int32 nskill = 8;
inline bool SRequestUserInfo::has_nskill() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void SRequestUserInfo::set_has_nskill() {
  _has_bits_[0] |= 0x00000080u;
}
inline void SRequestUserInfo::clear_has_nskill() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void SRequestUserInfo::clear_nskill() {
  nskill_ = 0;
  clear_has_nskill();
}
inline ::google::protobuf::int32 SRequestUserInfo::nskill() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.nskill)
  return nskill_;
}
inline void SRequestUserInfo::set_nskill(::google::protobuf::int32 value) {
  set_has_nskill();
  nskill_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.nskill)
}

// required int32 exp = 9;
inline bool SRequestUserInfo::has_exp() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void SRequestUserInfo::set_has_exp() {
  _has_bits_[0] |= 0x00000100u;
}
inline void SRequestUserInfo::clear_has_exp() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void SRequestUserInfo::clear_exp() {
  exp_ = 0;
  clear_has_exp();
}
inline ::google::protobuf::int32 SRequestUserInfo::exp() const {
  // @@protoc_insertion_point(field_get:SRequestUserInfo.exp)
  return exp_;
}
inline void SRequestUserInfo::set_exp(::google::protobuf::int32 value) {
  set_has_exp();
  exp_ = value;
  // @@protoc_insertion_point(field_set:SRequestUserInfo.exp)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_SRequestUserInfo_2eproto__INCLUDED
