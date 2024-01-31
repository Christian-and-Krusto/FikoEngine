#pragma once

namespace FikoEngine {
    class UUID {
    public:
        UUID();

        UUID(uint64_t uuid);

        UUID(const UUID &other);

        operator uint64_t() { return m_UUID; }

        operator const uint64_t() const { return m_UUID; }

        uint64_t GetID() { return m_UUID;}

        uint64_t GetID() const  { return m_UUID;}

    private:
        uint64_t m_UUID;
    };

    class UUID32 {
    public:
        UUID32();

        UUID32(uint32_t uuid);

        UUID32(const UUID32 &other);

        operator uint32_t() { return m_UUID; }

        operator const uint32_t() const { return m_UUID; }

        uint32_t GetID() { return m_UUID;}

        uint32_t GetID() const { return m_UUID;}
    private:
        uint32_t m_UUID;
    };


}
namespace std {

    template<> struct hash<FikoEngine::UUID> {
        std::size_t operator()(const FikoEngine::UUID &uuid) const {
            return hash<uint64_t>()((uint64_t) uuid.GetID());
        }
    };

    template<> struct hash<FikoEngine::UUID32> {
        std::size_t operator()(const FikoEngine::UUID32 &uuid) const {
            return hash<uint32_t>()((uint32_t) uuid.GetID());
        }
    };
}