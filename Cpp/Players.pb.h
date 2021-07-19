// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Players.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Players_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Players_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Players_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Players_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Players_2eproto;
namespace test {
class Player;
struct PlayerDefaultTypeInternal;
extern PlayerDefaultTypeInternal _Player_default_instance_;
class Players;
struct PlayersDefaultTypeInternal;
extern PlayersDefaultTypeInternal _Players_default_instance_;
}  // namespace test
PROTOBUF_NAMESPACE_OPEN
template<> ::test::Player* Arena::CreateMaybeMessage<::test::Player>(Arena*);
template<> ::test::Players* Arena::CreateMaybeMessage<::test::Players>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace test {

// ===================================================================

class Player final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test.Player) */ {
 public:
  inline Player() : Player(nullptr) {}
  ~Player() override;
  explicit constexpr Player(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Player(const Player& from);
  Player(Player&& from) noexcept
    : Player() {
    *this = ::std::move(from);
  }

  inline Player& operator=(const Player& from) {
    CopyFrom(from);
    return *this;
  }
  inline Player& operator=(Player&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Player& default_instance() {
    return *internal_default_instance();
  }
  static inline const Player* internal_default_instance() {
    return reinterpret_cast<const Player*>(
               &_Player_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Player& a, Player& b) {
    a.Swap(&b);
  }
  inline void Swap(Player* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Player* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Player* New() const final {
    return new Player();
  }

  Player* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Player>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Player& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Player& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Player* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test.Player";
  }
  protected:
  explicit Player(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPlayerNameFieldNumber = 2,
    kPlayerPositionFieldNumber = 4,
    kPlayerIdFieldNumber = 1,
    kPlayerNumberFieldNumber = 3,
  };
  // string PlayerName = 2;
  void clear_playername();
  const std::string& playername() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_playername(ArgT0&& arg0, ArgT... args);
  std::string* mutable_playername();
  PROTOBUF_MUST_USE_RESULT std::string* release_playername();
  void set_allocated_playername(std::string* playername);
  private:
  const std::string& _internal_playername() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_playername(const std::string& value);
  std::string* _internal_mutable_playername();
  public:

  // string PlayerPosition = 4;
  void clear_playerposition();
  const std::string& playerposition() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_playerposition(ArgT0&& arg0, ArgT... args);
  std::string* mutable_playerposition();
  PROTOBUF_MUST_USE_RESULT std::string* release_playerposition();
  void set_allocated_playerposition(std::string* playerposition);
  private:
  const std::string& _internal_playerposition() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_playerposition(const std::string& value);
  std::string* _internal_mutable_playerposition();
  public:

  // int32 PlayerId = 1;
  void clear_playerid();
  ::PROTOBUF_NAMESPACE_ID::int32 playerid() const;
  void set_playerid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_playerid() const;
  void _internal_set_playerid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 PlayerNumber = 3;
  void clear_playernumber();
  ::PROTOBUF_NAMESPACE_ID::int32 playernumber() const;
  void set_playernumber(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_playernumber() const;
  void _internal_set_playernumber(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:test.Player)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr playername_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr playerposition_;
  ::PROTOBUF_NAMESPACE_ID::int32 playerid_;
  ::PROTOBUF_NAMESPACE_ID::int32 playernumber_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Players_2eproto;
};
// -------------------------------------------------------------------

class Players final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:test.Players) */ {
 public:
  inline Players() : Players(nullptr) {}
  ~Players() override;
  explicit constexpr Players(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Players(const Players& from);
  Players(Players&& from) noexcept
    : Players() {
    *this = ::std::move(from);
  }

  inline Players& operator=(const Players& from) {
    CopyFrom(from);
    return *this;
  }
  inline Players& operator=(Players&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Players& default_instance() {
    return *internal_default_instance();
  }
  static inline const Players* internal_default_instance() {
    return reinterpret_cast<const Players*>(
               &_Players_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Players& a, Players& b) {
    a.Swap(&b);
  }
  inline void Swap(Players* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Players* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Players* New() const final {
    return new Players();
  }

  Players* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Players>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Players& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Players& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Players* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "test.Players";
  }
  protected:
  explicit Players(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPlayerListFieldNumber = 1,
  };
  // repeated .test.Player PlayerList = 1;
  int playerlist_size() const;
  private:
  int _internal_playerlist_size() const;
  public:
  void clear_playerlist();
  ::test::Player* mutable_playerlist(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::test::Player >*
      mutable_playerlist();
  private:
  const ::test::Player& _internal_playerlist(int index) const;
  ::test::Player* _internal_add_playerlist();
  public:
  const ::test::Player& playerlist(int index) const;
  ::test::Player* add_playerlist();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::test::Player >&
      playerlist() const;

  // @@protoc_insertion_point(class_scope:test.Players)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::test::Player > playerlist_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Players_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Player

// int32 PlayerId = 1;
inline void Player::clear_playerid() {
  playerid_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Player::_internal_playerid() const {
  return playerid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Player::playerid() const {
  // @@protoc_insertion_point(field_get:test.Player.PlayerId)
  return _internal_playerid();
}
inline void Player::_internal_set_playerid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  playerid_ = value;
}
inline void Player::set_playerid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_playerid(value);
  // @@protoc_insertion_point(field_set:test.Player.PlayerId)
}

// string PlayerName = 2;
inline void Player::clear_playername() {
  playername_.ClearToEmpty();
}
inline const std::string& Player::playername() const {
  // @@protoc_insertion_point(field_get:test.Player.PlayerName)
  return _internal_playername();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Player::set_playername(ArgT0&& arg0, ArgT... args) {
 
 playername_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:test.Player.PlayerName)
}
inline std::string* Player::mutable_playername() {
  std::string* _s = _internal_mutable_playername();
  // @@protoc_insertion_point(field_mutable:test.Player.PlayerName)
  return _s;
}
inline const std::string& Player::_internal_playername() const {
  return playername_.Get();
}
inline void Player::_internal_set_playername(const std::string& value) {
  
  playername_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Player::_internal_mutable_playername() {
  
  return playername_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Player::release_playername() {
  // @@protoc_insertion_point(field_release:test.Player.PlayerName)
  return playername_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Player::set_allocated_playername(std::string* playername) {
  if (playername != nullptr) {
    
  } else {
    
  }
  playername_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), playername,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:test.Player.PlayerName)
}

// int32 PlayerNumber = 3;
inline void Player::clear_playernumber() {
  playernumber_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Player::_internal_playernumber() const {
  return playernumber_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Player::playernumber() const {
  // @@protoc_insertion_point(field_get:test.Player.PlayerNumber)
  return _internal_playernumber();
}
inline void Player::_internal_set_playernumber(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  playernumber_ = value;
}
inline void Player::set_playernumber(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_playernumber(value);
  // @@protoc_insertion_point(field_set:test.Player.PlayerNumber)
}

// string PlayerPosition = 4;
inline void Player::clear_playerposition() {
  playerposition_.ClearToEmpty();
}
inline const std::string& Player::playerposition() const {
  // @@protoc_insertion_point(field_get:test.Player.PlayerPosition)
  return _internal_playerposition();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Player::set_playerposition(ArgT0&& arg0, ArgT... args) {
 
 playerposition_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:test.Player.PlayerPosition)
}
inline std::string* Player::mutable_playerposition() {
  std::string* _s = _internal_mutable_playerposition();
  // @@protoc_insertion_point(field_mutable:test.Player.PlayerPosition)
  return _s;
}
inline const std::string& Player::_internal_playerposition() const {
  return playerposition_.Get();
}
inline void Player::_internal_set_playerposition(const std::string& value) {
  
  playerposition_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Player::_internal_mutable_playerposition() {
  
  return playerposition_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Player::release_playerposition() {
  // @@protoc_insertion_point(field_release:test.Player.PlayerPosition)
  return playerposition_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Player::set_allocated_playerposition(std::string* playerposition) {
  if (playerposition != nullptr) {
    
  } else {
    
  }
  playerposition_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), playerposition,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:test.Player.PlayerPosition)
}

// -------------------------------------------------------------------

// Players

// repeated .test.Player PlayerList = 1;
inline int Players::_internal_playerlist_size() const {
  return playerlist_.size();
}
inline int Players::playerlist_size() const {
  return _internal_playerlist_size();
}
inline void Players::clear_playerlist() {
  playerlist_.Clear();
}
inline ::test::Player* Players::mutable_playerlist(int index) {
  // @@protoc_insertion_point(field_mutable:test.Players.PlayerList)
  return playerlist_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::test::Player >*
Players::mutable_playerlist() {
  // @@protoc_insertion_point(field_mutable_list:test.Players.PlayerList)
  return &playerlist_;
}
inline const ::test::Player& Players::_internal_playerlist(int index) const {
  return playerlist_.Get(index);
}
inline const ::test::Player& Players::playerlist(int index) const {
  // @@protoc_insertion_point(field_get:test.Players.PlayerList)
  return _internal_playerlist(index);
}
inline ::test::Player* Players::_internal_add_playerlist() {
  return playerlist_.Add();
}
inline ::test::Player* Players::add_playerlist() {
  ::test::Player* _add = _internal_add_playerlist();
  // @@protoc_insertion_point(field_add:test.Players.PlayerList)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::test::Player >&
Players::playerlist() const {
  // @@protoc_insertion_point(field_list:test.Players.PlayerList)
  return playerlist_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Players_2eproto