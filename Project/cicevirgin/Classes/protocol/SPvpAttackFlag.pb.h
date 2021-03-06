// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SPvpAttackFlag.proto

#ifndef PROTOBUF_SPvpAttackFlag_2eproto__INCLUDED
#define PROTOBUF_SPvpAttackFlag_2eproto__INCLUDED

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
void  protobuf_AddDesc_SPvpAttackFlag_2eproto();
void protobuf_AssignDesc_SPvpAttackFlag_2eproto();
void protobuf_ShutdownFile_SPvpAttackFlag_2eproto();

class SPvpAttackFlag;

// ===================================================================

class SPvpAttackFlag : public ::google::protobuf::Message {
 public:
  SPvpAttackFlag();
  virtual ~SPvpAttackFlag();

  SPvpAttackFlag(const SPvpAttackFlag& from);

  inline SPvpAttackFlag& operator=(const SPvpAttackFlag& from) {
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
  static const SPvpAttackFlag& default_instance();

  void Swap(SPvpAttackFlag* other);

  // implements Message ----------------------------------------------

  SPvpAttackFlag* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SPvpAttackFlag& from);
  void MergeFrom(const SPvpAttackFlag& from);
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

  // required int32 skillType = 1;
  inline bool has_skilltype() const;
  inline void clear_skilltype();
  static const int kSkillTypeFieldNumber = 1;
  inline ::google::protobuf::int32 skilltype() const;
  inline void set_skilltype(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:SPvpAttackFlag)
 private:
  inline void set_has_skilltype();
  inline void clear_has_skilltype();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 skilltype_;
  friend void  protobuf_AddDesc_SPvpAttackFlag_2eproto();
  friend void protobuf_AssignDesc_SPvpAttackFlag_2eproto();
  friend void protobuf_ShutdownFile_SPvpAttackFlag_2eproto();

  void InitAsDefaultInstance();
  static SPvpAttackFlag* default_instance_;
};
// ===================================================================


// ===================================================================

// SPvpAttackFlag

// required int32 skillType = 1;
inline bool SPvpAttackFlag::has_skilltype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SPvpAttackFlag::set_has_skilltype() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SPvpAttackFlag::clear_has_skilltype() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SPvpAttackFlag::clear_skilltype() {
  skilltype_ = 0;
  clear_has_skilltype();
}
inline ::google::protobuf::int32 SPvpAttackFlag::skilltype() const {
  // @@protoc_insertion_point(field_get:SPvpAttackFlag.skillType)
  return skilltype_;
}
inline void SPvpAttackFlag::set_skilltype(::google::protobuf::int32 value) {
  set_has_skilltype();
  skilltype_ = value;
  // @@protoc_insertion_point(field_set:SPvpAttackFlag.skillType)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_SPvpAttackFlag_2eproto__INCLUDED
