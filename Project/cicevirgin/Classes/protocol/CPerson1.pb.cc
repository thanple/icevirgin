// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CPerson1.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "CPerson1.pb.h"

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

const ::google::protobuf::Descriptor* CPerson1_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CPerson1_reflection_ = NULL;
const ::google::protobuf::Descriptor* CPerson1_PhoneNumber_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CPerson1_PhoneNumber_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* CPerson1_PhoneType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_CPerson1_2eproto() {
  protobuf_AddDesc_CPerson1_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "CPerson1.proto");
  GOOGLE_CHECK(file != NULL);
  CPerson1_descriptor_ = file->message_type(0);
  static const int CPerson1_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, email_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, phone_),
  };
  CPerson1_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CPerson1_descriptor_,
      CPerson1::default_instance_,
      CPerson1_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CPerson1));
  CPerson1_PhoneNumber_descriptor_ = CPerson1_descriptor_->nested_type(0);
  static const int CPerson1_PhoneNumber_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1_PhoneNumber, number_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1_PhoneNumber, type_),
  };
  CPerson1_PhoneNumber_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CPerson1_PhoneNumber_descriptor_,
      CPerson1_PhoneNumber::default_instance_,
      CPerson1_PhoneNumber_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1_PhoneNumber, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CPerson1_PhoneNumber, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CPerson1_PhoneNumber));
  CPerson1_PhoneType_descriptor_ = CPerson1_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_CPerson1_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CPerson1_descriptor_, &CPerson1::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CPerson1_PhoneNumber_descriptor_, &CPerson1_PhoneNumber::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_CPerson1_2eproto() {
  delete CPerson1::default_instance_;
  delete CPerson1_reflection_;
  delete CPerson1_PhoneNumber::default_instance_;
  delete CPerson1_PhoneNumber_reflection_;
}

void protobuf_AddDesc_CPerson1_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016CPerson1.proto\"\316\001\n\010CPerson1\022\014\n\004name\030\001 "
    "\002(\t\022\n\n\002id\030\002 \002(\005\022\r\n\005email\030\003 \001(\t\022$\n\005phone\030"
    "\004 \003(\0132\025.CPerson1.PhoneNumber\032F\n\013PhoneNum"
    "ber\022\016\n\006number\030\001 \002(\t\022\'\n\004type\030\002 \001(\0162\023.CPer"
    "son1.PhoneType:\004HOME\"+\n\tPhoneType\022\n\n\006MOB"
    "ILE\020\000\022\010\n\004HOME\020\001\022\010\n\004WORK\020\002B/\n\"com.thanple"
    ".gs.common.nio.protocolB\t_CPerson1", 274);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "CPerson1.proto", &protobuf_RegisterTypes);
  CPerson1::default_instance_ = new CPerson1();
  CPerson1_PhoneNumber::default_instance_ = new CPerson1_PhoneNumber();
  CPerson1::default_instance_->InitAsDefaultInstance();
  CPerson1_PhoneNumber::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_CPerson1_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_CPerson1_2eproto {
  StaticDescriptorInitializer_CPerson1_2eproto() {
    protobuf_AddDesc_CPerson1_2eproto();
  }
} static_descriptor_initializer_CPerson1_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* CPerson1_PhoneType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CPerson1_PhoneType_descriptor_;
}
bool CPerson1_PhoneType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const CPerson1_PhoneType CPerson1::MOBILE;
const CPerson1_PhoneType CPerson1::HOME;
const CPerson1_PhoneType CPerson1::WORK;
const CPerson1_PhoneType CPerson1::PhoneType_MIN;
const CPerson1_PhoneType CPerson1::PhoneType_MAX;
const int CPerson1::PhoneType_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int CPerson1_PhoneNumber::kNumberFieldNumber;
const int CPerson1_PhoneNumber::kTypeFieldNumber;
#endif  // !_MSC_VER

CPerson1_PhoneNumber::CPerson1_PhoneNumber()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:CPerson1.PhoneNumber)
}

void CPerson1_PhoneNumber::InitAsDefaultInstance() {
}

CPerson1_PhoneNumber::CPerson1_PhoneNumber(const CPerson1_PhoneNumber& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CPerson1.PhoneNumber)
}

void CPerson1_PhoneNumber::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  number_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CPerson1_PhoneNumber::~CPerson1_PhoneNumber() {
  // @@protoc_insertion_point(destructor:CPerson1.PhoneNumber)
  SharedDtor();
}

void CPerson1_PhoneNumber::SharedDtor() {
  if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete number_;
  }
  if (this != default_instance_) {
  }
}

void CPerson1_PhoneNumber::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CPerson1_PhoneNumber::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CPerson1_PhoneNumber_descriptor_;
}

const CPerson1_PhoneNumber& CPerson1_PhoneNumber::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_CPerson1_2eproto();
  return *default_instance_;
}

CPerson1_PhoneNumber* CPerson1_PhoneNumber::default_instance_ = NULL;

CPerson1_PhoneNumber* CPerson1_PhoneNumber::New() const {
  return new CPerson1_PhoneNumber;
}

void CPerson1_PhoneNumber::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_number()) {
      if (number_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        number_->clear();
      }
    }
    type_ = 1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CPerson1_PhoneNumber::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CPerson1.PhoneNumber)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string number = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_number()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->number().data(), this->number().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "number");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // optional .CPerson1.PhoneType type = 2 [default = HOME];
      case 2: {
        if (tag == 16) {
         parse_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::CPerson1_PhoneType_IsValid(value)) {
            set_type(static_cast< ::CPerson1_PhoneType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
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
  // @@protoc_insertion_point(parse_success:CPerson1.PhoneNumber)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CPerson1.PhoneNumber)
  return false;
#undef DO_
}

void CPerson1_PhoneNumber::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CPerson1.PhoneNumber)
  // required string number = 1;
  if (has_number()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->number().data(), this->number().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "number");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->number(), output);
  }

  // optional .CPerson1.PhoneType type = 2 [default = HOME];
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:CPerson1.PhoneNumber)
}

::google::protobuf::uint8* CPerson1_PhoneNumber::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:CPerson1.PhoneNumber)
  // required string number = 1;
  if (has_number()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->number().data(), this->number().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "number");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->number(), target);
  }

  // optional .CPerson1.PhoneType type = 2 [default = HOME];
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CPerson1.PhoneNumber)
  return target;
}

int CPerson1_PhoneNumber::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string number = 1;
    if (has_number()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->number());
    }

    // optional .CPerson1.PhoneType type = 2 [default = HOME];
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
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

void CPerson1_PhoneNumber::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CPerson1_PhoneNumber* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CPerson1_PhoneNumber*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CPerson1_PhoneNumber::MergeFrom(const CPerson1_PhoneNumber& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_number()) {
      set_number(from.number());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CPerson1_PhoneNumber::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CPerson1_PhoneNumber::CopyFrom(const CPerson1_PhoneNumber& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CPerson1_PhoneNumber::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void CPerson1_PhoneNumber::Swap(CPerson1_PhoneNumber* other) {
  if (other != this) {
    std::swap(number_, other->number_);
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CPerson1_PhoneNumber::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CPerson1_PhoneNumber_descriptor_;
  metadata.reflection = CPerson1_PhoneNumber_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int CPerson1::kNameFieldNumber;
const int CPerson1::kIdFieldNumber;
const int CPerson1::kEmailFieldNumber;
const int CPerson1::kPhoneFieldNumber;
#endif  // !_MSC_VER

CPerson1::CPerson1()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:CPerson1)
}

void CPerson1::InitAsDefaultInstance() {
}

CPerson1::CPerson1(const CPerson1& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CPerson1)
}

void CPerson1::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  id_ = 0;
  email_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CPerson1::~CPerson1() {
  // @@protoc_insertion_point(destructor:CPerson1)
  SharedDtor();
}

void CPerson1::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete email_;
  }
  if (this != default_instance_) {
  }
}

void CPerson1::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CPerson1::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CPerson1_descriptor_;
}

const CPerson1& CPerson1::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_CPerson1_2eproto();
  return *default_instance_;
}

CPerson1* CPerson1::default_instance_ = NULL;

CPerson1* CPerson1::New() const {
  return new CPerson1;
}

void CPerson1::Clear() {
  if (_has_bits_[0 / 32] & 7) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    id_ = 0;
    if (has_email()) {
      if (email_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        email_->clear();
      }
    }
  }
  phone_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CPerson1::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CPerson1)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_id;
        break;
      }

      // required int32 id = 2;
      case 2: {
        if (tag == 16) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_email;
        break;
      }

      // optional string email = 3;
      case 3: {
        if (tag == 26) {
         parse_email:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_email()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->email().data(), this->email().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "email");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_phone;
        break;
      }

      // repeated .CPerson1.PhoneNumber phone = 4;
      case 4: {
        if (tag == 34) {
         parse_phone:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_phone()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_phone;
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
  // @@protoc_insertion_point(parse_success:CPerson1)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CPerson1)
  return false;
#undef DO_
}

void CPerson1::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CPerson1)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // required int32 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->id(), output);
  }

  // optional string email = 3;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->email(), output);
  }

  // repeated .CPerson1.PhoneNumber phone = 4;
  for (int i = 0; i < this->phone_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->phone(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:CPerson1)
}

::google::protobuf::uint8* CPerson1::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:CPerson1)
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // required int32 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->id(), target);
  }

  // optional string email = 3;
  if (has_email()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->email().data(), this->email().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "email");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->email(), target);
  }

  // repeated .CPerson1.PhoneNumber phone = 4;
  for (int i = 0; i < this->phone_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->phone(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CPerson1)
  return target;
}

int CPerson1::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required int32 id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional string email = 3;
    if (has_email()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->email());
    }

  }
  // repeated .CPerson1.PhoneNumber phone = 4;
  total_size += 1 * this->phone_size();
  for (int i = 0; i < this->phone_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->phone(i));
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

void CPerson1::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CPerson1* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CPerson1*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CPerson1::MergeFrom(const CPerson1& from) {
  GOOGLE_CHECK_NE(&from, this);
  phone_.MergeFrom(from.phone_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_email()) {
      set_email(from.email());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CPerson1::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CPerson1::CopyFrom(const CPerson1& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CPerson1::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->phone())) return false;
  return true;
}

void CPerson1::Swap(CPerson1* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(id_, other->id_);
    std::swap(email_, other->email_);
    phone_.Swap(&other->phone_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CPerson1::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CPerson1_descriptor_;
  metadata.reflection = CPerson1_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
