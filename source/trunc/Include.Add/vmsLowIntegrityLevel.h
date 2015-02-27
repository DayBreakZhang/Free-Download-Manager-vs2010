/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <Sddl.h>

class vmsLowLabelSecurityAttributes : public SECURITY_ATTRIBUTES
{
public:
	vmsLowLabelSecurityAttributes ()
	{
		const LPCWSTR LOW_INTEGRITY_SDDL_SACL_W = L"S:(ML;;NW;;;LW)";
		ZeroMemory (this, sizeof (SECURITY_ATTRIBUTES));
		nLength = sizeof (SECURITY_ATTRIBUTES);
		ConvertStringSecurityDescriptorToSecurityDescriptorW (
			LOW_INTEGRITY_SDDL_SACL_W, SDDL_REVISION_1, &lpSecurityDescriptor, NULL);
	}

	virtual ~vmsLowLabelSecurityAttributes ()
	{
		if (lpSecurityDescriptor)
			LocalFree (lpSecurityDescriptor);
	}
};