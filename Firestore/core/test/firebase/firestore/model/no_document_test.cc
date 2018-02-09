/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Firestore/core/src/firebase/firestore/model/no_document.h"

#include "absl/strings/string_view.h"
#include "gtest/gtest.h"

namespace firebase {
namespace firestore {
namespace model {

namespace {

inline NoDocument MakeDocument(const absl::string_view data,
                               const absl::string_view path) {
  return NoDocument(
      FieldValue::ObjectValue({{"field", FieldValue::StringValue(data)}}),
      DocumentKey::FromPathString(path));
}

}  // anonymous namespace

TEST(Document, Getter) {
  const Document& doc = MakeDocument("foo", "i/am/a/path");
  EXPECT_EQ(MaybeDocument::Type::NoDocument, doc.type());
  EXPECT_EQ(
      FieldValue::ObjectValue({{"field", FieldValue::StringValue("foo")}}),
      doc.data());
  EXPECT_EQ(DocumentKey::FromPathString("i/am/a/path"), doc.key());
}

}  // namespace model
}  // namespace firestore
}  // namespace firebase