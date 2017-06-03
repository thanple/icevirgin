// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CRequestFight.proto

#ifndef PROTOBUF_CRequestFight_2eproto__INCLUDED
#define PROTOBUF_CRequestFight_2eproto__INCLUDED

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
void  protobuf_AddDesc_CRequestFight_2eproto();
void protobuf_AssignDesc_CRequestFight_2eproto();
void protobuf_ShutdownFile_CRequestFight_2eproto();

class CRequestFight;

// ===================================================================

class CRequestFight : public ::google::protobuf::Message {
 public:
  CRequestFight();
  virtual ~CRequestFight();

  CRequestFight(const CRequestFight& from);

  inline CRequestFight& operator=(const CRequestFight& from) {
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
  static const CRequestFight& default_instance();

  void Swap(CRequestFight* other);

  // implements Message ----------------------------------------------

  CRequestFight* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CRequestFight& from);
  void MergeFrom(const CRequestFight& from);
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

  // required int32 fighthType = 1;
  inline bool has_fighthtype() const;
  inline void clear_fighthtype();
  static const int kFighthTypeFieldNumber = 1;
  inline ::google::protobuf::int32 fighthtype() const;
  inline void set_fighthtype(::google::protobuf::int32 value);

  // required int32 fighthId = 2;
  inline bool has_fighthid() const;
  inline void clear_fighthid();
  static const int kFighthIdFieldNumber = 2;
  inline ::google::protobuf::int32 fighthid() const;
  inline void set_fighthid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CRequestFight)
 private:
  inline void set_has_fighthtype();
  inline void clear_has_fighthtype();
  inline void set_has_fighthid();
  inline void clear_has_fighthid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 fighthtype_;
  ::google::protobuf::int32 fighthid_;
  friend void  protobuf_AddDesc_CRequestFight_2eproto();
  friend void protobuf_AssignDesc_CRequestFight_2eproto();
  friend void protobuf_ShutdownFile_CRequestFight_2eproto();

  void InitAsDefaultInstance();
  static CRequestFight* default_instance_;
};
// ===================================================================


// ===================================================================

// CRequestFight

// required int32 fighthType = 1;
inline bool CRequestFight::has_fighthtype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CRequestFight::set_has_fighthtype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CRequestFight::clear_has_fighthtype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CRequestFight::clear_fighthtype() {
  fighthtype_ = 0;
  clear_has_fighthtype();
}
inline ::google::protobuf::int32 CRequestFight::fighthtype() const {
  // @@protoc_insertion_point(field_get:CRequestFight.fighthType)
  return fighthtype_;
}
inline void CRequestFight::set_fighthtype(::google::protobuf::int32 value) {
  set_has_fighthtype();
  fighthtype_ = value;
  // @@protoc_insertion_point(field_set:CRequestFight.fighthType)
}

// required int32 fighthId = 2;
inline bool CRequestFight::has_fighthid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CRequestFight::set_has_fighthid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CRequestFight::clear_has_fighthid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CRequestFight::clear_fighthid() {
  fighthid_ = 0;
  clear_has_fighthid();
}
inline ::google::protobuf::int32 CRequestFight::fighthid() const {
  // @@protoc_insertion_point(field_get:CRequestFight.fighthId)
  return fighthid_;
}
inline void CRequestFight::set_fighthid(::google::protobuf::int32 value) {
  set_has_fighthid();
  fighthid_ = value;
  // @@protoc_insertion_point(field_set:CRequestFight.fighthId)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CRequestFight_2eproto__INCLUDED
