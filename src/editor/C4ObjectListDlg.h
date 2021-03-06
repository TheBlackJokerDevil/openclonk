/*
 * OpenClonk, http://www.openclonk.org
 *
 * Copyright (c) 2007-2009, RedWolf Design GmbH, http://www.clonk.de/
 * Copyright (c) 2013-2016, The OpenClonk Team and contributors
 *
 * Distributed under the terms of the ISC license; see accompanying file
 * "COPYING" for details.
 *
 * "Clonk" is a registered trademark of Matthes Bender, used with permission.
 * See accompanying file "TRADEMARK" for details.
 *
 * To redistribute this file separately, substitute the full license texts
 * for the above references.
 */

/* A window listing all objects in the game */

#ifndef INC_C4ObjectListDlg
#define INC_C4ObjectListDlg

#ifdef USE_GTK
#include <gtk/gtk.h>
#endif // USE_GTK

#include "object/C4ObjectList.h"

class C4ObjectListDlg: public C4ObjectListChangeListener
{
public:
	C4ObjectListDlg();
	virtual ~C4ObjectListDlg();
	void Execute();
	void Open();
	void Update(C4ObjectList &rSelection);

	virtual void OnObjectRemove(C4ObjectList * pList, C4ObjectLink * pLnk);
	virtual void OnObjectAdded(C4ObjectList * pList, C4ObjectLink * pLnk);
	virtual void OnObjectRename(C4ObjectList * pList, C4ObjectLink * pLnk);

#ifdef USE_GTK
private:
	GtkWidget * window;
	GtkWidget * treeview;
	GObject * model;
	bool updating_selection;

	static void OnDestroy(GtkWidget * widget, C4ObjectListDlg * dlg);
	static void OnRowActivated(GtkTreeView * tree_view, GtkTreePath * path, GtkTreeViewColumn * column, C4ObjectListDlg * dlg);
	static void OnSelectionChanged(GtkTreeSelection * selection, C4ObjectListDlg * dlg);
#endif // USE_GTK
};

#endif //INC_C4ObjectListDlg
