// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SFightBlood.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "SFightBlood.pb.h"

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

const ::google::protobuf::Descriptor* SFightBlood_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SFightBlood_reflection_ = NULL;
const ::google::protobuf::Descriptor* SFightBlood_FighterInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SFightBlood_FighterInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_SFightBlood_2eproto() {
  protobuf_AddDesc_SFightBlood_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "SFightBlood.proto");
  GOOGLE_CHECK(file != NULL);
  SFightBlood_descriptor_ = file->message_type(0);
  static const int SFightBlood_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood, fighthtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood, info_),
  };
  SFightBlood_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SFightBlood_descriptor_,
      SFightBlood::default_instance_,
      SFightBlood_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SFightBlood));
  SFightBlood_FighterInfo_descriptor_ = SFightBlood_descriptor_->nested_type(0);
  static const int SFightBlood_FighterInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood_FighterInfo, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood_FighterInfo, blood_),
  };
  SFightBlood_FighterInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SFightBlood_FighterInfo_descriptor_,
      SFightBlood_FighterInfo::default_instance_,
      SFightBlood_FighterInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood_FighterInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SFightBlood_FighterInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SFightBlood_FighterInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_SFightBlood_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SFightBlood_descriptor_, &SFightBlood::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SFightBlood_FighterInfo_descriptor_, &SFightBlood_FighterInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_SFightBlood_2eproto() {
  delete SFightBlood::default_instance_;
  delete SFightBlood_reflection_;
  delete SFightBlood_FighterInfo::default_instance_;
  delete SFightBlood_FighterInfo_reflection_;
}

void protobuf_AddDesc_SFightBlood_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021SFightBlood.proto\"s\n\013SFightBlood\022\022\n\nfi"
    "ghthType\030\001 \002(\005\022&\n\004info\030\002 \003(\0132\030.SFightBlo"
    "od.FighterInfo\032(\n\013FighterInfo\022\n\n\002id\030\001 \002("
    "\005\022\r\n\005blood\030\002 \002(\005B2\n\"com.thanple.gs.commo"
    "n.nio.protocolB\014_SFightBlood", 188);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "SFightBlood.proto", &protobuf_RegisterTypes);
  SFightBlood::default_instance_ = new SFightBlood();
  SFightBlood_FighterInfo::default_instance_ = new SFightBlood_FighterInfo();
  SFightBlood::default_instance_->InitAsDefaultInstance();
  SFightBlood_FighterInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_SFightBlood_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_SFightBlood_2eproto {
  StaticDescriptorInitializer_SFightBlood_2eproto() {
    protobuf_AddDesc_SFightBlood_2eproto();
  }
} static_descriptor_initializer_SFightBlood_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SFightBlood_FighterInfo::kIdFieldNumber;
const int SFightBlood_FighterInfo::kBloodFieldNumber;
#endif  // !_MSC_VER

SFightBlood_FighterInfo::SFightBlood_FighterInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SFightBlood.FighterInfo)
}

void SFightBlood_FighterInfo::InitAsDefaultInstance() {
}

SFightBlood_FighterInfo::SFightBlood_FighterInfo(const SFightBlood_FighterInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SFightBlood.FighterInfo)
}

void SFightBlood_FighterInfo::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  blood_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SFightBlood_FighterInfo::~SFightBlood_FighterInfo() {
  // @@protoc_insertion_point(destructor:SFightBlood.FighterInfo)
  SharedDtor();
}

void SFightBlood_FighterInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SFightBlood_FighterInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SFightBlood_FighterInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SFightBlood_FighterInfo_descriptor_;
}

const SFightBlood_FighterInfo& SFightBlood_FighterInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SFightBlood_2eproto();
  return *default_instance_;
}

SFightBlood_FighterInfo* SFightBlood_FighterInfo::default_instance_ = NULL;

SFightBlood_FighterInfo* SFightBlood_FighterInfo::New() const {
  return new SFightBlood_FighterInfo;
}

void SFightBlood_FighterInfo::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<SFightBlood_FighterInfo*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(id_, blood_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SFightBlood_FighterInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SFightBlood.FighterInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_blood;
        break;
      }

      // required int32 blood = 2;
      case 2: {
        if (tag == 16) {
         parse_blood:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &blood_)));
          set_has_blood();
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
  // @@protoc_insertion_point(parse_success:SFightBlood.FighterInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SFightBlood.FighterInfo)
  return false;
#undef DO_
}

void SFightBlood_FighterInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SFightBlood.FighterInfo)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required int32 blood = 2;
  if (has_blood()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->blood(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SFightBlood.FighterInfo)
}

::google::protobuf::uint8* SFightBlood_FighterInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SFightBlood.FighterInfo)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required int32 blood = 2;
  if (has_blood()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->blood(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SFightBlood.FighterInfo)
  return target;
}

int SFightBlood_FighterInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required int32 blood = 2;
    if (has_blood()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->blood());
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

void SFightBlood_FighterInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SFightBlood_FighterInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SFightBlood_FighterInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SFightBlood_FighterInfo::MergeFrom(const SFightBlood_FighterInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_blood()) {
      set_blood(from.blood());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SFightBlood_FighterInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SFightBlood_FighterInfo::CopyFrom(const SFightBlood_FighterInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SFightBlood_FighterInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void SFightBlood_FighterInfo::Swap(SFightBlood_FighterInfo* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(blood_, other->blood_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SFightBlood_FighterInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SFightBlood_FighterInfo_descriptor_;
  metadata.reflection = SFightBlood_FighterInfo_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int SFightBlood::kFighthTypeFieldNumber;
const int SFightBlood::kInfoFieldNumber;
#endif  // !_MSC_VER

SFightBlood::SFightBlood()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SFightBlood)
}

void SFightBlood::InitAsDefaultInstance() {
}

SFightBlood::SFightBlood(const SFightBlood& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SFightBlood)
}

void SFightBlood::SharedCtor() {
  _cached_size_ = 0;
  fighthtype_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SFightBlood::~SFightBlood() {
  // @@protoc_insertion_point(destructor:SFightBlood)
  SharedDtor();
}

void SFightBlood::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SFightBlood::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SFightBlood::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SFightBlood_descriptor_;
}

const SFightBlood& SFightBlood::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SFightBlood_2eproto();
  return *default_instance_;
}

SFightBlood* SFightBlood::default_instance_ = NULL;

SFightBlood* SFightBlood::New() const {
  return new SFightBlood;
}

void SFightBlood::Clear() {
  fighthtype_ = 0;
  info_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SFightBlood::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SFightBlood)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 fighthType = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &fighthtype_)));
          set_has_fighthtype();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_info;
        break;
      }

      // repeated .SFightBlood.FighterInfo info = 2;
      case 2: {
        if (tag == 18) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_info;
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
  // @@protoc_insertion_point(parse_success:SFightBlood)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SFightBlood)
  return false;
#undef DO_
}

void SFightBlood::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SFightBlood)
  // required int32 fighthType = 1;
  if (has_fighthtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->fighthtype(), output);
  }

  // repeated .SFightBlood.FighterInfo info = 2;
  for (int i = 0; i < this->info_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->info(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SFightBlood)
}

::google::protobuf::uint8* SFightBlood::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SFightBlood)
  // required int32 fighthType = 1;
  if (has_fighthtype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->fighthtype(), target);
  }

  // repeated .SFightBlood.FighterInfo info = 2;
  for (int i = 0; i < this->info_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->info(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SFightBlood)
  return target;
}

int SFightBlood::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 fighthType = 1;
    if (has_fighthtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->fighthtype());
    }

  }
  // repeated .SFightBlood.FighterInfo info = 2;
  total_size += 1 * this->info_size();
  for (int i = 0; i < this->info_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->info(i));
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

void SFightBlood::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SFightBlood* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SFightBlood*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SFightBlood::MergeFrom(const SFightBlood& from) {
  GOOGLE_CHECK_NE(&from, this);
  info_.MergeFrom(from.info_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_fighthtype()) {
      set_fighthtype(from.fighthtype());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SFightBlood::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SFightBlood::CopyFrom(const SFightBlood& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SFightBlood::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->info())) return false;
  return true;
}

void SFightBlood::Swap(SFightBlood* other) {
  if (other != this) {
    std::swap(fighthtype_, other->fighthtype_);
    info_.Swap(&other->info_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SFightBlood::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SFightBlood_descriptor_;
  metadata.reflection = SFightBlood_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)