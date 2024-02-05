#pragma once
#include <atomic>
#include <mutex>

#ifdef __GNUC__
#include <cxxabi.h>// GCC / Clang only
#endif

#include "Log.hpp"

class RefCounted
{
public:
    void IncRefCount() const;
    void DecRefCount() const;

    uint32_t GetRefCount() const;

private:
    mutable std::atomic<uint32_t> m_RefCount{};
};

namespace RefUtils
{
    void AddToLiveReferences( void* instance, size_t size );
    void RemoveFromLiveReferences( void* instance );
    size_t GetSizeFromLiveReferences( void* instance );
    bool IsLive( void* instance );
}// namespace RefUtils

inline static std::mutex m{};

template <typename T> class Ref
{
public:
    Ref();
    Ref( std::nullptr_t );
    Ref( T* instance );
    Ref( const Ref<T>& other );
    template <typename T2> Ref( const Ref<T2>& other );
    template <typename T2> Ref( Ref<T2>&& other );

    ~Ref();

public:
    template <typename... Args, auto size = sizeof( T )> static Ref<T> Create( Args&&... args );
    static Ref<T> CopyWithoutIncrement( const Ref<T>& other );

public:
    T* Raw();
    const T* Raw() const;

    void Reset( T* instance = nullptr );
    template <typename T2> Ref<T2> As() const;
    bool EqualsObject( const Ref<T>& other );

public:
    Ref& operator=( std::nullptr_t );
    Ref& operator=( const Ref<T>& other );
    template <typename T2> Ref& operator=( Ref<T2>&& other );
    template <typename T2> Ref& operator=( const Ref<T2>& other );

    bool operator==( const Ref<T>& other ) const;
    bool operator!=( const Ref<T>& other ) const;

    operator bool();
    operator bool() const;

    operator T*();
    operator T*() const;

    T* operator->();
    const T* operator->() const;

    T& operator*();
    const T& operator*() const;

private:
    void IncRef() const;
    void DecRef() const;

    template <class T2> friend class Ref;
    mutable T* m_Instance;
};

template <typename T> class WeakRef
{
public:
    WeakRef() = default;
    WeakRef( Ref<T> ref );
    WeakRef( T* instance );

public:
    bool IsValid() const;
    Ref<T> Lock() const;

public:
    operator bool() const;

private:
    T* m_Instance{};
};
