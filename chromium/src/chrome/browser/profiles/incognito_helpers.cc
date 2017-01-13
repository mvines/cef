// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/profiles/incognito_helpers.h"

#include "chrome/browser/profiles/profile.h"

namespace chrome {

namespace {
BrowserContextIncognitoHelper* g_helper = nullptr;
}  // namespace

void SetBrowserContextIncognitoHelper(BrowserContextIncognitoHelper* helper) {
  g_helper = helper;
}

content::BrowserContext* GetBrowserContextRedirectedInIncognito(
    content::BrowserContext* context) {
  if (g_helper) {
    content::BrowserContext* new_context =
        g_helper->GetBrowserContextRedirectedInIncognito(context);
    if (new_context)
      return new_context;
  }

  return static_cast<Profile*>(context)->GetOriginalProfile();
}

content::BrowserContext* GetBrowserContextOwnInstanceInIncognito(
    content::BrowserContext* context) {
  if (g_helper) {
    content::BrowserContext* new_context =
        g_helper->GetBrowserContextOwnInstanceInIncognito(context);
    if (new_context)
      return new_context;
  }

  return context;
}

}  // namespace chrome
