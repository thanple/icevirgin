// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SRequestPvpRooms.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "SRequestPvpRooms.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* SRequestPvpRooms_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SRequestPvpRooms_reflection_ = NULL;
const ::google::protobuf::Descriptor* SRequestPvpRooms_Item_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SRequestPvpRooms_Item_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_SRequestPvpRooms_2eproto() {
  protobuf_AddDesc_SRequestPvpRooms_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "SRequestPvpRooms.proto");
  GOOGLE_CHECK(file != NULL);
  SRequestPvpRooms_descriptor_ = file->message_type(0);
  static const int SRequestPvpRooms_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms, rooms_),
  };
  SRequestPvpRooms_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SRequestPvpRooms_descriptor_,
      SRequestPvpRooms::default_instance_,
      SRequestPvpRooms_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SRequestPvpRooms));
  SRequestPvpRooms_Item_descriptor_ = SRequestPvpRooms_descriptor_->nested_type(0);
  static const int SRequestPvpRooms_Item_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms_Item, instanceid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms_Item, status_),
  };
  SRequestPvpRooms_Item_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SRequestPvpRooms_Item_descriptor_,
      SRequestPvpRooms_Item::default_instance_,
      SRequestPvpRooms_Item_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms_Item, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SRequestPvpRooms_Item, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SRequestPvpRooms_Item));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_SRequestPvpRooms_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SRequestPvpRooms_descriptor_, &SRequestPvpRooms::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SRequestPvpRooms_Item_descriptor_, &SRequestPvpRooms_Item::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_SRequestPvpRooms_2eproto() {
  delete SRequestPvpRooms::default_instance_;
  delete SRequestPvpRooms_reflection_;
  delete SRequestPvpRooms_Item::default_instance_;
  delete SRequestPvpRooms_Item_reflection_;
}

void protobuf_AddDesc_SRequestPvpRooms_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026SRequestPvpRooms.proto\"e\n\020SRequestPvpR"
    "ooms\022%\n\005rooms\030\001 \003(\0132\026.SRequestPvpRooms.I"
    "tem\032*\n\004Item\022\022\n\ninstanceId\030\001 \002(\005\022\016\n\006statu"
    "s\030\002 \002(\005B7\n\"com.thanple.gs.common.nio.pro"
    "tocolB\021_SRequestPvpRooms", 184);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "SRequestPvpRooms.proto", &protobuf_RegisterTypes);
  SRequestPvpRooms::default_instance_ = new SRequestPvpRooms();
  SRequestPvpRooms_Item::default_instance_ = new SRequestPvpRooms_Item();
  SRequestPvpRooms::default_instance_->InitAsDefaultInstance();
  SRequestPvpRooms_Item::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_SRequestPvpRooms_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_SRequestPvpRooms_2eproto {
  StaticDescriptorInitializer_SRequestPvpRooms_2eproto() {
    protobuf_AddDesc_SRequestPvpRooms_2eproto();
  }
} static_descriptor_initializer_SRequestPvpRooms_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SRequestPvpRooms_Item::kInstanceIdFieldNumber;
const int SRequestPvpRooms_Item::kStatusFieldNumber;
#endif  // !_MSC_VER

SRequestPvpRooms_Item::SRequestPvpRooms_Item()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SRequestPvpRooms.Item)
}

void SRequestPvpRooms_Item::InitAsDefaultInstance() {
}

SRequestPvpRooms_Item::SRequestPvpRooms_Item(const SRequestPvpRooms_Item& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SRequestPvpRooms.Item)
}

void SRequestPvpRooms_Item::SharedCtor() {
  _cached_size_ = 0;
  instanceid_ = 0;
  status_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SRequestPvpRooms_Item::~SRequestPvpRooms_Item() {
  // @@protoc_insertion_point(destructor:SRequestPvpRooms.Item)
  SharedDtor();
}

void SRequestPvpRooms_Item::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SRequestPvpRooms_Item::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SRequestPvpRooms_Item::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SRequestPvpRooms_Item_descriptor_;
}

const SRequestPvpRooms_Item& SRequestPvpRooms_Item::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SRequestPvpRooms_2eproto();
  return *default_instance_;
}

SRequestPvpRooms_Item* SRequestPvpRooms_Item::default_instance_ = NULL;

SRequestPvpRooms_Item* SRequestPvpRooms_Item::New() const {
  return new SRequestPvpRooms_Item;
}

void SRequestPvpRooms_Item::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<SRequestPvpRooms_Item*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(instanceid_, status_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SRequestPvpRooms_Item::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SRequestPvpRooms.Item)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 instanceId = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &instanceid_)));
          set_has_instanceid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_status;
        break;
      }

      // required int32 status = 2;
      case 2: {
        if (tag == 16) {
         parse_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &status_)));
          set_has_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SRequestPvpRooms.Item)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SRequestPvpRooms.Item)
  return false;
#undef DO_
}

void SRequestPvpRooms_Item::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SRequestPvpRooms.Item)
  // required int32 instanceId = 1;
  if (has_instanceid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->instanceid(), output);
  }

  // required int32 status = 2;
  if (has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->status(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SRequestPvpRooms.Item)
}

::google::protobuf::uint8* SRequestPvpRooms_Item::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SRequestPvpRooms.Item)
  // required int32 instanceId = 1;
  if (has_instanceid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->instanceid(), target);
  }

  // required int32 status = 2;
  if (has_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->status(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SRequestPvpRooms.Item)
  return target;
}

int SRequestPvpRooms_Item::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 instanceId = 1;
    if (has_instanceid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->instanceid());
    }

    // required int32 status = 2;
    if (has_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->status());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SRequestPvpRooms_Item::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SRequestPvpRooms_Item* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SRequestPvpRooms_Item*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SRequestPvpRooms_Item::MergeFrom(const SRequestPvpRooms_Item& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_instanceid()) {
      set_instanceid(from.instanceid());
    }
    if (from.has_status()) {
      set_status(from.status());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SRequestPvpRooms_Item::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SRequestPvpRooms_Item::CopyFrom(const SRequestPvpRooms_Item& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SRequestPvpRooms_Item::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void SRequestPvpRooms_Item::Swap(SRequestPvpRooms_Item* other) {
  if (other != this) {
    std::swap(instanceid_, other->instanceid_);
    std::swap(status_, other->status_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SRequestPvpRooms_Item::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SRequestPvpRooms_Item_descriptor_;
  metadata.reflection = SRequestPvpRooms_Item_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int SRequestPvpRooms::kRoomsFieldNumber;
#endif  // !_MSC_VER

SRequestPvpRooms::SRequestPvpRooms()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SRequestPvpRooms)
}

void SRequestPvpRooms::InitAsDefaultInstance() {
}

SRequestPvpRooms::SRequestPvpRooms(const SRequestPvpRooms& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SRequestPvpRooms)
}

void SRequestPvpRooms::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SRequestPvpRooms::~SRequestPvpRooms() {
  // @@protoc_insertion_point(destructor:SRequestPvpRooms)
  SharedDtor();
}

void SRequestPvpRooms::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SRequestPvpRooms::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SRequestPvpRooms::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SRequestPvpRooms_descriptor_;
}

const SRequestPvpRooms& SRequestPvpRooms::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SRequestPvpRooms_2eproto();
  return *default_instance_;
}

SRequestPvpRooms* SRequestPvpRooms::default_instance_ = NULL;

SRequestPvpRooms* SRequestPvpRooms::New() const {
  return new SRequestPvpRooms;
}

void SRequestPvpRooms::Clear() {
  rooms_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SRequestPvpRooms::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SRequestPvpRooms)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .SRequestPvpRooms.Item rooms = 1;
      case 1: {
        if (tag == 10) {
         parse_rooms:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_rooms()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_rooms;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SRequestPvpRooms)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SRequestPvpRooms)
  return false;
#undef DO_
}

void SRequestPvpRooms::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SRequestPvpRooms)
  // repeated .SRequestPvpRooms.Item rooms = 1;
  for (int i = 0; i < this->rooms_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->rooms(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SRequestPvpRooms)
}

::google::protobuf::uint8* SRequestPvpRooms::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SRequestPvpRooms)
  // repeated .SRequestPvpRooms.Item rooms = 1;
  for (int i = 0; i < this->rooms_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->rooms(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SRequestPvpRooms)
  return target;
}

int SRequestPvpRooms::ByteSize() const {
  int total_size = 0;

  // repeated .SRequestPvpRooms.Item rooms = 1;
  total_size += 1 * this->rooms_size();
  for (int i = 0; i < this->rooms_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->rooms(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SRequestPvpRooms::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SRequestPvpRooms* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SRequestPvpRooms*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SRequestPvpRooms::MergeFrom(const SRequestPvpRooms& from) {
  GOOGLE_CHECK_NE(&from, this);
  rooms_.MergeFrom(from.rooms_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SRequestPvpRooms::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SRequestPvpRooms::CopyFrom(const SRequestPvpRooms& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SRequestPvpRooms::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->rooms())) return false;
  return true;
}

void SRequestPvpRooms::Swap(SRequestPvpRooms* other) {
  if (other != this) {
    rooms_.Swap(&other->rooms_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SRequestPvpRooms::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SRequestPvpRooms_descriptor_;
  metadata.reflection = SRequestPvpRooms_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)