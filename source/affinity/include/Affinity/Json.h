// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_JSON_H
#define AFFINITY_JSON_H

#include <sstream>

namespace AffinityReader {

class Class;
struct DocFormat;

void JsonPrint(const Class* c, std::ostream& s, bool with_type, bool with_blob, const DocFormat* f = nullptr);

} // namespace AffinityReader

#endif /* AFFINITY_JSON_H */
