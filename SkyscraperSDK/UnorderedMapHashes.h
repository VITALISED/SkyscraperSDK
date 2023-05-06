#pragma once

namespace UnorderedMapHashes
{
	template <class Type>
	struct Hash {
		typedef std::string value_type;
	};
}

struct TkIDUnorderedMap
{
	struct Hash128 {};
	struct Hash256 {};
};
