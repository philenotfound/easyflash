/*
 *
 * (c) 2011 Thomas Giesel
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Thomas Giesel skoe@directbox.com
 */

#ifdef __WXMAC__
#include <ApplicationServices/ApplicationServices.h>
#endif // __WXMAC__

#include <wx/menu.h>
#include <wx/icon.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/msgdlg.h>
#include <wx/cmdline.h>

#include "easytransfer.xpm"
#include "EasyTransferApp.h"

IMPLEMENT_APP(EasyTransferApp);

/*****************************************************************************/
EasyTransferApp::EasyTransferApp()
{
#ifdef __WXMAC__
    ProcessSerialNumber psn;
    GetCurrentProcess(&psn);
    TransformProcessType(&psn, kProcessTransformToForegroundApplication);
#endif // __WXMAC__
}

/*****************************************************************************/
EasyTransferApp::~EasyTransferApp()
{
}

/*****************************************************************************/
bool EasyTransferApp::OnInit()
{
    size_t i;
    wxIcon icon(easytransfer_xpm);

    m_pMainFrame = new EasyTransferMainFrame(NULL, _T("EasyTransfer " VERSION));
    m_pMainFrame->SetIcon(icon);
    m_pMainFrame->Show();
    SetTopWindow(m_pMainFrame);

    return true;
}
