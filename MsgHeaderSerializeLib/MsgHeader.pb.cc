// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgHeader.proto

#include "MsgHeader.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace Serialize {
class MsgHeaderProtoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MsgHeaderProto> _instance;
} _MsgHeaderProto_default_instance_;
}  // namespace Serialize
static void InitDefaultsscc_info_MsgHeaderProto_MsgHeader_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::Serialize::_MsgHeaderProto_default_instance_;
    new (ptr) ::Serialize::MsgHeaderProto();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Serialize::MsgHeaderProto::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MsgHeaderProto_MsgHeader_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MsgHeaderProto_MsgHeader_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_MsgHeader_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_MsgHeader_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_MsgHeader_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_MsgHeader_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Serialize::MsgHeaderProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Serialize::MsgHeaderProto, m_to_),
  PROTOBUF_FIELD_OFFSET(::Serialize::MsgHeaderProto, m_from_),
  PROTOBUF_FIELD_OFFSET(::Serialize::MsgHeaderProto, m_type_),
  PROTOBUF_FIELD_OFFSET(::Serialize::MsgHeaderProto, m_size_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Serialize::MsgHeaderProto)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Serialize::_MsgHeaderProto_default_instance_),
};

const char descriptor_table_protodef_MsgHeader_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017MsgHeader.proto\022\tSerialize\"N\n\016MsgHeade"
  "rProto\022\014\n\004m_To\030\001 \001(\t\022\016\n\006m_From\030\002 \001(\t\022\016\n\006"
  "m_Type\030\003 \001(\005\022\016\n\006m_Size\030\004 \001(\005b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_MsgHeader_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_MsgHeader_2eproto_sccs[1] = {
  &scc_info_MsgHeaderProto_MsgHeader_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_MsgHeader_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_MsgHeader_2eproto = {
  false, false, descriptor_table_protodef_MsgHeader_2eproto, "MsgHeader.proto", 116,
  &descriptor_table_MsgHeader_2eproto_once, descriptor_table_MsgHeader_2eproto_sccs, descriptor_table_MsgHeader_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_MsgHeader_2eproto::offsets,
  file_level_metadata_MsgHeader_2eproto, 1, file_level_enum_descriptors_MsgHeader_2eproto, file_level_service_descriptors_MsgHeader_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_MsgHeader_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_MsgHeader_2eproto)), true);
namespace Serialize {

// ===================================================================

void MsgHeaderProto::InitAsDefaultInstance() {
}
class MsgHeaderProto::_Internal {
 public:
};

MsgHeaderProto::MsgHeaderProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Serialize.MsgHeaderProto)
}
MsgHeaderProto::MsgHeaderProto(const MsgHeaderProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  m_to_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_m_to().empty()) {
    m_to_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_m_to(),
      GetArena());
  }
  m_from_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_m_from().empty()) {
    m_from_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_m_from(),
      GetArena());
  }
  ::memcpy(&m_type_, &from.m_type_,
    static_cast<size_t>(reinterpret_cast<char*>(&m_size_) -
    reinterpret_cast<char*>(&m_type_)) + sizeof(m_size_));
  // @@protoc_insertion_point(copy_constructor:Serialize.MsgHeaderProto)
}

void MsgHeaderProto::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MsgHeaderProto_MsgHeader_2eproto.base);
  m_to_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  m_from_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&m_type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&m_size_) -
      reinterpret_cast<char*>(&m_type_)) + sizeof(m_size_));
}

MsgHeaderProto::~MsgHeaderProto() {
  // @@protoc_insertion_point(destructor:Serialize.MsgHeaderProto)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void MsgHeaderProto::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  m_to_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  m_from_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MsgHeaderProto::ArenaDtor(void* object) {
  MsgHeaderProto* _this = reinterpret_cast< MsgHeaderProto* >(object);
  (void)_this;
}
void MsgHeaderProto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void MsgHeaderProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MsgHeaderProto& MsgHeaderProto::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MsgHeaderProto_MsgHeader_2eproto.base);
  return *internal_default_instance();
}


void MsgHeaderProto::Clear() {
// @@protoc_insertion_point(message_clear_start:Serialize.MsgHeaderProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  m_to_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  m_from_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&m_type_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&m_size_) -
      reinterpret_cast<char*>(&m_type_)) + sizeof(m_size_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MsgHeaderProto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string m_To = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_m_to();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Serialize.MsgHeaderProto.m_To"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string m_From = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_m_from();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Serialize.MsgHeaderProto.m_From"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 m_Type = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          m_type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 m_Size = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          m_size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* MsgHeaderProto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Serialize.MsgHeaderProto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string m_To = 1;
  if (this->m_to().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_m_to().data(), static_cast<int>(this->_internal_m_to().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Serialize.MsgHeaderProto.m_To");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_m_to(), target);
  }

  // string m_From = 2;
  if (this->m_from().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_m_from().data(), static_cast<int>(this->_internal_m_from().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Serialize.MsgHeaderProto.m_From");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_m_from(), target);
  }

  // int32 m_Type = 3;
  if (this->m_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_m_type(), target);
  }

  // int32 m_Size = 4;
  if (this->m_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_m_size(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Serialize.MsgHeaderProto)
  return target;
}

size_t MsgHeaderProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Serialize.MsgHeaderProto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string m_To = 1;
  if (this->m_to().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_m_to());
  }

  // string m_From = 2;
  if (this->m_from().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_m_from());
  }

  // int32 m_Type = 3;
  if (this->m_type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_m_type());
  }

  // int32 m_Size = 4;
  if (this->m_size() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_m_size());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MsgHeaderProto::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Serialize.MsgHeaderProto)
  GOOGLE_DCHECK_NE(&from, this);
  const MsgHeaderProto* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MsgHeaderProto>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Serialize.MsgHeaderProto)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Serialize.MsgHeaderProto)
    MergeFrom(*source);
  }
}

void MsgHeaderProto::MergeFrom(const MsgHeaderProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Serialize.MsgHeaderProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.m_to().size() > 0) {
    _internal_set_m_to(from._internal_m_to());
  }
  if (from.m_from().size() > 0) {
    _internal_set_m_from(from._internal_m_from());
  }
  if (from.m_type() != 0) {
    _internal_set_m_type(from._internal_m_type());
  }
  if (from.m_size() != 0) {
    _internal_set_m_size(from._internal_m_size());
  }
}

void MsgHeaderProto::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Serialize.MsgHeaderProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgHeaderProto::CopyFrom(const MsgHeaderProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Serialize.MsgHeaderProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgHeaderProto::IsInitialized() const {
  return true;
}

void MsgHeaderProto::InternalSwap(MsgHeaderProto* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  m_to_.Swap(&other->m_to_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  m_from_.Swap(&other->m_from_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MsgHeaderProto, m_size_)
      + sizeof(MsgHeaderProto::m_size_)
      - PROTOBUF_FIELD_OFFSET(MsgHeaderProto, m_type_)>(
          reinterpret_cast<char*>(&m_type_),
          reinterpret_cast<char*>(&other->m_type_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MsgHeaderProto::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Serialize
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Serialize::MsgHeaderProto* Arena::CreateMaybeMessage< ::Serialize::MsgHeaderProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Serialize::MsgHeaderProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>