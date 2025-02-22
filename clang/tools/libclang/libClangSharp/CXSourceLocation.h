// Copyright (c) .NET Foundation and Contributors. All Rights Reserved. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from https://github.com/llvm/llvm-project/tree/llvmorg-14.0.0/clang/tools/libclang
// Original source is Copyright (c) the LLVM Project and Contributors. Licensed under the Apache License v2.0 with LLVM Exceptions. See NOTICE.txt in the project root for license information.

#ifndef LIBCLANGSHARP_CXSOURCELOCATION_H
#define LIBCLANGSHARP_CXSOURCELOCATION_H

#pragma warning(push)
#pragma warning(disable : 4146 4244 4267 4291 4624 4996)

#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include "clang-c/Index.h"

#pragma warning(pop)

void createNullLocation(CXFile* file, unsigned* line, unsigned* column, unsigned* offset);

clang::SourceRange getCursorSourceRange(CXCursor C);

bool isASTUnitSourceLocation(const CXSourceLocation& L);

namespace clang {
namespace cxloc {
    CXSourceLocation translateSourceLocation(ASTContext& Context, SourceLocation Loc);
    CXSourceLocation translateSourceLocation(const SourceManager& SM, const LangOptions& LangOpts, SourceLocation Loc);

    CXSourceRange translateSourceRange(ASTContext& Context, SourceRange R);
    CXSourceRange translateSourceRange(const SourceManager& SM, const LangOptions& LangOpts, SourceRange R);
}
}

#endif
