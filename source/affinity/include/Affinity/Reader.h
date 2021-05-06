// Copyright (c) 2020-2021 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_READER_H
#define AFFINITY_READER_H

#include "Affinity/Utils.h"

namespace AffinityReader {

class ReaderPrivate;
class Class;
struct DocFormat;

class Reader
{
public:
	Reader();
	virtual ~Reader();

	bool Load(const ByteBuffer& buf);

	[[nodiscard]] bool DbgDump() const;

	[[nodiscard]] const std::string& GetErrorMessage() const;

	[[nodiscard]] const Class*     GetDoc() const;
	[[nodiscard]] const DocFormat* GetDocFormat() const;

	AF_NO_COPY(Reader);

private:
	ReaderPrivate* m_pimpl;
};

} // namespace AffinityReader

#endif /* AFFINITY_READER_H */
