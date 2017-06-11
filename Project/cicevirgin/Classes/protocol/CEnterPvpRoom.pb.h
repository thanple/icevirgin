// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CEnterPvpRoom.proto

#ifndef PROTOBUF_CEnterPvpRoom_2eproto__INCLUDED
#define PROTOBUF_CEnterPvpRoom_2eproto__INCLUDED

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
void  protobuf_AddDesc_CEnterPvpRoom_2eproto();
void protobuf_AssignDesc_CEnterPvpRoom_2eproto();
void protobuf_ShutdownFile_CEnterPvpRoom_2eproto();

class CEnterPvpRoom;

// ===================================================================

class CEnterPvpRoom : public ::google::protobuf::Message {
 public:
  CEnterPvpRoom();
  virtual ~CEnterPvpRoom();

  CEnterPvpRoom(const CEnterPvpRoom& from);

  inline CEnterPvpRoom& operator=(const CEnterPvpRoom& from) {
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
  static const CEnterPvpRoom& default_instance();

  void Swap(CEnterPvpRoom* other);

  // implements Message ----------------------------------------------

  CEnterPvpRoom* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CEnterPvpRoom& from);
  void MergeFrom(const CEnterPvpRoom& from);
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

  // required int32 instanceId = 1;
  inline bool has_instanceid() const;
  inline void clear_instanceid();
  static const int kInstanceIdFieldNumber = 1;
  inline ::google::protobuf::int32 instanceid() const;
  inline void set_instanceid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CEnterPvpRoom)
 private:
  inline void set_has_instanceid();
  inline void clear_has_instanceid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 instanceid_;
  friend void  protobuf_AddDesc_CEnterPvpRoom_2eproto();
  friend void protobuf_AssignDesc_CEnterPvpRoom_2eproto();
  friend void protobuf_ShutdownFile_CEnterPvpRoom_2eproto();

  void InitAsDefaultInstance();
  static CEnterPvpRoom* default_instance_;
};
// ===================================================================


// ===================================================================

// CEnterPvpRoom

// required int32 instanceId = 1;
inline bool CEnterPvpRoom::has_instanceid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CEnterPvpRoom::set_has_instanceid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CEnterPvpRoom::clear_has_instanceid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CEnterPvpRoom::clear_instanceid() {
  instanceid_ = 0;
  clear_has_instanceid();
}
inline ::google::protobuf::int32 CEnterPvpRoom::instanceid() const {
  // @@protoc_insertion_point(field_get:CEnterPvpRoom.instanceId)
  return instanceid_;
}
inline void CEnterPvpRoom::set_instanceid(::google::protobuf::int32 value) {
  set_has_instanceid();
  instanceid_ = value;
  // @@protoc_insertion_point(field_set:CEnterPvpRoom.instanceId)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CEnterPvpRoom_2eproto__INCLUDED