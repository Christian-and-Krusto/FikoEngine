/**
 * @file
 * @author Krusto Stoyanov ( k.stoianov2@gmail.com )
 * @brief 
 * @version 1.0
 * @date 
 * 
 * @section LICENSE
 * MIT License
 * 
 * Copyright (c) 2024 Christian and Krusto
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @section DESCRIPTION
 * 
 * Memory util classes implementation
 */

/***************************************************************************************************************************
Includes
***************************************************************************************************************************/
#include "Ref.hpp"
#include <unordered_map>

/***************************************************************************************************************************
Macro definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Type definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Static variables
***************************************************************************************************************************/

static std::unordered_map<void*, size_t> s_LiveReferences;
static std::mutex s_LiveReferenceMutex;

/***************************************************************************************************************************
RefUtils namespace global functions implementation
***************************************************************************************************************************/
namespace RefUtils
{

    void AddToLiveReferences( void* instance, size_t size )
    {
        std::scoped_lock<std::mutex> lock( s_LiveReferenceMutex );
        s_LiveReferences.emplace( instance, size );
    }

    void RemoveFromLiveReferences( void* instance )
    {
        std::scoped_lock<std::mutex> lock( s_LiveReferenceMutex );
        s_LiveReferences.erase( instance );
    }

    size_t GetSizeFromLiveReferences( void* instance )
    {
        std::scoped_lock<std::mutex> lock( s_LiveReferenceMutex );
        if ( s_LiveReferences.contains( instance ) ) return s_LiveReferences.at( instance );
        return 0;
    }

    bool IsLive( void* instance ) { return s_LiveReferences.find( instance ) != s_LiveReferences.end(); }
}// namespace RefUtils

/***************************************************************************************************************************
RefCounted base class functions implementation
***************************************************************************************************************************/
void RefCounted::IncRefCount() const { m_RefCount++; }

void RefCounted::DecRefCount() const { m_RefCount--; }

uint32_t RefCounted::GetRefCount() const { return m_RefCount.load(); }

/***************************************************************************************************************************
Ref class constructors implementation
***************************************************************************************************************************/
template <typename T>
Ref<T>::Ref() : m_Instance( nullptr )
{}

template <typename T>
Ref<T>::Ref( std::nullptr_t ) : m_Instance( nullptr )
{}

template <typename T>
Ref<T>::Ref( T* instance ) : m_Instance( instance )
{
    static_assert( std::is_base_of<RefCounted, T>::value, "Class is not RefCounted!" );
    std::lock_guard<std::mutex> lock( m );
    IncRef();
}

template <typename T>
Ref<T>::Ref( const Ref<T>& other ) : m_Instance( other.m_Instance )
{
    IncRef();
}

template <typename T>
template <typename T2>
Ref<T>::Ref( Ref<T2>&& other )
{
    m_Instance = ( T* ) other.m_Instance;
    other.m_Instance = nullptr;
}

template <typename T>
template <typename T2>
Ref<T>::Ref( const Ref<T2>& other )
{
    m_Instance = ( T* ) other.m_Instance;
    IncRef();
}

/***************************************************************************************************************************
Ref class de-constructor implementation
***************************************************************************************************************************/
template <typename T>
Ref<T>::~Ref()
{
    DecRef();
}

/***************************************************************************************************************************
Ref class static functions implementation
***************************************************************************************************************************/
template <typename T>
template <typename... Args, auto size>
Ref<T> Ref<T>::Create( Args&&... args )
{

#ifdef __GNUC__
    LOG_INFO( "Allocated " + std::to_string( size ) + "B Ref<" + std::string( abi::__cxa_demangle( typeid( T ).name(), 0, 0, 0 ) ) + ">" );
#else
#endif
    return Ref<T>( new T( std::forward<Args>( args )... ) );
}

template <typename T>
Ref<T> Ref<T>::CopyWithoutIncrement( const Ref<T>& other )
{
    Ref<T> result = nullptr;
    result->m_Instance = other.m_Instance;
    return result;
}

/***************************************************************************************************************************
Ref class public functions implementation
***************************************************************************************************************************/
template <typename T>
T* Ref<T>::Raw()
{
    return m_Instance;
}

template <typename T>
const T* Ref<T>::Raw() const
{
    return m_Instance;
}

template <typename T>
void Ref<T>::Reset( T* instance )
{
    DecRef();
    m_Instance = instance;
}

template <typename T>
template <typename T2>
Ref<T2> Ref<T>::As() const
{
    return Ref<T2>( *this );
}

template <typename T>
bool Ref<T>::EqualsObject( const Ref<T>& other )
{
    if ( !m_Instance || !other.m_Instance ) return false;

    return *m_Instance == *other.m_Instance;
}

/***************************************************************************************************************************
Ref class operators overload implementation
***************************************************************************************************************************/
template <typename T>
Ref<T>& Ref<T>::operator=( const Ref<T>& other )
{
    other.IncRef();
    DecRef();

    m_Instance = other.m_Instance;
    return *this;
}

template <typename T>
Ref<T>& Ref<T>::operator=( std::nullptr_t )
{
    DecRef();
    m_Instance = nullptr;
    return *this;
}

template <typename T>
template <typename T2>
Ref<T>& Ref<T>::operator=( const Ref<T2>& other )
{
    other.IncRef();
    DecRef();

    m_Instance = other.m_Instance;
    return *this;
}

template <typename T>
template <typename T2>
Ref<T>& Ref<T>::operator=( Ref<T2>&& other )
{
    DecRef();

    m_Instance = other.m_Instance;
    other.m_Instance = nullptr;
    return *this;
}

template <typename T>
bool Ref<T>::operator==( const Ref<T>& other ) const
{
    return m_Instance == other.m_Instance;
}

template <typename T>
bool Ref<T>::operator!=( const Ref<T>& other ) const
{
    return !( *this == other );
}

template <typename T>
Ref<T>::operator bool()
{
    return m_Instance != nullptr;
}

template <typename T>
Ref<T>::operator bool() const
{
    return m_Instance != nullptr;
}

template <typename T>
Ref<T>::operator T*()
{
    return m_Instance;
}

template <typename T>
Ref<T>::operator T*() const
{
    return m_Instance;
}

template <typename T>
T* Ref<T>::operator->()
{
    return m_Instance;
}

template <typename T>
const T* Ref<T>::operator->() const
{
    return m_Instance;
}

template <typename T>
T& Ref<T>::operator*()
{
    return *m_Instance;
}

template <typename T>
const T& Ref<T>::operator*() const
{
    return *m_Instance;
}

/***************************************************************************************************************************
Ref class private functions implementation
***************************************************************************************************************************/
template <typename T>
void Ref<T>::IncRef() const
{
    if ( m_Instance )
    {
        m_Instance->IncRefCount();
        RefUtils::AddToLiveReferences( ( void* ) m_Instance, sizeof( T ) );
    }
}

template <typename T>
void Ref<T>::DecRef() const
{
    if ( m_Instance )
    {
        m_Instance->DecRefCount();
        if ( m_Instance->GetRefCount() == 0 )
        {
            std::lock_guard<std::mutex> lock( m );
            delete m_Instance;

#ifdef __GNUC__
            LOG_INFO( "Deallocated " + std::to_string( RefUtils::GetSizeFromLiveReferences( ( void* ) m_Instance ) ) +
                      "B Ref<" +
                      std::string( abi::__cxa_demangle( typeid( T ).name(), 0, 0, 0 ) ) + ">" );
#else
#endif
            RefUtils::RemoveFromLiveReferences( ( void* ) m_Instance );
            m_Instance = nullptr;
        }
    }
}

/***************************************************************************************************************************
WeakRef class constructors implementation
***************************************************************************************************************************/
template <typename T>
WeakRef<T>::WeakRef( Ref<T> ref )
{
    m_Instance = ref.Raw();
}

template <typename T>
WeakRef<T>::WeakRef( T* instance )
{
    m_Instance = instance;
}

/***************************************************************************************************************************
WeakRef class public functions implementation
***************************************************************************************************************************/
template <typename T>
bool WeakRef<T>::IsValid() const
{
    return m_Instance ? RefUtils::IsLive( m_Instance ) : false;
}

template <typename T>
Ref<T> WeakRef<T>::Lock() const
{
    if ( IsValid() ) { return Ref<T>( m_Instance ); }
    return Ref<T>();
}

/***************************************************************************************************************************
WeakRef class operators overload implementation
***************************************************************************************************************************/
template <typename T>
WeakRef<T>::operator bool() const
{
    return IsValid();
}