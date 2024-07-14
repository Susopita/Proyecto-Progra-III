// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: mensajes.proto
// Protobuf C++ Version: 5.27.1

#include "mensajes.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace mensaje {

inline constexpr initBackend::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : iniciar_{false},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR initBackend::initBackend(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct initBackendDefaultTypeInternal {
  PROTOBUF_CONSTEXPR initBackendDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~initBackendDefaultTypeInternal() {}
  union {
    initBackend _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 initBackendDefaultTypeInternal _initBackend_default_instance_;

inline constexpr Pelicula::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : titulo_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        tag_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        sinopsis_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Pelicula::Pelicula(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct PeliculaDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PeliculaDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PeliculaDefaultTypeInternal() {}
  union {
    Pelicula _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PeliculaDefaultTypeInternal _Pelicula_default_instance_;

inline constexpr Busqueda::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : texto_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Busqueda::Busqueda(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct BusquedaDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BusquedaDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BusquedaDefaultTypeInternal() {}
  union {
    Busqueda _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BusquedaDefaultTypeInternal _Busqueda_default_instance_;

inline constexpr Resultado_Busqueda::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : peliculas_{},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Resultado_Busqueda::Resultado_Busqueda(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct Resultado_BusquedaDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Resultado_BusquedaDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~Resultado_BusquedaDefaultTypeInternal() {}
  union {
    Resultado_Busqueda _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Resultado_BusquedaDefaultTypeInternal _Resultado_Busqueda_default_instance_;
}  // namespace mensaje
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_mensajes_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_mensajes_2eproto = nullptr;
const ::uint32_t
    TableStruct_mensajes_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::mensaje::initBackend, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::mensaje::initBackend, _impl_.iniciar_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::mensaje::Busqueda, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::mensaje::Busqueda, _impl_.texto_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::mensaje::Pelicula, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::mensaje::Pelicula, _impl_.titulo_),
        PROTOBUF_FIELD_OFFSET(::mensaje::Pelicula, _impl_.tag_),
        PROTOBUF_FIELD_OFFSET(::mensaje::Pelicula, _impl_.sinopsis_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::mensaje::Resultado_Busqueda, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::mensaje::Resultado_Busqueda, _impl_.peliculas_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::mensaje::initBackend)},
        {9, -1, -1, sizeof(::mensaje::Busqueda)},
        {18, -1, -1, sizeof(::mensaje::Pelicula)},
        {29, -1, -1, sizeof(::mensaje::Resultado_Busqueda)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::mensaje::_initBackend_default_instance_._instance,
    &::mensaje::_Busqueda_default_instance_._instance,
    &::mensaje::_Pelicula_default_instance_._instance,
    &::mensaje::_Resultado_Busqueda_default_instance_._instance,
};
const char descriptor_table_protodef_mensajes_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\016mensajes.proto\022\007mensaje\"\036\n\013initBackend"
    "\022\017\n\007iniciar\030\001 \001(\010\"\031\n\010Busqueda\022\r\n\005texto\030\001"
    " \001(\t\"9\n\010Pelicula\022\016\n\006titulo\030\001 \001(\t\022\013\n\003tag\030"
    "\002 \001(\t\022\020\n\010sinopsis\030\003 \001(\t\":\n\022Resultado_Bus"
    "queda\022$\n\tpeliculas\030\001 \003(\0132\021.mensaje.Pelic"
    "ulab\006proto3"
};
static ::absl::once_flag descriptor_table_mensajes_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_mensajes_2eproto = {
    false,
    false,
    211,
    descriptor_table_protodef_mensajes_2eproto,
    "mensajes.proto",
    &descriptor_table_mensajes_2eproto_once,
    nullptr,
    0,
    4,
    schemas,
    file_default_instances,
    TableStruct_mensajes_2eproto::offsets,
    file_level_enum_descriptors_mensajes_2eproto,
    file_level_service_descriptors_mensajes_2eproto,
};
namespace mensaje {
// ===================================================================

class initBackend::_Internal {
 public:
};

initBackend::initBackend(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:mensaje.initBackend)
}
initBackend::initBackend(
    ::google::protobuf::Arena* arena, const initBackend& from)
    : initBackend(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE initBackend::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void initBackend::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.iniciar_ = {};
}
initBackend::~initBackend() {
  // @@protoc_insertion_point(destructor:mensaje.initBackend)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void initBackend::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
initBackend::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(initBackend, _impl_._cached_size_),
              false,
          },
          &initBackend::MergeImpl,
          &initBackend::kDescriptorMethods,
          &descriptor_table_mensajes_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> initBackend::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_initBackend_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::mensaje::initBackend>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bool iniciar = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(initBackend, _impl_.iniciar_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(initBackend, _impl_.iniciar_)}},
  }}, {{
    65535, 65535
  }}, {{
    // bool iniciar = 1;
    {PROTOBUF_FIELD_OFFSET(initBackend, _impl_.iniciar_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void initBackend::Clear() {
// @@protoc_insertion_point(message_clear_start:mensaje.initBackend)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.iniciar_ = false;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* initBackend::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mensaje.initBackend)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bool iniciar = 1;
  if (this->_internal_iniciar() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        1, this->_internal_iniciar(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mensaje.initBackend)
  return target;
}

::size_t initBackend::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mensaje.initBackend)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool iniciar = 1;
  if (this->_internal_iniciar() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void initBackend::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<initBackend*>(&to_msg);
  auto& from = static_cast<const initBackend&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mensaje.initBackend)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_iniciar() != 0) {
    _this->_impl_.iniciar_ = from._impl_.iniciar_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void initBackend::CopyFrom(const initBackend& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mensaje.initBackend)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void initBackend::InternalSwap(initBackend* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
        swap(_impl_.iniciar_, other->_impl_.iniciar_);
}

::google::protobuf::Metadata initBackend::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class Busqueda::_Internal {
 public:
};

Busqueda::Busqueda(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:mensaje.Busqueda)
}
inline PROTOBUF_NDEBUG_INLINE Busqueda::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::mensaje::Busqueda& from_msg)
      : texto_(arena, from.texto_),
        _cached_size_{0} {}

Busqueda::Busqueda(
    ::google::protobuf::Arena* arena,
    const Busqueda& from)
    : ::google::protobuf::Message(arena) {
  Busqueda* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:mensaje.Busqueda)
}
inline PROTOBUF_NDEBUG_INLINE Busqueda::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : texto_(arena),
        _cached_size_{0} {}

inline void Busqueda::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Busqueda::~Busqueda() {
  // @@protoc_insertion_point(destructor:mensaje.Busqueda)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Busqueda::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.texto_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Busqueda::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Busqueda, _impl_._cached_size_),
              false,
          },
          &Busqueda::MergeImpl,
          &Busqueda::kDescriptorMethods,
          &descriptor_table_mensajes_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 30, 2> Busqueda::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Busqueda_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::mensaje::Busqueda>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string texto = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Busqueda, _impl_.texto_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string texto = 1;
    {PROTOBUF_FIELD_OFFSET(Busqueda, _impl_.texto_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\20\5\0\0\0\0\0\0"
    "mensaje.Busqueda"
    "texto"
  }},
};

PROTOBUF_NOINLINE void Busqueda::Clear() {
// @@protoc_insertion_point(message_clear_start:mensaje.Busqueda)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.texto_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Busqueda::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mensaje.Busqueda)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string texto = 1;
  if (!this->_internal_texto().empty()) {
    const std::string& _s = this->_internal_texto();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "mensaje.Busqueda.texto");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mensaje.Busqueda)
  return target;
}

::size_t Busqueda::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mensaje.Busqueda)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string texto = 1;
  if (!this->_internal_texto().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_texto());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Busqueda::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Busqueda*>(&to_msg);
  auto& from = static_cast<const Busqueda&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mensaje.Busqueda)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_texto().empty()) {
    _this->_internal_set_texto(from._internal_texto());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Busqueda::CopyFrom(const Busqueda& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mensaje.Busqueda)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Busqueda::InternalSwap(Busqueda* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.texto_, &other->_impl_.texto_, arena);
}

::google::protobuf::Metadata Busqueda::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class Pelicula::_Internal {
 public:
};

Pelicula::Pelicula(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:mensaje.Pelicula)
}
inline PROTOBUF_NDEBUG_INLINE Pelicula::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::mensaje::Pelicula& from_msg)
      : titulo_(arena, from.titulo_),
        tag_(arena, from.tag_),
        sinopsis_(arena, from.sinopsis_),
        _cached_size_{0} {}

Pelicula::Pelicula(
    ::google::protobuf::Arena* arena,
    const Pelicula& from)
    : ::google::protobuf::Message(arena) {
  Pelicula* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:mensaje.Pelicula)
}
inline PROTOBUF_NDEBUG_INLINE Pelicula::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : titulo_(arena),
        tag_(arena),
        sinopsis_(arena),
        _cached_size_{0} {}

inline void Pelicula::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Pelicula::~Pelicula() {
  // @@protoc_insertion_point(destructor:mensaje.Pelicula)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Pelicula::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.titulo_.Destroy();
  _impl_.tag_.Destroy();
  _impl_.sinopsis_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Pelicula::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Pelicula, _impl_._cached_size_),
              false,
          },
          &Pelicula::MergeImpl,
          &Pelicula::kDescriptorMethods,
          &descriptor_table_mensajes_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 0, 42, 2> Pelicula::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Pelicula_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::mensaje::Pelicula>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string titulo = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.titulo_)}},
    // string tag = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.tag_)}},
    // string sinopsis = 3;
    {::_pbi::TcParser::FastUS1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.sinopsis_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string titulo = 1;
    {PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.titulo_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string tag = 2;
    {PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.tag_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string sinopsis = 3;
    {PROTOBUF_FIELD_OFFSET(Pelicula, _impl_.sinopsis_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\20\6\3\10\0\0\0\0"
    "mensaje.Pelicula"
    "titulo"
    "tag"
    "sinopsis"
  }},
};

PROTOBUF_NOINLINE void Pelicula::Clear() {
// @@protoc_insertion_point(message_clear_start:mensaje.Pelicula)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.titulo_.ClearToEmpty();
  _impl_.tag_.ClearToEmpty();
  _impl_.sinopsis_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Pelicula::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mensaje.Pelicula)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string titulo = 1;
  if (!this->_internal_titulo().empty()) {
    const std::string& _s = this->_internal_titulo();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "mensaje.Pelicula.titulo");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // string tag = 2;
  if (!this->_internal_tag().empty()) {
    const std::string& _s = this->_internal_tag();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "mensaje.Pelicula.tag");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // string sinopsis = 3;
  if (!this->_internal_sinopsis().empty()) {
    const std::string& _s = this->_internal_sinopsis();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "mensaje.Pelicula.sinopsis");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mensaje.Pelicula)
  return target;
}

::size_t Pelicula::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mensaje.Pelicula)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // string titulo = 1;
  if (!this->_internal_titulo().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_titulo());
  }

  // string tag = 2;
  if (!this->_internal_tag().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_tag());
  }

  // string sinopsis = 3;
  if (!this->_internal_sinopsis().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_sinopsis());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Pelicula::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Pelicula*>(&to_msg);
  auto& from = static_cast<const Pelicula&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mensaje.Pelicula)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_titulo().empty()) {
    _this->_internal_set_titulo(from._internal_titulo());
  }
  if (!from._internal_tag().empty()) {
    _this->_internal_set_tag(from._internal_tag());
  }
  if (!from._internal_sinopsis().empty()) {
    _this->_internal_set_sinopsis(from._internal_sinopsis());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Pelicula::CopyFrom(const Pelicula& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mensaje.Pelicula)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Pelicula::InternalSwap(Pelicula* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.titulo_, &other->_impl_.titulo_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.tag_, &other->_impl_.tag_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.sinopsis_, &other->_impl_.sinopsis_, arena);
}

::google::protobuf::Metadata Pelicula::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class Resultado_Busqueda::_Internal {
 public:
};

Resultado_Busqueda::Resultado_Busqueda(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:mensaje.Resultado_Busqueda)
}
inline PROTOBUF_NDEBUG_INLINE Resultado_Busqueda::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::mensaje::Resultado_Busqueda& from_msg)
      : peliculas_{visibility, arena, from.peliculas_},
        _cached_size_{0} {}

Resultado_Busqueda::Resultado_Busqueda(
    ::google::protobuf::Arena* arena,
    const Resultado_Busqueda& from)
    : ::google::protobuf::Message(arena) {
  Resultado_Busqueda* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:mensaje.Resultado_Busqueda)
}
inline PROTOBUF_NDEBUG_INLINE Resultado_Busqueda::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : peliculas_{visibility, arena},
        _cached_size_{0} {}

inline void Resultado_Busqueda::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Resultado_Busqueda::~Resultado_Busqueda() {
  // @@protoc_insertion_point(destructor:mensaje.Resultado_Busqueda)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Resultado_Busqueda::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Resultado_Busqueda::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Resultado_Busqueda, _impl_._cached_size_),
              false,
          },
          &Resultado_Busqueda::MergeImpl,
          &Resultado_Busqueda::kDescriptorMethods,
          &descriptor_table_mensajes_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> Resultado_Busqueda::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Resultado_Busqueda_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::mensaje::Resultado_Busqueda>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .mensaje.Pelicula peliculas = 1;
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Resultado_Busqueda, _impl_.peliculas_)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .mensaje.Pelicula peliculas = 1;
    {PROTOBUF_FIELD_OFFSET(Resultado_Busqueda, _impl_.peliculas_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::mensaje::Pelicula>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void Resultado_Busqueda::Clear() {
// @@protoc_insertion_point(message_clear_start:mensaje.Resultado_Busqueda)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.peliculas_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Resultado_Busqueda::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:mensaje.Resultado_Busqueda)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .mensaje.Pelicula peliculas = 1;
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_peliculas_size());
       i < n; i++) {
    const auto& repfield = this->_internal_peliculas().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            1, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:mensaje.Resultado_Busqueda)
  return target;
}

::size_t Resultado_Busqueda::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mensaje.Resultado_Busqueda)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // repeated .mensaje.Pelicula peliculas = 1;
  total_size += 1UL * this->_internal_peliculas_size();
  for (const auto& msg : this->_internal_peliculas()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Resultado_Busqueda::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Resultado_Busqueda*>(&to_msg);
  auto& from = static_cast<const Resultado_Busqueda&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:mensaje.Resultado_Busqueda)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_peliculas()->MergeFrom(
      from._internal_peliculas());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Resultado_Busqueda::CopyFrom(const Resultado_Busqueda& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mensaje.Resultado_Busqueda)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Resultado_Busqueda::InternalSwap(Resultado_Busqueda* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.peliculas_.InternalSwap(&other->_impl_.peliculas_);
}

::google::protobuf::Metadata Resultado_Busqueda::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace mensaje
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_mensajes_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
